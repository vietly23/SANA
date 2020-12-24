#include <vector>
#include "measures/MultiEdgeCorrectness.hpp"

MultiEdgeCorrectness::MultiEdgeCorrectness(const Graph* G1, const Graph* G2) : Measure(G1, G2, "mec") {
}

MultiEdgeCorrectness::~MultiEdgeCorrectness() {
}

double MultiEdgeCorrectness::eval(const Alignment& A) {
#ifdef MULTI_PAIRWISE
    return (double) A.numAlignedEdges(*G1, *G2)/(G2->getTotalEdgeWeight() + G1->getTotalEdgeWeight());
#else
    return 1;
#endif
}
