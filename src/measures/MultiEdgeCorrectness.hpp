#ifndef MULTIEDGECORRECTNESS_HPP
#define MULTIEDGECORRECTNESS_HPP
#include "Graph.hpp"
#include "measures/Measure.hpp"

class MultiEdgeCorrectness: public Measure {
public:
    MultiEdgeCorrectness(const Graph* G1, const Graph* G2);
    virtual ~MultiEdgeCorrectness();
    double eval(const Alignment& A);

};

#endif

