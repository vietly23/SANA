ADD_EXECUTABLE(test-lib-sana 

    # temperature schedule sanity checks
    temperatureSchedule/LinearRegressionTest.cpp
    temperatureSchedule/TemperatureScheduleTest.cpp

    # graph sanity checks
    # graph/GraphTest.cpp
    # container type tests
    detail/AdjacencyMatrixTest.cpp

    main.cpp
)

TARGET_LINK_LIBRARIES(test-lib-sana
    PUBLIC
        sana_lib
        gtest
        gtest_main
)

ADD_TEST(NAME test-lib-sana
    COMMAND test-lib-sana)

add_custom_target(test-verbose COMMAND ${CMAKE_CTEST_COMMAND} --verbose)

