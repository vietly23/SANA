#ifndef NETGO_HPP
#define NETGO_HPP
#include "measures/Measure.hpp"
#include "measures/localMeasures/LocalMeasure.hpp"

class NetGO: public Measure {
public:
    NetGO(const Graph* G1, const Graph* G2);
    virtual ~NetGO();
    double eval(const Alignment& A);
private:
    bool NORMALIZE;
    double Permutation(uint M, uint N);
    double GOtermValuePerAlignment(uint M, uint N);
    double GOtermValuePerAlignedPair(uint M, uint N);
    double scoreUpperBound();
};

#endif

