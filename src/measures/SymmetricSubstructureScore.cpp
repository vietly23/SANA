#include "measures/SymmetricSubstructureScore.hpp"

#include <vector>

SymmetricSubstructureScore::SymmetricSubstructureScore(const Graph* G1, const Graph* G2) : Measure(G1, G2, "s3") {
}

SymmetricSubstructureScore::~SymmetricSubstructureScore() {
}

double SymmetricSubstructureScore::eval(const Alignment& A) {
    double aligEdges = A.numAlignedEdges(*G1, *G2);
    return aligEdges / 
        (G1->getNumEdges() + G2->numEdgesInNodeInducedSubgraph(A.asVector()) - aligEdges);
}
