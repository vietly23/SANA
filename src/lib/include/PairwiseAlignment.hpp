#ifndef PAIRWISE_ALIGNMENT_H
#define PAIRWISE_ALIGNMENT_H

#include "Graph.hpp"
#include "Alignment.hpp"

class PairwiseAlignment: public Alignment {

    std::vector<ushort> A;

public:

    PairwiseAlignment() = default;
    ~PairwiseAlignment() = default;
    PairwiseAlignment(const PairwiseAlignment &rhs);

    void setVector(std::vector<unsigned short> &x) {
        A = x;
    }
    std::vector<unsigned short> &getVec() {
        return A;
    }
    bool printDefinitionErrors(const Graph &G1, const Graph &G2);
};

#endif
