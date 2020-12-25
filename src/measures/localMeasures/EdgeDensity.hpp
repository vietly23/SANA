#ifndef EDGEDENSITY_HPP
#define EDGEDENSITY_HPP

#include <vector>

#include "measures/localMeasures/LocalMeasure.hpp"

class EdgeDensity: public LocalMeasure {
public:
    EdgeDensity(const Graph* G1, const Graph* G2, uint maxDist);
    virtual ~EdgeDensity();
private:
    void initSimMatrix();
    float compare(double n1, double n2);
    double calcEdgeDensity(const Graph* G, uint originNode, uint maxDist) const;
    std::vector<double> generateVector(const Graph* G, uint maxDist) const;
    std::vector<double> edged1;
    std::vector<double> edged2;
    std::vector<std::vector<uint>> edgeList; //edges in no particular order
    uint maxDist;
};

#endif

