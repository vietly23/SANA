#ifndef SANA_CONFIGURATIONOPTION_HPP
#define SANA_CONFIGURATIONOPTION_HPP

#include <functional>
#include <string>

namespace sana {
    template <typename T>
    using Converter = std::function<T (std::string)>;
    template <typename T>
    using ConfigKey = std::pair<std::string, Converter<T>>;

    ConfigKey<bool> BooleanConfig(std::string key);
    ConfigKey<unsigned int> UnsignedIntConfig(std::string key);
    ConfigKey<long long> LongLongConfig(std::string key);
    ConfigKey<std::string> StringConfig(std::string key);
}


#endif //SANA_CONFIGURATIONOPTION_HPP
