#include "files.h"
#include "cppinclusions.h"

uint32_t num_cppinclusions(SQLite::Database& db)
{
    SQLite::Statement query(db, "SELECT COUNT(*) FROM cppinclusions;");
    query.executeStep();
    return query.getColumn(0).getInt();
}

float avg_num_cppinclusions(SQLite::Database& db)
{
    return num_cppinclusions(db) / num_files(db);
}
