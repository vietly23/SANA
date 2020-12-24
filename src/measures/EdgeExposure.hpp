#ifndef EDGEEXPOSURE_HPP
#define EDGEEXPOSURE_HPP
#include <vector>
#include <iostream>

#include "Graph.hpp"
#include "measures/Measure.hpp"
#include "measures/localMeasures/LocalMeasure.hpp"
#include "utils/utils.hpp"

class EdgeExposure : public Measure {
public:
    EdgeExposure(const Graph* G1, const Graph* G2);
    virtual ~EdgeExposure();
    double eval(const Alignment& A);

    static uint getMaxEdge();
    static uint numer, denom;

    static int numExposedEdges(const Alignment& A, const Graph& G1, const Graph& G2);
private:
	static uint EDGE_SUM, MAX_EDGE;
};
#endif

