#include <sstream>

#include "gtest/gtest.h"

#include "graph/GraphLoader.hpp"

TEST(GraphLoaderFromStream, ParseFormatGW) {
    std::stringstream iss("LEDA.GRAPH\n"
                          "string\n"
                          "long\n"
                          "-2\n"
                          "4\n"
                          "|{NodeA}|\n"
                          "|{NodeB}|\n"
                          "|{NodeC}|\n"
                          "|{NodeD}|\n"
                          "5\n"
                          "1 2 0 |{0}|\n"
                          "1 3 0 |{0}|\n"
                          "2 3 0 |{0}|\n"
                          "2 4 0 |{0}|\n"
                          "3 4 0 |{0}|\n");
    GraphLoader graphLoader;
    auto graphData = graphLoader.loadGraph(iss);
    EXPECT_EQ(graphData->NodeNames.size(), 4);
    EXPECT_EQ(graphData->EdgeList.size(), 5);
    auto actualEdgeList = graphData->EdgeList;
    std::vector<sana::Edge> expectedEdgeList{sana::Edge({0}, {1}),
                                             sana::Edge({0}, {2}),
                                             sana::Edge({1}, {2}),
                                             sana::Edge({1}, {3}),
                                             sana::Edge({2}, {3})};
    ASSERT_EQ(expectedEdgeList.size(), actualEdgeList.size());
    for (int i = 0; i < actualEdgeList.size(); i++) {
        auto expectedEdge = expectedEdgeList.at(i);
        auto actualEdge = actualEdgeList.at(i);

        EXPECT_EQ(expectedEdge.source, actualEdge.source);
        EXPECT_EQ(expectedEdge.destination, actualEdge.destination);
    }
}

TEST(GraphLoaderFromStream, UnorderedEdgeListGW) {
    std::stringstream iss("LEDA.GRAPH\n"
                          "string\n"
                          "long\n"
                          "-2\n"
                          "4\n"
                          "|{NodeA}|\n"
                          "|{NodeB}|\n"
                          "|{NodeC}|\n"
                          "|{NodeD}|\n"
                          "5\n"
                          "2 3 0 |{0}|\n"
                          "3 4 0 |{0}|\n"
                          "1 2 0 |{0}|\n"
                          "2 4 0 |{0}|\n"
                          "1 3 0 |{0}|\n");
    GraphLoader graphLoader;
    auto graphData = graphLoader.loadGraph(iss);
    EXPECT_EQ(graphData->NodeNames.size(), 4);
    EXPECT_EQ(graphData->EdgeList.size(), 5);
    auto actualEdgeList = graphData->EdgeList;
    std::vector<sana::Edge> expectedEdgeList{sana::Edge({0}, {1}),
                                             sana::Edge({0}, {2}),
                                             sana::Edge({1}, {2}),
                                             sana::Edge({1}, {3}),
                                             sana::Edge({2}, {3})};
    ASSERT_EQ(expectedEdgeList.size(), actualEdgeList.size());
    for (int i = 0; i < actualEdgeList.size(); i++) {
        auto expectedEdge = expectedEdgeList.at(i);
        auto actualEdge = actualEdgeList.at(i);
        EXPECT_EQ(expectedEdge.source, actualEdge.source);
        EXPECT_EQ(expectedEdge.destination, actualEdge.destination);
    }
}