#ifndef LOCALMEASURE_HPP
#define LOCALMEASURE_HPP

#include <vector>

#include "Graph.hpp"
#include "measures/Measure.hpp"

class LocalMeasure: public Measure {
public:
    LocalMeasure(const Graph* G1, const Graph* G2, const std::string& name);
    virtual ~LocalMeasure() =0;
    virtual double eval(const Alignment& A);
    bool isLocal();
    std::vector<std::vector<float>>* getSimMatrix();
    void writeSimsWithNames(std::string outfile);
    double balanceWeight();

protected:
    void loadBinSimMatrix(std::string simMatrixFileName);
    virtual void initSimMatrix() =0;
    
    std::vector<std::vector<float>> sims;
    static const std::string autogenMatricesFolder;
};

#endif

