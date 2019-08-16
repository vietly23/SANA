#ifndef SANA_CONFIGURATION
#define SANA_CONFIGURATION
#include <vector>
#include <string>

#include <sana/Graph.hpp>

namespace sana::config {
    struct SANAConfiguration {
        std::vector<Graph> graphList;
    };
}
#endif

