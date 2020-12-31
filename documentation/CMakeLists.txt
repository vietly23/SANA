cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(SANA_Documentation
        VERSION 2.0.0)

# ---- Doxygen variables ----

# set Doxyfile variables
set(DOXYGEN_PROJECT_NAME SANA)
# TODO: Share common variables?
set(DOXYGEN_PROJECT_VERSION ${PROJECT_VERSION})
set(DOXYGEN_PROJECT_INPUT "${PROJECT_ROOT}")
set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/doxygen")

configure_file(${CMAKE_CURRENT_LIST_DIR}/Doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

add_custom_target(
        GenerateDocs
        DEPENDS
        pages/help_output.md
        pages/help_tutorial.md
            Doxyfile
        COMMAND
            ${CMAKE_COMMAND} -E make_directory "${DOXYGEN_OUTPUT_DIRECTORY}"
        COMMAND
            "doxygen"
        COMMENT
            "Docs written to: ${DOXYGEN_OUTPUT_DIRECTORY}"
        WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
)
