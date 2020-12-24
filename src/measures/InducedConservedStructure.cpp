#include "measures/InducedConservedStructure.hpp"

#include <vector>

InducedConservedStructure::InducedConservedStructure(const Graph* G1, const Graph* G2) : Measure(G1, G2, "ics") {
}

InducedConservedStructure::~InducedConservedStructure() {
}

double InducedConservedStructure::eval(const Alignment& A) {
    return (double) A.numAlignedEdges(*G1, *G2)/G2->numEdgesInNodeInducedSubgraph(A.asVector());
}
