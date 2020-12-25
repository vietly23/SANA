#ifndef GENERICLOCALMEASURE_HPP
#define GENERICLOCALMEASURE_HPP

#include "measures/localMeasures/LocalMeasure.hpp"

#include <string>
#include <vector>

class GenericLocalMeasure: public LocalMeasure {
public:
    GenericLocalMeasure(const Graph* G1, const Graph* G2, std::string name, const std::vector<std::vector<float>>& simMatrix);
    virtual ~GenericLocalMeasure();
private:

    void initSimMatrix();
};

#endif

