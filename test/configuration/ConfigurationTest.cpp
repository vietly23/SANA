#include <map>
#include "gtest/gtest.h"

#include "configuration/Configuration.hpp"
#include "configuration/ConfigurationOption.hpp"


TEST(ConfigurationSuite, GetValueWorks) {
    std::map<std::string, std::string> map;
    map["logging.enabled"] = "true";
    sana::Configuration config{map};
    ASSERT_EQ(config.getValue(sana::StringConfig("logging.enabled")), "true");
    ASSERT_EQ(config.getValue(sana::StringConfig("another.value"), "not-present"), "not-present");
}