# - Try to find testu01
# Once done this will define:
# TESTU01_FOUND - Set to TRUE if we found everything (library, includes)
# TESTU01_INCLUDE_DIRS - headers
# TESTU01_LIBRARIES - libraries

# try to find package using pkg-config (if available)
find_package(PkgConfig)
pkg_check_modules(PC_testu01 QUIET testu01)

# look for the include and library paths
find_path(TESTU01_INCLUDE_DIR NAMES unif01.h bbattery.h PATH_SUFFIXES testu01 PATHS ${PC_testu01_INCLUDE_DIRS})
find_library(TESTU01_LIBRARY NAMES testu01 PATHS ${PC_testu01_LIBRARY_DIRS})

# set TESTU01_FOUND variable and display standard error / success messages
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(testu01 DEFAULT_MSG TESTU01_LIBRARY TESTU01_INCLUDE_DIR)

# set return variables
if(TESTU01_FOUND)
  set(TESTU01_LIBRARIES ${TESTU01_LIBRARY})
  set(TESTU01_INCLUDE_DIRS ${TESTU01_INCLUDE_DIR})
endif()
