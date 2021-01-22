# SANA LIBRARY COMPILATION
add_library(sana_lib
        Alignment.cpp
        graph/Graph.cpp
        complementaryProteins.cpp
        Report.cpp
        arguments/ArgumentParser.cpp
        graph/GraphLoader.cpp
        arguments/MethodSelector.cpp
        arguments/SupportedArguments.cpp
        arguments/measureSelector.cpp
        arguments/modeSelector.cpp
        configuration/Configuration.cpp
        configuration/ConfigurationOption.cpp
        methods/Method.cpp
        methods/SANA.cpp
        methods/NoneMethod.cpp
        methods/HillClimbing.cpp
        methods/wrappers/LGraalWrapper.cpp
        methods/wrappers/WAVEWrapper.cpp
        methods/wrappers/GEDEVOWrapper.cpp
        methods/wrappers/SPINALWrapper.cpp
        methods/wrappers/GREATWrapper.cpp
        methods/wrappers/MIGRAALWrapper.cpp
        methods/wrappers/SANAPISWAPWrapper.cpp
        methods/wrappers/PISwapWrapper.cpp
        methods/wrappers/PINALOGWrapper.cpp
        methods/wrappers/OptNetAlignWrapper.cpp
        methods/wrappers/WrappedMethod.cpp
        methods/wrappers/HubAlignWrapper.cpp
        methods/wrappers/GHOSTWrapper.cpp
        methods/wrappers/NETALWrapper.cpp
        methods/wrappers/MagnaWrapper.cpp
        methods/wrappers/NATALIEWrapper.cpp
        methods/wrappers/CytoGEDEVOWrapper.cpp
        methods/RandomAligner.cpp
        measures/MeasureCombination.cpp
        measures/SymmetricSubstructureScore.cpp
        measures/localMeasures/Importance.cpp
        measures/localMeasures/EdgeCount.cpp
        measures/localMeasures/GraphletLGraal.cpp
        measures/localMeasures/NodeDensity.cpp
        measures/localMeasures/GraphletNorm.cpp
        measures/localMeasures/GraphletCosine.cpp
        measures/localMeasures/NodeCount.cpp
        measures/localMeasures/ExternalSimMatrix.cpp
        measures/localMeasures/GenericLocalMeasure.cpp
        measures/localMeasures/EdgeDensity.cpp
        measures/localMeasures/LocalMeasure.cpp
        measures/localMeasures/GoSimilarity.cpp
        measures/localMeasures/Sequence.cpp
        measures/localMeasures/Graphlet.cpp
        measures/LargestCommonConnectedSubgraph.cpp
        measures/EdgeExposure.cpp
        measures/EdgeDifference.cpp
        measures/EdgeCorrectness.cpp
        measures/SquaredEdgeScore.cpp
        measures/WeightedEdgeConservation.cpp
        measures/NetGO.cpp
        measures/MultiS3.cpp
        measures/InducedConservedStructure.cpp
        measures/JaccardSimilarityScore.cpp
        measures/SymmetricEdgeCoverage.cpp
        measures/EdgeRatio.cpp
        measures/ExternalWeightedEdgeConservation.cpp
        measures/InvalidMeasure.cpp
        measures/CoreScore.cpp
        measures/GoAverage.cpp
        measures/NodeCorrectness.cpp
        measures/MultiEdgeCorrectness.cpp
        measures/Measure.cpp
        modes/ClusterMode.cpp
        modes/ParameterEstimation.cpp
        modes/CreateShadow.cpp
        modes/SimilarityMode.cpp
        modes/AnalysisMode.cpp
        modes/NormalMode.cpp
        modes/AlphaEstimation.cpp
        modes/Experiment.cpp
        schedulemethods/ScheduleMethod.cpp
        schedulemethods/StatisticalTest.cpp
        schedulemethods/IteratedAmeur.cpp
        schedulemethods/scheduleUtils.cpp
        schedulemethods/LinearRegressionVintage.cpp
        schedulemethods/PBadBinarySearch.cpp
        schedulemethods/Ameur.cpp
        schedulemethods/LinearRegressionModern.cpp
        schedulemethods/IteratedLinearRegression.cpp
        temperature/TemperatureSchedule.cpp
        utils/LinearRegression.cpp
        utils/FileIO.cpp
        utils/ParetoFront.cpp
        utils/ComputeGraphletsWrapper.cpp
        utils/Timer.cpp
        utils/Matrix.cpp
        utils/utils.cpp
        utils/templateUtils.cpp
        utils/randomSeed.cpp
        utils/NormalDistribution.cpp
        utils/computeGraphlets.cpp
        utils/Utility.cpp
        modes/Mode.cpp modes/SanaMode.cpp modes/SanaMode.hpp measures/AlignmentEvaluator.cpp measures/AlignmentEvaluator.hpp)
set(SANA_VERSION "Version ${PROJECT_VERSION} - Compiled by ${CMAKE_CXX_COMPILER_ID}_${CMAKE_CXX_COMPILER_VERSION}")
target_link_libraries(sana_lib CONAN_PKG::spdlog CONAN_PKG::cxxopts)
target_include_directories(sana_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(sana_lib PUBLIC SANA_VERSION="${SANA_VERSION}")

# SANA EXECUTABLE COMPILATION
add_executable(sana_exe main.cpp temperature/TemperatureSchedule.cpp temperature/TemperatureSchedule.hpp)
target_link_libraries(sana_exe PUBLIC sana_lib -pthread CONAN_PKG::spdlog CONAN_PKG::cxxopts CONAN_PKG::di)
target_compile_definitions(sana_exe PUBLIC SANA_VERSION="${SANA_VERSION}")
