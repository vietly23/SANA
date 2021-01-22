#include "arguments/modeSelector.hpp"

#include "spdlog/spdlog.h"

#include "modes/ParameterEstimation.hpp"
#include "modes/AlphaEstimation.hpp"
#include "modes/NormalMode.hpp"
#include "modes/CreateShadow.hpp"
#include "modes/ClusterMode.hpp"
#include "modes/Experiment.hpp"
#include "modes/AnalysisMode.hpp"
#include "modes/SanaMode.hpp"
#include "modes/SimilarityMode.hpp"
#include "utils/utils.hpp"

bool modeSelector::validMode(string name) {
    vector<string> validModes = {
        "cluster", "exp", "param", "alpha", "dbg",
        "normal", "analysis", "similarity", "shadow"
    };
    return std::any_of(validModes.cbegin(), validModes.cend(),
            [&name](const std::string& validMode){return validMode == name;});
}

Mode* modeSelector::selectMode(ArgumentParser& args) {
    string name = args.strings["-mode"];
    if      (name == "cluster")    return new ClusterMode();
    else if (name == "exp")        return new Experiment();
    else if (name == "param")      return new ParameterEstimation(args.strings["-paramestimation"]);
    else if (name == "alpha")      return new AlphaEstimation();
    else if (name == "shadow")     return new CreateShadow();
    else if (name == "analysis")   return new AnalysisMode();
    else if (name == "similarity") return new SimilarityMode();
    else if (name == "normal")     return new NormalMode();
    else if (name == "pareto")     throw runtime_error("pareto got deprecated since node_colors");
    throw runtime_error("Error: unknown mode: " + name);
}

typedef sana::Mode RefactoredMode;
std::unique_ptr<RefactoredMode> sana::mode::selectMode(const Configuration& configuration) {
    std::string mode = configuration.getValue(StringConfig("mode"), "normal");
    if (mode == "normal") {
        return std::unique_ptr<RefactoredMode>(new NormalMode{configuration, GraphLoader()});
    }
    spdlog::info("Unrecognized mode '{}'. Defaulting to normal mode", mode);
    return std::unique_ptr<RefactoredMode>(new NormalMode{configuration, GraphLoader()});
}
