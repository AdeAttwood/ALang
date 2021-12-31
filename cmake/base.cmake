# Set the build type if its not test
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

# Ensure the build type is valid
if(NOT "${CMAKE_BUILD_TYPE}" STREQUAL "Debug" AND
   NOT "${CMAKE_BUILD_TYPE}" STREQUAL "Release" AND
   NOT "${CMAKE_BUILD_TYPE}" STREQUAL "MinSizeRel" AND
   NOT "${CMAKE_BUILD_TYPE}" STREQUAL "RelWithDebInfo")
    message(FATAL_ERROR "Unknown build type \"${CMAKE_BUILD_TYPE}\". Allowed values are Debug, Release, RelWithDebInfo, and MinSizeRel.")
endif()

# detect operating system and host processor
message(STATUS "We are on a ${CMAKE_SYSTEM_NAME} system")
message(STATUS "The host processor is ${CMAKE_HOST_SYSTEM_PROCESSOR}")

# Place binaries and libraries according to GNU standards. For example
# executables created with `add_executable` will be built into the `bin`
# directory
include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

# Set the default compiler flags for GNU
if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    # TODO(ade): Add back in the removed flags -Woverloaded-virtual
    # TODO(ade): Remove the -Wno-attributes to enable the warninga again when
    # antlr4 is released and upgraded to >=4.9.3
    # See: https://github.com/antlr/antlr4/pull/2773
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-attributes -Wunreachable-code -Wno-unknown-pragmas -Wno-sign-compare -Wwrite-strings -Wno-unused")
    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g3")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
endif()
