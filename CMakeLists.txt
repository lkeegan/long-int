cmake_minimum_required(VERSION 3.0)

project (long-int)

# Prepare "Catch" library for other executables
set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/catch)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

# mpir extended precision integer routines
include_directories(usr/local/include)
link_directories(usr/local/lib)

# My "longLCG" library
include_directories(${PROJECT_SOURCE_DIR}/inc)
add_library(longLCG src/longLCG.cpp)

# Make test executable
add_executable(tests test/main.cpp)
target_link_libraries(tests Catch longLCG mpir)

#enable_testing()
add_test(NAME Addition COMMAND tests)

#Make running the tests part of the build, so failed test = failed build
add_custom_command(TARGET tests POST_BUILD COMMAND tests)
