cmake_minimum_required(VERSION 3.10.0)
project(SANA 
        DESCRIPTION "Simulated Annealing Network Aligner"
        VERSION 2.0.0 
        LANGUAGES CXX
)

enable_testing()

include(cmake/conan.cmake)
conan_cmake_run(REQUIRES spdlog/1.8.2 BASIC_SETUP CMAKE_TARGETS)
add_subdirectory(src)
# TODO: Add tests
# add_subdirectory(test)

