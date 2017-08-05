cmake_minimum_required(VERSION 3.0)
project (longLCG)

# set(CMAKE_VERBOSE_MAKEFILE ON)

# modules to find MPIR and TestU01 libraries
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -pedantic -Wextra")

# Catch unit testing library
set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/catch)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

# mpir extended precision integer library (required)
find_package(mpir REQUIRED)

# longLCG library
include_directories(longLCG ${PROJECT_SOURCE_DIR}/inc)
add_library(longLCG src/longLCG.cpp)
target_link_libraries(longLCG ${MPIR_LIBRARIES})

# Make unit test executable
add_executable(tests test/main.cpp)
target_link_libraries(tests Catch longLCG)

# Make TestU01 rng test suite executable
find_package(TestU01)
if(TESTU01_FOUND)
	add_executable(TestU01 testu01.cpp)
	target_include_directories(TestU01 PUBLIC ${TESTU01_INCLUDE_DIR})
	target_link_libraries(TestU01 longLCG ${TESTU01_LIBRARIES})
endif()

#enable_testing()
add_test(NAME Addition COMMAND tests)

#Make running the unit tests part of the build, so failed test = failed build
add_custom_command(TARGET tests POST_BUILD COMMAND tests -d yes)
