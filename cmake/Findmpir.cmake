# - Try to find MPIR
# Once done this will define:
# MPIR_FOUND - Set to TRUE if we found everything (library, includes)
# MPIR_INCLUDE_DIR - headers
# MPIR_LIBRARIES - libraries

find_path(MPIR_INCLUDE_DIR NAMES mpir.h)
find_library(MPIR_LIBRARIES NAMES mpir)

if(MPIR_LIBRARIES AND MPIR_INCLUDE_DIR)
	set(MPIR_FOUND true)
endif()

if(MPIR_FOUND)
	if(NOT MPIR_FIND_QUIETLY)
		message(STATUS "found MPIR header file in ${MPIR_INCLUDE_DIR}")
		message(STATUS "found MPIR libraries: ${MPIR_LIBRARIES}")
	endif()
else(MPIR_FOUND)
	if(MPIR_FIND_REQUIRED)
		message(FATAL_ERROR "could not find package MPIR")
	else(MPIR_FIND_REQUIRED)
		message(STATUS "optional package MPIR was not found")
	endif(MPIR_FIND_REQUIRED)
endif(MPIR_FOUND)

