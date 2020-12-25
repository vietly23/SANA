#ifndef MEASURECOMBINATION_HPP
#define MEASURECOMBINATION_HPP
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <thread>
#include <algorithm>
#include <map>
#include <functional>
#include <iomanip>

#include "measures/Measure.hpp"

class MeasureCombination {
public:
    MeasureCombination();
    ~MeasureCombination();
    double eval(const Alignment& A) const;
    double eval(const std::string& measureName, const Alignment& A) const;
    void addMeasure(Measure* m, double weight);
    void addMeasure(Measure* m);
    void printWeights(std::ostream& ofs) const;
    void printMeasures(const Alignment& A, std::ostream& ofs) const;
    double getWeight(const std::string& measureName) const;
    Measure* getMeasure(const std::string& measureName) const;
    Measure* getMeasure(int i) const;
    bool containsMeasure(const std::string& measureName) const;
    void normalize();
    uint numMeasures() const;
    std::string toString() const;

    double getSumLocalWeight() const;
    //Please note that the return types are references
    //to private variables, similar to C# get {}
    //The const postfix has been therefore been removed
    //because these functions can lead to state changes.
    std::vector<std::vector<float>>& getAggregatedLocalSims();
    std::map<std::string, std::vector<std::vector<float>> >& getLocalSimMap();

    int getNumberOfLocalMeasures() const;
    void rebalanceWeight(std::string& input);
    void rebalanceWeight();
    /*Writes out the local scores file in this format (example only of course):
    Pairwise Alignment  LocalMeasure1       LocalMeasure2       Weighted Sum
    821    723            0.334               0.214               0.548
    */
    void writeLocalScores(std::ostream & outfile, Graph const & G1, Graph const & G2, Alignment const & A) const;

private:
    typedef std::vector<std::vector<float>> SimMatrix;
    typedef std::function<void(SimMatrix &, uint const &, uint const &)> SimMatrixRecipe;
    std::vector<Measure*> measures;
    std::vector<double> weights;
    SimMatrix localAggregatedSim;
    std::map<std::string, SimMatrix> localScoreSimMap;
    
    void initn1n2(uint& n1, uint& n2) const;

    //Abstracts the construction of the similarity matrix. Instead of the get..()
    //functions producing possibly different implementations of similarity matrices,
    //a common type of similarity matrix is produced in initSim and populated
    //by a Recipe function.
    std::vector<std::vector<float>> initSim(SimMatrixRecipe Recipe) const;

    void clearWeights();
    void setWeight(const std::string& measureName, double weight);
};

#endif

