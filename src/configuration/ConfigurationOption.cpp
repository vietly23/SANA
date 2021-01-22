#include "ConfigurationOption.hpp"


sana::ConfigKey<unsigned int> sana::UnsignedIntConfig(std::string key) {
    return ConfigKey<unsigned int>{key, [](std::string value) {return std::stoul(value);}} ;
}

sana::ConfigKey<std::string> sana::StringConfig(std::string key) {
    return sana::ConfigKey<std::string>(key, [](std::string value) {return value;});
}

sana::ConfigKey<bool> sana::BooleanConfig(std::string key) {
    return ConfigKey<bool>{key, [](std::string value) {return value == "true";}};
}

sana::ConfigKey<long long> sana::LongLongConfig(std::string key) {
    return sana::ConfigKey<long long>(key, [](std::string value){return std::stoll(value);});
}
