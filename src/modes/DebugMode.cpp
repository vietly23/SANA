#include "modes/DebugMode.hpp"

#include <algorithm>
#include <utility>

#include "arguments/ArgumentParser.hpp"
#include "arguments/measureSelector.hpp"
#include "arguments/MethodSelector.hpp"
#include "arguments/GraphLoader.hpp"

#include "Graph.hpp"
#include "Alignment.hpp"
#include "NormalMode.hpp"
#include "complementaryProteins.hpp"
#include "measures/MeasureCombination.hpp"
#include "measures/localMeasures/GoSimilarity.hpp"
#include "methods/Method.hpp"
#include "methods/SANA.hpp"
#include "schedulemethods/LinearRegressionVintage.hpp"
#include "utils/utils.hpp"

void DebugMode::run(ArgumentParser& args) {

    pair<Graph, Graph> graphs = GraphLoader::initGraphs(args);
    Graph G1 = graphs.first;
    Graph G2 = graphs.second;

}

std::string DebugMode::getName(void) {
    return "DebugMode";
}
