#ifndef GOSIMILARITY_HPP
#define GOSIMILARITY_HPP

#include <unordered_map>

#include "measures/localMeasures/LocalMeasure.hpp"

class GoSimilarity: public LocalMeasure {
public:
    GoSimilarity(const Graph* G1, const Graph* G2,
        const std::vector<double>& countWeights,
        double occurrencesFraction = 1);
    
    virtual ~GoSimilarity();
    //double eval(const Alignment& A);

    static std::string getGoSimpleFileName(const Graph& G);
    static void ensureGoFileSimpleFormatExists(const Graph& G);

    static std::vector<std::vector<uint>> loadGOTerms(const Graph& G,
        double occurrencesFraction = 1);

    //returns the number of times that each go term appears in G
    static std::unordered_map<uint,uint> getGoCounts(const Graph& G);

    static bool fulfillsPrereqs(const Graph* G1, const Graph* G2);

    static std::vector<uint> leastFrequentGoTerms(const Graph& G,
        double occurrencesFraction);

private:
    static const std::string biogridGOFile;
    
    std::vector<double> countWeights;
    double occurrencesFraction;

    void initSimMatrix();

    static void assertNoRepeatedEntries(const std::vector<std::vector<uint>>& goTerms);
    static void simpleToInternalFormat(const Graph& G, std::string GOFileSimpleFormat, std::string GOFileInternalFormat);
    static void ensureGOFileInternalFormatExists(const Graph& G);

    static uint numberAnnotatedProteins(const Graph& G);

    static void generateGOFileSimpleFormat(std::string GOFile, std::string GOFileSimpleFormat);
    static void generateGene2GoSimpleFormat();

    static bool isBioGRIDNetwork(const Graph& G);
    static bool hasGOData(const Graph& G);
};

#endif

