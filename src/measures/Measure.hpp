#ifndef MEASURE_HPP
#define MEASURE_HPP

#include <string>

#include "Alignment.hpp"
#include "graph/Graph.hpp"
#include "utils/Timer.hpp"
#include "utils/utils.hpp"

class Measure {
public:
    Measure(const Graph* G1, const Graph* G2, const std::string& name);
    virtual ~Measure();
    virtual double eval(const Alignment& A) = 0;
    std::string getName();
    virtual bool isLocal();
    virtual double balanceWeight();
protected:
    const Graph* G1;
    const Graph* G2;
private:
    std::string name;
};

#endif

