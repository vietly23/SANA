#include "gtest/gtest.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_sinks.h"

int main(int argc, char **argv) {
    auto stdout_logger = spdlog::stdout_logger_mt("stdoutTestLogger");
    spdlog::set_level(spdlog::level::debug);
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}