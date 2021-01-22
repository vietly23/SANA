#include <iostream>
#include <cstdlib>

#include <thread>

#include "boost/di.hpp"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_sinks.h"

#include "arguments/ArgumentParser.hpp"
#include "arguments/modeSelector.hpp"
#include "configuration/Configuration.hpp"
#include "configuration/ConfigurationOption.hpp"
#include "modes/Mode.hpp"
#include "utils/Utility.hpp"

using namespace sana;
namespace di = boost::di;

seed generateSeed(const Configuration &);
void configureLogging(const Configuration &);

int main(int argc, char* argv[]) {
    ArgumentParser args;
    Configuration configuration = args.parseArguments(argc, argv);

    // Configuration
    configureLogging(configuration);
    spdlog::info("Configuration values: {}", configuration.toString());
    spdlog::info("SANA: {}", SANA_VERSION);
    std::unique_ptr<sana::Mode> mode = mode::selectMode(configuration);
    mode->run();
    return 0;
}

seed generateSeed(const Configuration & config) {
    auto seedValue = config.getValue(UnsignedIntConfig("utils.seed"));
    if (seedValue.has_value()) {
        spdlog::info("Configuring initial seed with value {}", seedValue.value());
        return sana::seed{seedValue.value()};
    } else {
        return sana::seed{std::random_device{}()};
    }
}

void configureLogging(const Configuration & configuration) {
    // Configure logging
    std::optional<bool> enableLogging = configuration.getValue(BooleanConfig("logging.enabled"));
    std::string logLevel = configuration.getValue(StringConfig("logging.level"), "info");
    if (enableLogging.has_value() && enableLogging.value()) {
        auto stderrLogger = spdlog::stderr_logger_st("stderr_console_logger");
        if (logLevel == "info") {
            spdlog::set_level(spdlog::level::info);
        } else if (logLevel == "debug") {
            spdlog::set_level(spdlog::level::debug);
        }
    }
}
