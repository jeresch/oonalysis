#ifndef METRICS_LOC_H
#define METRICS_LOC_H

#include <fstream>
#include <string>

namespace oonalysis::metrics {

// Retrieve
void main_loc();
int max_loc(std::string& filename);
int avg_loc();

} // namespace oonalysis::metrics

#endif // METRICS_LOC_H
