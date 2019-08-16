add_subdirectory(lib)

add_executable(sana_exe main.cpp Utility.cpp) 
target_link_libraries(sana_exe sana_lib)

target_link_libraries(sana_exe Boost::program_options)

target_compile_options(sana_exe PRIVATE -Werror)
target_compile_features(sana_exe PRIVATE cxx_std_17)
# 
# target_include_directories(sana_exe INTERFACE $<CMAKE_CURRENT_SOURCE_DIR/lib>)
# 
