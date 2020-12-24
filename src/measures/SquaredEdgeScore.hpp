#ifndef SQUAREDEDGESCORE_HPP_
#define SQUAREDEDGESCORE_HPP_
#include <vector>
#include <iostream>

#include "Graph.hpp"
#include "measures/Measure.hpp"
#include "measures/localMeasures/LocalMeasure.hpp"

class SquaredEdgeScore : public Measure {
public:
    SquaredEdgeScore(const Graph* G1, const Graph* G2);
    virtual ~SquaredEdgeScore();
    double eval(const Alignment& A);
    static double getDenom();

    int numSquaredAlignedEdges(const Alignment& A) const;
	static double SES_DENOM;
};

#endif /* SQUAREDEDGESCORE_HPP_ */

