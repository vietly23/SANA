#ifndef NodeCount_HPP
#define NodeCount_HPP

#include <vector>

#include "measures/localMeasures/LocalMeasure.hpp"

class NodeCount: public LocalMeasure {
public:
    NodeCount(const Graph* G1, const Graph* G2, const std::vector<double>& distWeights);
    virtual ~NodeCount();
private:
    std::vector<double> distWeights;
    
    void initSimMatrix();
};

#endif

