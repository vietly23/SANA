#ifndef GRAPHLET_HPP_
#define GRAPHLET_HPP_

#include <vector>

#include "measures/localMeasures/LocalMeasure.hpp"

class Graphlet: public LocalMeasure {
public:
    Graphlet(const Graph* G1, const Graph* G2, uint maxGraphletSize);
    virtual ~Graphlet();

private:
	uint maxGraphletSize;
    const uint NUM_ORBITS = 73;
	
    void initSimMatrix();

    std::vector<double> getNumbersOfAffectedOrbits() const;
    std::vector<double> getOrbitWeights() const;
    double getOrbitWeightSum() const;

};

#endif /* GRAPHLET_HPP_ */
