add_executable(sana_test_suite
        utils/UtilityTest.cpp
        configuration/ConfigurationTest.cpp
        configuration/ConfigurationOptionTest.cpp AlignmentTest.cpp temperature/TemperatureScheduleTest.cpp schedulemethods/LinearRegressionModernTest.cpp main.cpp graph/GraphLoaderTest.cpp graph/GraphTest.cpp)
target_link_libraries(sana_test_suite CONAN_PKG::gtest CONAN_PKG::gtest sana_lib)