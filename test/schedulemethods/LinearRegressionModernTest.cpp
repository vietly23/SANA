#include <chrono>
#include <iostream>
#include "gtest/gtest.h"

#include "schedulemethods/LinearRegressionModern.hpp"

TEST(LinearRegressionModernTestSuite, LinearRegressionModernWorks) {
    // TODO: Figure out way to run sana for x iterations.
//    LinearRegressionModern m;
//    auto startInitialComputation = std::chrono::system_clock::now();
//    auto tInitial = m.computeTInitial({20, 30.0});
//    auto endInitialComputation = std::chrono::system_clock::now();
//    auto tFinal = m.computeTFinal({20, 30.0});
//    auto endFinalComputation = std::chrono::system_clock::now();
//    std::cout << tInitial << std::endl;
//    std::cout << tFinal << std::endl;
//    auto initialDuration = std::chrono::duration_cast<std::chrono::seconds>(endInitialComputation - startInitialComputation).count();
//    auto finalDuration = std::chrono::duration_cast<std::chrono::seconds>(endFinalComputation - endInitialComputation).count();
//    // Just to verify results are cached, not correct.
//    EXPECT_LT(finalDuration, initialDuration);
}

