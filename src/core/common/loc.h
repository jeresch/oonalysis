#ifndef CORE_METRICS_LOC_H
#define CORE_METRICS_LOC_H

#include <string>
#include <cstdint>
#include <fstream>

namespace oonalysis::core::common {

uint32_t loc_in_stream(std::istream& file);
uint32_t loc_in_file(const std::string& file);

} // namespace oonalysis::core::common

#endif // CORE_METRICS_LOC_H
