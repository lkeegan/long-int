# - Try to find MPIR
# Once done this will define:
# MPIR_FOUND - Set to TRUE if we found everything (library, includes)
# MPIR_INCLUDE_DIRS - headers
# MPIR_LIBRARIES - libraries

# try to find package using pkg-config (if available)
find_package(PkgConfig)
pkg_check_modules(PC_mpir QUIET mpir)

# look for the include and library paths
find_path(MPIR_INCLUDE_DIR NAMES mpir.h PATHS ${PC_mpir_INCLUDE_DIRS})
find_library(MPIR_LIBRARY NAMES mpir PATHS ${PC_mpir_LIBRARY_DIRS})

# set MPIR_FOUND variable and display standard error / success messages
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(mpir DEFAULT_MSG MPIR_LIBRARY MPIR_INCLUDE_DIR)

# set return variables
if(MPIR_FOUND)
  set(MPIR_LIBRARIES ${MPIR_LIBRARY})
  set(MPIR_INCLUDE_DIRS ${MPIR_INCLUDE_DIR})
endif()
