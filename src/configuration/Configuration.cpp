#include "Configuration.hpp"

#include <algorithm>
#include <iomanip>
#include <sstream>
#include "spdlog/spdlog.h"

sana::Configuration::Configuration(std::map<std::string, std::string> configMap):configMap(configMap) {
}

std::string sana::Configuration::toString() const {
    std::stringstream stream;
    std::for_each(configMap.cbegin(), --configMap.cend(),
            [&stream](auto p) {
                stream << p.first << "=" << std::quoted(p.second) << ",";
            }
    );
    auto lastValue = --configMap.cend();
    stream << lastValue->first << "=" << std::quoted(lastValue->second);
    return stream.str();
}
