#ifndef GOAVERAGE_HPP
#define GOAVERAGE_HPP
#include "measures/Measure.hpp"

class GoAverage: public Measure {
public:
    GoAverage(Graph* G1, Graph* G2);
    virtual ~GoAverage();
    double eval(const Alignment& A);
private:

};

#endif

