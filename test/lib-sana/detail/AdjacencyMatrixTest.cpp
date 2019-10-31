#ifndef SANA_ADJ_MATRIX_TEST
#define SANA_ADJ_MATRIX_TEST

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

TEST(AdjacencyMatrixIteratorSuite, TestEdgeValue) {
    using namespace sana::detail;
    AdjacencyMatrix adjMatrix;
    adjMatrix.resize(3);
    adjMatrix.setEdgeValue(0, 0, true);
    adjMatrix.setEdgeValue(1, 2, true);
    adjMatrix.setEdgeValue(0, 1, true);
    adjMatrix.setEdgeValue(0, 2, true);

    // Yes, ASSERT_TRUE works for bools. Using EXPECT_EQ is better
    // for explicitly stating we are comparing files
    EXPECT_EQ(adjMatrix.edgeValue(0, 0), true);
    EXPECT_EQ(adjMatrix.edgeValue(1, 2), true);
    EXPECT_EQ(adjMatrix.edgeValue(2, 1), true);
    EXPECT_EQ(adjMatrix.edgeValue(0, 1), true);
    EXPECT_EQ(adjMatrix.edgeValue(1, 0), true);
    EXPECT_EQ(adjMatrix.edgeValue(2, 0), true);
}

TEST(AdjacencyMatrixIteratorSuite, TestIterator) {
    using namespace sana::detail;
    AdjacencyMatrix adjMatrix;
    adjMatrix.resize(3);
    adjMatrix.setEdgeValue(0, 0, true);
    adjMatrix.setEdgeValue(1, 2, true);
    adjMatrix.setEdgeValue(0, 1, true);
    adjMatrix.setEdgeValue(0, 2, true);
}
#endif

