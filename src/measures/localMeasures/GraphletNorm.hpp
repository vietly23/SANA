#ifndef GRAPHLETNORM_HPP
#define GRAPHLETNORM_HPP

#include <vector>

#include "measures/localMeasures/LocalMeasure.hpp"

class GraphletNorm: public LocalMeasure {
public:
    GraphletNorm(const Graph* G1, const Graph* G2, uint maxGraphletSize);
    virtual ~GraphletNorm();

private:
    uint maxGraphletSize;
    void initSimMatrix();
    double magnitude(std::vector<uint> &vector);
    const uint NUM_ORBITS = 73;
    std::vector<double> NODV(std::vector<uint> &v);
    double ODVratio(std::vector<double> &u, std::vector<double> &v, uint i);
    double RMS_ODVdiff1(std::vector<uint> &u, std::vector<uint> &v);
    double ODVsim(std::vector<uint> &u, std::vector<uint> &v);
    std::vector<uint> reduce(std::vector<uint> &v);
    
};

#endif
