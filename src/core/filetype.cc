#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include "oonalysis.h"
#include "util/strutils.h"
extern "C" {
#include "util/log.h"
}

namespace oonalysis::core {

void log_filetype(lang_t l) {
    switch(l) {
    case C:
        LOG(DEBUG, "C language");
        break;
    case CPP:
        LOG(DEBUG, "CPP language");
        break;
    case PY:
    case HS:
    case NONE:
    case UNKNOWN:
    case OTHER:
    default:
        LOG(WARNING, "Unsupported language");
        break;
    }
}

std::string file_from_path(const std::string& path) {
    std::vector<std::string> toks = str_split(path, '/');
    return toks.back();
}

std::string file_ext(const std::string& filename) {
    std::vector<std::string> toks = str_split(file_from_path(filename), '.');
    return toks.back();
}

lang_t lang_from_filename(const std::string& filename) {
    std::string ext = to_lower(file_ext(filename));

    // Obvious
    if (ext == "c")    { return C; }
    if (
        ext == "cc" ||
        ext == "cpp" ||
        ext == "hpp" ||
        ext == "hh" ||
        ext == "h"
        )  { return CPP; }
    if (ext == "hs")   { return HS; }
    if (ext == "java") { return OTHER; }
    if (ext == "py")   { return PY; }

    // Not Obvious
    if (ext == "makefile"
     || ext == "cmake"
     || ext == "make"
     || ext == "includecache"
     || ext == "internal"
     || ext == "marks"
     || ext == "so"
     || ext == "a"
     || ext == "h"
     || ext == "hpp"
     || ext == "hh"
     || ext == "dylib"
     || ext == "dll"
     || ext == "o"
     || ext == "gitignore") { return NONE; }

    // Non-Code
    if (ext == "doc"
     || ext == "docx"
     || ext == "txt"
     || ext == "md"
     || ext == "markdown"
     || ext == "yml"
     || ext == "xml"
     || ext == "swp"
     || ext == "yaml") { return NONE; }

    return UNKNOWN;
}

lang_t lang_from_filenames(const std::vector<std::string>& filenames) {
    std::map<lang_t, int> score;
    score[C]   = 0;
    score[CPP] = 0;
    score[HS]  = 0;
    score[PY]  = 0;

    for (std::string filename : filenames) {
        lang_t lang = lang_from_filename(filename);
        if (lang == NONE || lang == OTHER) { continue; }

        if (lang == UNKNOWN) {
            LOG(WARNING, "Unknown filetype: %s", filename.c_str());
            continue;
        }
        score[lang_from_filename(filename)]++;
    }

    lang_t res = NONE;
    int max_count = 0;
    for (auto it = score.begin(); it != score.end(); ++it) {
        if (it->second > max_count) {
            max_count = it->second;
            res = it->first;
        }
    }

    log_filetype(res);
    return res;
}

} // namespace oonalysis::core
