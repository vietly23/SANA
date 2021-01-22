#include <array>
#include <sstream>
#include <vector>

#include "gtest/gtest.h"

#include "Alignment.hpp"
#include "graph/Graph.hpp"
#include "utils/Utility.hpp"

TEST(AlignmentTestSuite, WriteAlignmentAsMapping) {
    std::vector<unsigned int> randomAlignment(5);
    for (int i = 0; i < 5; i++) randomAlignment[i] = i;

    std::ostringstream out;
    sana::AlignmentUtility utility;
    utility.writeMapping(randomAlignment, out);
    EXPECT_EQ(out.str(), "0 1 2 3 4\n");

    std::ostringstream reverseOut;
    std::reverse(randomAlignment.begin(), randomAlignment.end());
    utility.writeMapping(randomAlignment, reverseOut);
    EXPECT_EQ(reverseOut.str(), "4 3 2 1 0\n");
}

TEST(AlignmentTestSuite, WriteAlignmentAsEdgeList) {
    Graph G1("g1", "", Graph::EdgeList{}, Graph::NodeNames{"A", "B", "C"}, Graph::EdgeWeights{}, Graph::NodeColors{});
    Graph G2("g1", "", Graph::EdgeList{}, Graph::NodeNames{"A1", "B1", "C1"}, Graph::EdgeWeights{}, Graph::NodeColors{});

    std::ostringstream out;
    sana::AlignmentUtility utility;
    utility.writeEdgeList(G1, G2, sana::Alignment{2, 0, 1}, out);
    std::ostringstream EXPECTED;
    EXPECTED << "A\tC1" << std::endl << "B\tA1" << std::endl << "C\tB1" << std::endl;
    EXPECT_EQ(out.str(), EXPECTED.str());
}

