#ifndef REPORT_HPP_
#define REPORT_HPP_

#include <string>
#include "Graph.hpp"
#include "Alignment.hpp"
#include "measures/CoreScore.hpp"
#include "measures/MeasureCombination.hpp"
#include "methods/Method.hpp"

class Report {
public:

static void saveReport(const Graph& G1, const Graph& G2, const Alignment& A,
    const MeasureCombination& M, const Method* method, const std::string& reportFileName, bool longVersion);
static void saveLocalMeasures(const Graph& G1, const Graph& G2, const Alignment& A,
    const MeasureCombination& M, const Method* method, const std::string& localMeasureFile);

/*Some pair of nodes dubbed as "core alignment" appear to have greater affinity
  for aligning with each other as opposed to other nodes. We've tried to
  measure this affinity across iterations by assigning scores based on
  frequency and pBad value (SANA.cpp). This function prints the node pairs
  along with corresponding scores in a file with .naf (network alignment
  frequency) extension. For more detail:
  https://github.com/waynebhayes/SANA/pull/132#issuecomment-646183330 */
static void saveCoreScore(const Graph& G1, const Graph& G2, const Alignment& A, const Method*,
        CoreScoreData& coreScoreData, const std::string& outputFileName);

private:

//print the alignment in edge list format, using node names, and sorted from least frequent to most frequent color
static void saveAlignmentAsEdgeList(const Alignment& A, const Graph& G1, const Graph& G2, const std::string& fileName);

//this function does so many things I can't give it a more relevant name -Nil
static std::string formattedFileName(const std::string& outFileName, const std::string& extension,
    const std::string& G1Name, const std::string& G2Name, const Method* method, Alignment const & A);

static void printGraphStats(const Graph& G, uint numCCsToPrint, std::ofstream& ofs);
};

#endif /* REPORT_HPP_ */
