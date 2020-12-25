#ifndef COMPLEMENTARYPROTEINS_HPP
#define COMPLEMENTARYPROTEINS_HPP

#include <string>
#include <vector>

#include "Alignment.hpp"

namespace complementaryProteins {

//the first (second) element is the number of complementary (non-complementary)
//protein pairs such that the proteins appear in both networks
std::vector<uint> countProteinPairsInNetworks(const Graph& G1, const Graph& G2, bool BioGRIDNetworks);
void printProteinPairCountInNetworks(bool BioGRIDNetworks = false);

std::vector<std::vector<std::string>> getProteinPairs(std::string complementStatus, bool BioGRIDNetworks);
std::vector<std::vector<std::string>> getAlignedPairs(const Graph& G1, const Graph& G2, const Alignment& A);
void printComplementaryProteinCounts(const Graph& G1, const Graph& G2, const Alignment& A, bool BioGRIDNetworks);
void printComplementaryProteinCounts(const Alignment& A, bool BioGRIDNetworks = false);

void printLocalTopologicalSimilarities(const Graph& G1, const Graph& G2, bool BioGRIDNetworks);

} //namespace complementaryProteins

#endif /* COMPLEMENTARYPROTEINS_HPP */

