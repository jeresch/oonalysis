#ifndef STRUTILS_H
#define STRUTILS_H

#include <string>
#include <vector>


namespace oonalysis {
namespace core {

std::string str_join(std::vector<std::string> strings, char glue);
std::vector<std::string> str_split(const std::string& str, char delim);
char first_nonwhitespace(const std::string& line);
std::string to_lower(const std::string& str);

} // namespace core
} // namespace oonalysis

#endif // STRUTILS_H
