#ifndef EDGECOUNT_HPP
#define EDGECOUNT_HPP

#include <vector>

#include "measures/localMeasures/LocalMeasure.hpp"

class EdgeCount: public LocalMeasure {
public:
    EdgeCount(const Graph* G1, const Graph* G2, const std::vector<double>& distWeights);
    virtual ~EdgeCount();
private:
    std::vector<double> distWeights;
    void initSimMatrix();
};

#endif

