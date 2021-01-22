#include <cstdio>

#include "gtest/gtest.h"

#include "utils/Utility.hpp"

using namespace sana;
TEST(UtilityTest, RandomDoubleReproducible) {
    for (int i = 0; i < 5; i++) {
        sana::RandomUtility utility{seed{10}};
        ASSERT_DOUBLE_EQ(utility.randomDouble(), 0.29876115866268999);
        ASSERT_DOUBLE_EQ(utility.randomDouble(), 0.49458992830960824);
        ASSERT_DOUBLE_EQ(utility.randomDouble(), 0.44301494621523846);
        ASSERT_DOUBLE_EQ(utility.randomDouble(), 0.83191136195063686);
        ASSERT_DOUBLE_EQ(utility.randomDouble(), 0.58332174213102717);
    }
}

TEST(UtilityTest, RandomIntReproducible) {
    for (int i = 0; i < 5; i++) {
        sana::RandomUtility utility{seed{10}};
        ASSERT_DOUBLE_EQ(utility.randomInteger(0, 100), 77);
        ASSERT_DOUBLE_EQ(utility.randomInteger(0, 100), 30);
        ASSERT_DOUBLE_EQ(utility.randomInteger(0, 100), 2);
        ASSERT_DOUBLE_EQ(utility.randomInteger(0, 100), 49);
        ASSERT_DOUBLE_EQ(utility.randomInteger(0, 100), 63);
    }
}
