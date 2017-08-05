# - Try to find TestU01
# Once done this will define:
# TESTU01_FOUND - Set to TRUE if we found everything (library, includes)
# TESTU01_INCLUDE_DIR - headers
# TESTU01_LIBRARIES - libraries

find_path(TESTU01_INCLUDE_DIR NAMES unif01.h bbattery.h PATH_SUFFIXES testu01)
find_library(TESTU01_LIBRARIES NAMES testu01)

if(TESTU01_LIBRARIES AND TESTU01_INCLUDE_DIR)
	set(TESTU01_FOUND true)
endif()

if(TESTU01_FOUND)
	if(NOT TESTU01_FIND_QUIETLY)
		message(STATUS "found TestU01 header file in ${TESTU01_INCLUDE_DIR}")
		message(STATUS "found TestU01 libraries: ${TESTU01_LIBRARIES}")
	endif()
else(TESTU01_FOUND)
	if(TESTU01_FIND_REQUIRED)
		message(FATAL_ERROR "could not find package TestU01")
	else(TESTU01_FIND_REQUIRED)
		message(STATUS "optional package TestU01 was not found")
	endif(TESTU01_FIND_REQUIRED)
endif(TESTU01_FOUND)

