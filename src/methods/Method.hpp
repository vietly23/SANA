#ifndef METHOD_HPP
#define METHOD_HPP

#include <string>
#include <iostream>

#include "Alignment.hpp"
#include "graph/Graph.hpp"
#include "utils/Timer.hpp"
#include "utils/utils.hpp"

class Method {
public:
    Method(const Graph* G1, const Graph* G2, std::string name);
    virtual ~Method();
    Alignment runAndPrintTime();
    virtual Alignment run() =0;
    virtual void describeParameters(std::ostream& stream) const =0;
    virtual std::string fileNameSuffix(const Alignment& A) const =0;

    std::string getName() const;
    double getExecTime() const;

protected:
    const Graph* G1;
    const Graph* G2;

private:
    std::string name;
    double execTime;
};

#endif
