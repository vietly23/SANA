#ifndef GRAPHLETLGRAAL_HPP_
#define GRAPHLETLGRAAL_HPP_

#include <vector>

#include "measures/localMeasures/LocalMeasure.hpp"

class GraphletLGraal: public LocalMeasure {
public:
    GraphletLGraal(const Graph* G1, const Graph* G2, uint maxGraphletSize);
    virtual ~GraphletLGraal();

private:
	uint maxGraphletSize;
    void initSimMatrix();
    
    double gdvSim(uint i, uint j, const std::vector<std::vector<uint>>& gdvsG1,
        const std::vector<std::vector<uint>>& gdvsG2) const;
};

#endif /* GRAPHLETLGRAAL_HPP_ */
