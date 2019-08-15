add_library(sana_lib 
    # Graph Types
    BinaryGraph.cpp 
    WeightedGraph.cpp
    Graph.cpp
    
    # SANA Specific Code
    PairwiseAlignment.cpp
    SANAConfiguration.cpp
    TemperatureSchedule.cpp
    SANA.cpp
    SANAResult.cpp
    
    # Utilities
    Timer.cpp
    LinearRegression.cpp
    Random.cpp 
    Utils.cpp
)

target_link_libraries(sana_lib Boost::log)

target_include_directories(sana_lib
    PUBLIC
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
target_compile_options(sana_lib PRIVATE -Werror)
target_compile_features(sana_lib PRIVATE cxx_std_11)

# target_include_directories(lib-sana PUBLIC ${Included-headers-directories})
