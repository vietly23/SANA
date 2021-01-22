#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP
#include <unordered_map>

#include "graph/GraphLoader.hpp"
#include "measures/localMeasures/LocalMeasure.hpp"

class Sequence: public LocalMeasure {
public:
    Sequence(const Graph* G1, const Graph* G2);
    virtual ~Sequence();
    void generateBitscoresFile(string bitscoresFile);

    static bool fulfillsPrereqs(const Graph* G1, const Graph* G2);

private:

    unordered_map<string,string> initNameMap(string curatedFastaFile);
    void initSimMatrix();

    static string blastScoreFile(const string& G1Name, const string& G2Name);
};

#endif

