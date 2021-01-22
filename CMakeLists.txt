cmake_minimum_required(VERSION 3.10.0)
project(SANA 
        DESCRIPTION "Simulated Annealing Network Aligner"
        VERSION 2.0.0 
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

include(cmake/conan.cmake)
conan_cmake_run(REQUIRES spdlog/1.8.2
                cxxopts/2.2.1
                gtest/1.10.0
                di/1.2.0
        BASIC_SETUP
        CMAKE_TARGETS)
add_subdirectory(src)

add_subdirectory(test)

