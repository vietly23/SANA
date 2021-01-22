#include "gtest/gtest.h"

#include "graph/Graph.hpp"

TEST(GraphTestSuite, EdgeComparatorWorks) {
    sana::Edge a({0}, {0});
    EXPECT_FALSE(sana::Edge::compare(a, a));

    sana::Edge b({0}, {1});
    EXPECT_TRUE(sana::Edge::compare(a, b));
    EXPECT_FALSE(sana::Edge::compare(b, a));

    sana::Edge higherDest({3}, {10});
    sana::Edge lowerDest({4}, {9});
    EXPECT_TRUE(sana::Edge::compare(higherDest, lowerDest));
}