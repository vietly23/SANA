#include "measures/InvalidMeasure.hpp"

#include <iostream>
#include <vector>

using namespace std;

InvalidMeasure::InvalidMeasure(): Measure(NULL, NULL, "invalid") {
}

InvalidMeasure::~InvalidMeasure() {
}

double InvalidMeasure::eval(const Alignment& A) {
    return -1;
}
