#ifndef NODECORRECTNESS_HPP
#define NODECORRECTNESS_HPP
#include <vector>
#include "measures/Measure.hpp"

class NodeCorrectness: public Measure {
public:
    NodeCorrectness(const std::vector<uint>& A);
    virtual ~NodeCorrectness();
    double eval(const Alignment& A);
    std::unordered_map<std::string, double> evalByColor(const Alignment& A, const Graph& G1, const Graph& G2) const;
    virtual std::vector<uint> getMappingforNC() const;
    static std::vector<uint> createTrueAlignment(const Graph& G1, const Graph& G2, const std::vector<std::string>& E);
    static bool fulfillsPrereqs(const Graph* G1, const Graph* G2);
    
private:
    std::vector<uint> trueAWithValidCountAppended;

};

#endif

