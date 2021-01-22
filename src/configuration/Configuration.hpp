#ifndef SANA_CONFIGURATION_HPP
#define SANA_CONFIGURATION_HPP

#include <functional>
#include <map>
#include <string>
#include <optional>

#include "configuration/ConfigurationOption.hpp"
namespace sana {
    namespace {
        template<typename T> struct identity { typedef T type; };
    }
    class Configuration {
    public:
        explicit Configuration(std::map<std::string, std::string> configMap);

        template <typename T>
        std::optional<T> getValue(sana::ConfigKey<T> config) const {
            auto value = configMap.find(std::get<std::string>(config));
            if (value != configMap.cend()) {
                return std::get<sana::Converter<T>>(config)(value->second);
            } else {
                return std::nullopt;
            }
        }

        template <typename T>
        T getValue(sana::ConfigKey<T> config, typename identity<T>::type defaultValue) const {
            auto optionalValue = getValue(config);
            return optionalValue.has_value() ? optionalValue.value() : defaultValue;
        }
        std::string toString() const;
    private:
        std::map<std::string, std::string> configMap;
    };
}
#endif //SANA_CONFIGURATION_HPP
