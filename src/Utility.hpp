#include "Graph.hpp"
#include "BinaryGraph.hpp"
#include <string>
#include "PairwiseAlignment.hpp"

class Utility {
public:
    static BinaryGraph LoadBinaryGraphFromLEDAFile(const std::string &);
    static BinaryGraph LoadBinaryGraphFromEdgeList(const std::string &);
    static PairwiseAlignment LoadPairwiseAlignmentFromEdgeList(Graph *G1, Graph *G2, const std::string &filename);
};


