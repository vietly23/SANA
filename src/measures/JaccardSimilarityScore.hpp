#ifndef JACCARDSIMILARITYSCORE_HPP
#define JACCARDSIMILARITYSCORE_HPP
#include "measures/Measure.hpp"

#include <vector>

class JaccardSimilarityScore: public Measure {
public:
    JaccardSimilarityScore(const Graph* G1, const Graph* G2);
    virtual ~JaccardSimilarityScore();
    double eval(const Alignment& A);
    static std::vector<uint> getAlignedByNode(const Graph *G1, const Graph *G2, const Alignment& A);
    // vector<uint> getAlignedByNode(const Alignment& A);
};

#endif