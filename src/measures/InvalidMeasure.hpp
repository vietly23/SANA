#ifndef INVALIDMEASURE_HPP
#define INVALIDMEASURE_HPP

#include "measures/Measure.hpp"

class InvalidMeasure: public Measure {
public:
    InvalidMeasure();
    virtual ~InvalidMeasure();
    double eval(const Alignment& A);

private:

};

#endif

