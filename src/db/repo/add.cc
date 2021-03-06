#include <SQLiteCpp.h>
#include "types.h"
#include "repo.h"
#include "db.h"
extern "C" {
#include "util/log.h"
}

namespace oonalysis::db::repo {

bool add_dbfile(db_file f) {
    LOG(DEBUG, "Adding db_file");

    SQLite::Database db(DB_NAME, SQLite::OPEN_READWRITE);

    // File not already added
    std::string stmt = "INSERT INTO file VALUES ('" + f.filename + "');";

    db.exec(
            "INSERT INTO file (filename, loc) VALUES ('"
          + f.filename
          + "', "
          + std::to_string(f.loc)
          + ");"
            );

    return true;
}

bool add_dbcppinclusion(db_cppinclusion incl) {
    LOG(DEBUG, "Adding db_cppinclusion");

    SQLite::Database db(DB_NAME, SQLite::OPEN_READWRITE);
    // See if file already added
    if (incl.id != 0) {
        SQLite::Statement query(db, "SELECT id FROM cppinclusion WHERE id = ?");
        query.bind(1, incl.id);
        query.executeStep();
        if (!query.isDone()) { return false; }
    }

    db.exec(
            "INSERT INTO cppinclusion (includer, includee) VALUES ('"
          + incl.includer
          + "', '"
          + incl.includee
          + "');");

    return true;
}

bool add_dbfunctiondecl(db_function_decl decl) {
    LOG(DEBUG, "Adding db_function_decl");

    SQLite::Database db(DB_NAME, SQLite::OPEN_READWRITE);
    // See if file already added
    if (decl.id != 0) {
        SQLite::Statement query(db, "SELECT id FROM cppinclusion WHERE id = ?");
        query.bind(1, decl.id);
        query.executeStep();
        if (!query.isDone()) { return false; }
    }

    db.exec(
            "INSERT INTO function_decl (name, file) VALUES ('"
          + decl.name
          + "', '"
          + decl.file
          + "');");

    return true;
}

} // namespace oonalysis::db::repo
