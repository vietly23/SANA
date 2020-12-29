cmake_minimum_required(VERSION 3.10.0)
project(SANA 
        DESCRIPTION "Simulated Annealing Network Aligner"
        VERSION 2.0.0 
        LANGUAGES CXX
)

enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_BINARY_DIR}/bin)
# Download dependencies
include(ExternalProject)
set(DEP_INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/Dependency)
ExternalProject_Add(
        dep_spdlog
        GIT_REPOSITORY "https://github.com/gabime/spdlog"
        GIT_TAG "v1.8.2"
        GIT_SHALLOW 1
        UPDATE_COMMAND ""
        PATCH_COMMAND ""
        CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX=${DEP_INSTALL_DIR}
        -DSPDLOG_BUILD_EXAMPLES=OFF
        -DSPDLOG_BUILD_BENCH=OFF
        -DSPDLOG_BUILD_TESTS=OFF
        TEST_COMMAND ""
)

add_subdirectory(src)
# TODO: Add tests
# add_subdirectory(test)

