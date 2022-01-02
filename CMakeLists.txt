# Copyright 2021-2022 Practically.io All rights reserved
#
# Use of this source is governed by a BSD-style
# licence that can be found in the LICENCE file or at
# https://www.practically.io/copyright/

cmake_minimum_required(VERSION 3.16)
set(PROJECT_VERSION_NAME "v0.0.1")

# Split and sanatize the project version so it can be uses as pars and used as
# the project version "v1.1.1" is not a valida version number
string(REPLACE "v" "" PROJECT_VERSION ${PROJECT_VERSION_NAME})
string(REPLACE "." ";" VERSION_LIST ${PROJECT_VERSION})
list(GET VERSION_LIST 0 PROJECT_VERSION_MAJOR)
list(GET VERSION_LIST 1 PROJECT_VERSION_MINOR)
list(GET VERSION_LIST 2 PROJECT_VERSION_PATCH)

project ("ALang" VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(./cmake/base.cmake)
include(./cmake/package.cmake)

find_package(PkgConfig REQUIRED)
find_package(Threads REQUIRED)
find_package(LLVM 12 REQUIRED CONFIG)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

find_library(ANTLR4 antlr4-runtime)
find_library(LIBUID uuid)
set(ANTLR4_LIB ${ANTLR4} ${LIBUID})

set(LLVM_LIB Threads::Threads dl tinfo z LLVM)

find_path(ANTLR4_INCLUDE_DIR antlr4-runtime/antlr4-runtime.h)
include_directories("${PROJECT_BINARY_DIR}" "${CMAKE_CURRENT_LIST_DIR}/src" "${LLVM_INCLUDE_DIR}" "${ANTLR4_INCLUDE_DIR}/antlr4-runtime")

link_directories(${LLVM_LINK_DIR})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h)

# Add the test directory. It is optional and can be disabled during with
#   cmake -DBUILD_TESTING=OFF ..
# To run unit tests produced here, we only need to run:
#   make test
if(NOT BUILD_TESTING MATCHES "OFF")
  enable_testing()
  find_package(GTest CONFIG REQUIRED)
  set(GTEST_LIB GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)

  add_test(NAME code-test COMMAND  ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/alang-test ${CMAKE_SOURCE_DIR}/code)
  set_tests_properties(code-test PROPERTIES ENVIRONMENT ALANG_PATH=${CMAKE_BINARY_DIR}/alang-ext)
endif()

add_subdirectory("${CMAKE_SOURCE_DIR}/src/framework")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/parser")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/alangvm")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/cmd")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/cpplib")
