#ifndef GRAPHLETCOSINE_HPP
#define GRAPHLETCOSINE_HPP

#include <vector>

#include "measures/localMeasures/LocalMeasure.hpp"

class GraphletCosine: public LocalMeasure {
public:
    GraphletCosine(const Graph* G1, const Graph* G2, uint maxGraphletSize);
    virtual ~GraphletCosine();

private:
	uint maxGraphletSize;
    void initSimMatrix();
    std::vector<uint> reduce(std::vector<uint> &v);
    const uint NUM_ORBITS = 73;
    double cosineSimilarity(std::vector<uint> &v1, std::vector<uint> &v2);
    double dot(std::vector<uint> &v1, std::vector<uint> &v2);
    double magnitude(std::vector<uint> &vector);
};

#endif
