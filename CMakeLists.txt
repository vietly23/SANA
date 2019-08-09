cmake_minimum_required(VERSION 3.0.0)
cmake_policy(SET CMP0048 NEW)

project(SANA 
	DESCRIPTION "Simulated Annealing Network Aligner"
	VERSION 2.0.0 
	LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)
# add_subdirectory(test)
