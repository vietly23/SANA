#ifndef RANDOMALIGNER_HPP
#define RANDOMALIGNER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "methods/Method.hpp"

using namespace std;

class RandomAligner: public Method {
public:

    RandomAligner(const Graph* G1, const Graph* G2);
    Alignment run();
    void describeParameters(ostream& stream) const;
    string fileNameSuffix(const Alignment& A) const;

private:

};

#endif
