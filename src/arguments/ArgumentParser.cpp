#include "arguments/ArgumentParser.hpp"

#include <iostream>
#include <ctime>
#include <unistd.h>

#include "spdlog/spdlog.h"
#include "cxxopts.hpp"

#include "utils/utils.hpp"

using namespace std;

cxxopts::Options constructCliOptions() {
    cxxopts::Options options("SANA", "Executable to align networks using simulated annealing");
    options.add_options()
            ("graph1", "First network (smaller one). Requirement: An alignment file must exist inside the networks "
                       "directory which matches the name of the specified species.",
                    cxxopts::value<std::string>()->default_value("yeast.gw"))
            ("graph2", "Second (larger in number of nodes) network. Requirement: An alignment file must exist "
                       "inside the networks directory which matches the name of the specified species.",
                    cxxopts::value<std::string>()->default_value("human.gw"))
            ("skip-graph-validation", "Skip graph validation. Speed up load time by skipping checks for graph validity")
            ("seed", "Set seeds for internal components for random number generation", cxxopts::value<int>())
            ("mode", "Sets the algorithm that performs the alignment. NOTE: All methods except \"sana/hc/random/none\" "
                     "call an external algorithm written by other authors. Possible aligners are: \"sana\", "
                     "\"lgraal\", \"hubalign\", \"wave\", \"random\", \"netal\", \"migraal\", \"ghost\", \"piswap\", "
                     "\"optnetalign\", \"spinal\", \"great\", \"natalie\", \"gedevo\", \"magna\", \"waveSim\", "
                     "\"none\", and \"hc\".")
            ("initial-alignment", "Starting Alignment. File containing the starting alignment by SANA.")
            // Miscellaneous Options
            ("version", "Print version of SANA and the compiler")
            ("h,help", "Print usage")
            ("logging", "Enable logging")
            ("log-level", "Log level", cxxopts::value<std::string>());
    return options;
}
void validateOptions(const cxxopts::ParseResult& result);

sana::Configuration ArgumentParser::parseArguments(int argc, char* argv[]) {
    cxxopts::Options options = constructCliOptions();
    std::map<std::string, std::string> map;
    try {
        auto result = options.parse(argc, argv);
        validateOptions(result);
        if (result.count("help")) {
            std::cout << options.help() << std::endl;
            exit(0);
        } else if (result.count("version")) {
            std::cout << SANA_VERSION << std::endl;
            exit(0);
        }
        map["graph1.filename"] = result["graph1"].as<std::string>();
        map["graph2.filename"] = result["graph2"].as<std::string>();
        map["logging.enabled"] = result["logging"].count() ? "true" : "false";
        if (result.count("log-level")) {
            map["logging.level"] = result["log-level"].as<std::string>();
        }
        if (result.count("seed")) {
            // Convert back to string - force cast to verify parameter is an integer
            map["utils.seed"] = to_string(result["seed"].as<int>());
        }
    } catch (const cxxopts::OptionException& e) {
        std::cerr << "Unable to parse options: " << e.what() << std::endl;
        std::cout << options.help() << std::endl;
        exit(-1);
    }
    sana::Configuration config(map);
    return config;
}

void validateOptions(const cxxopts::ParseResult& result) {
    if (result.count("log-level")) {
        std::string level = result["log-level"].as<std::string>();
        if (level != "info" and level != "debug") {
            throw cxxopts::OptionException("Unrecognized argument: '" + level + "'. Acceptable values for "
                                                                                "--log-level are 'info' or 'debug'");
        }
    }
}

