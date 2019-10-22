#ifndef SANA_GRAPH_TEST
#define SANA_GRAPH_TEST

#include <gtest/gtest.h>

#include "AdjacencyMatrix.hpp"

TEST(AdjacencyMatrixIteratorSuite, TestUtilites) {
    using namespace sana::detail;
    EXPECT_EQ(translateVertex(0, 0), 0);
    EXPECT_EQ(translateVertex(3, 2), 8);
    EXPECT_EQ(translateVertex(2, 3), 8);
    EXPECT_EQ(translateVertex(1, 1), 2);
    EXPECT_EQ(translateVertex(1, 0), 1);
    EXPECT_EQ(translateVertex(4, 1), 11);
    EXPECT_EQ(translateVertex(1, 4), 11);

}

TEST(AdjacencyMatrixIteratorSuite, TestIterator) {
    /*
    using namespace sana::detail;
    UndirectedAdjacencyMatrix adjMatrix;
    adjMatrix.resize(3);
    */
}

#endif
