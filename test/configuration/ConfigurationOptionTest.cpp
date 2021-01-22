#include <map>
#include "gtest/gtest.h"

#include "configuration/Configuration.hpp"
#include "configuration/ConfigurationOption.hpp"


TEST(ConfigurationSuite, GetValueBoolean) {
    std::map<std::string, std::string> map;
    map["logging.enabled"] = "true";
    sana::Configuration config{map};

    std::optional<bool> possibleValue = config.getValue(sana::BooleanConfig("logging.enabled"));
    ASSERT_TRUE(possibleValue.has_value());
    ASSERT_TRUE(possibleValue.value());

    bool randomKeyDefault = config.getValue(sana::BooleanConfig("random.key"), false);
    ASSERT_FALSE(randomKeyDefault);

    auto randomKeyNoDefault = config.getValue(sana::BooleanConfig("random.key"));
    ASSERT_FALSE(randomKeyNoDefault.has_value());
}

TEST(ConfigurationSuite, GetValueUnsignedInt) {
    std::map<std::string, std::string> map;
    map["utils.seed"] = "1024";
    sana::Configuration config{map};

    std::optional<unsigned int> possibleValue = config.getValue(sana::UnsignedIntConfig("utils.seed"));
    ASSERT_TRUE(possibleValue.has_value());
    ASSERT_EQ(possibleValue.value(), 1024);

    unsigned int randomKeyDefault = config.getValue(sana::UnsignedIntConfig("random.key"), 202);
    ASSERT_EQ(randomKeyDefault, 202);

    auto randomKeyNoDefault = config.getValue(sana::UnsignedIntConfig("random.key"));
    ASSERT_FALSE(randomKeyNoDefault.has_value());
}
