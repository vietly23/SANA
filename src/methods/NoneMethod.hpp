#ifndef NONEMETHOD_HPP
#define NONEMETHOD_HPP

#include <iostream>
#include <string>
#include "methods/Method.hpp"

class NoneMethod : public Method {
public:
    NoneMethod(const Graph* G1, const Graph* G2, std::string startAName);
    ~NoneMethod();
    Alignment run();
    void describeParameters(std::ostream& stream) const;
    std::string fileNameSuffix(const Alignment& A) const;
private:
    Alignment A;
};

#endif

