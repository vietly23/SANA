#ifndef NODEDENSITY_HPP
#define NODEDENSITY_HPP

#include <vector>

#include "measures/localMeasures/LocalMeasure.hpp"

class NodeDensity: public LocalMeasure {
public:
    NodeDensity(const Graph* G1, const Graph* G2, uint maxDist);
    virtual ~NodeDensity();
private:
    void initSimMatrix();
    float compare(double n1, double n2);
    double calcNodeDensity(const Graph* G, uint originNode, uint maxDist) const;
    std::vector<double> generateVector(const Graph* G, uint maxDist) const;
    std::vector<double> noded1;
    std::vector<double> noded2;
    std::vector<std::vector<uint>> nodedList; //edges in no particular order
    uint maxDist;
};

#endif

