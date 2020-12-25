#ifndef HILLCLIMBING_HPP
#define HILLCLIMBING_HPP

#include <map>

#include "measures/MeasureCombination.hpp"
#include "methods/Method.hpp"

class HillClimbing: public Method {
public:
    HillClimbing();
    HillClimbing(const Graph* G1, const Graph* G2, MeasureCombination* M, std::string startAName);
    virtual ~HillClimbing();

    Alignment run();
    void describeParameters(std::ostream& stream) const;
    std::string fileNameSuffix(const Alignment& A) const;
    double getExecutionTime() const;


private:

    MeasureCombination *M;
    double changeProbability;
    std::string startAName;
    Alignment startA;
    
    double executionTime;

    //random number generation
    std::mt19937 gen;
    std::uniform_int_distribution<> G1RandomNode;
    std::uniform_int_distribution<> G2RandomUnassignedNode;
    std::uniform_real_distribution<> randomReal;
};

#endif
