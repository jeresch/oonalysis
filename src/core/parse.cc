#include <stdlib.h>
#include "parse.h"
#include "filetype.h"
#include "metrics/loc.h"
#include "clang/clang.h"
#include "db/file.h"
#include "common/loc.h"
extern "C" {
#include "util/log.h"
}


namespace oonalysis::core {

void common_parse(const std::vector<std::string>& files) {
    for (auto file : files) {
        int loc = common::loc_in_file(file);
        db::add_new_file(file, &loc);
    }
}

void parse_files(const std::vector<std::string>& files) {
    LOG(INFO, "Parsing files");

    common_parse(files);

    lang_t project_lang = lang_from_filenames(files);
    switch (project_lang) {
    case C:
    case CPP:
        clang::main_clang(files);
        break;
    case HS:
    case PY:
    case UNKNOWN:
    case OTHER:
    case NONE:
    default:
        LOG(ERROR, "Unsupported project type");
        exit(1);
    }

    LOG(INFO, "Done parsing");
}

} // namespace oonalysis::core
