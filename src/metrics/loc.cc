#include <iostream>
#include <tuple>
#include <fstream>
#include "loc.h"
#include "db/file.h"

namespace oonalysis::metrics {

std::tuple<int, std::string> max_loc() {
    return db::max_loc();
}

int avg_loc() {
    return db::avg_loc();
}

void main_loc() {
    std::cout << "Printing Lines of Code Stats:" << std::endl;

    auto max_res = max_loc();
    std::cout << "Max LOC is " << std::get<0>(max_res) << " in file " << std::get<1>(max_res) << std::endl;

    std::cout << "Avg LOC is " << avg_loc() << std::endl;
}

} // namespace oonalysis::metrics
