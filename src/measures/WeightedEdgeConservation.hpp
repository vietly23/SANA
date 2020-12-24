#ifndef WEIGHTEDEDGECONSERVATION_HPP
#define WEIGHTEDEDGECONSERVATION_HPP
#include <vector>
#include <iostream>

#include "Graph.hpp"
#include "measures/Measure.hpp"
#include "measures/localMeasures/LocalMeasure.hpp"

class WeightedEdgeConservation: public Measure {
public:
    WeightedEdgeConservation(const Graph* G1, const Graph* G2, LocalMeasure* m);
    virtual ~WeightedEdgeConservation();
    double eval(const Alignment& A);
    LocalMeasure* getNodeSimMeasure();
private:
    LocalMeasure *nodeSim;
};

#endif

