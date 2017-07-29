#ifndef DBTYPES_H
#define DBTYPES_H

#include "db.h"

typedef struct db_file
{
    int id;
    std::string filename;
} db_file;

typedef struct db_cppinclusion
{
    int id;
    std::string includer;
    std::string includee;
} db_cppinclusion;

#endif // DBTYPES_H