cmake_minimum_required(VERSION 2.8.12)
cmake_policy(SET CMP0048 NEW)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

project(SANA 
	DESCRIPTION "Simulated Annealing Network Aligner"
	VERSION 2.0.0 
	LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)
# add_subdirectory(test)
