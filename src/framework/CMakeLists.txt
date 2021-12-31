# Copyright 2021 Practically.io All rights reserved
#
# Use of this source is governed by a BSD-style
# licence that can be found in the LICENCE file or at
# https://www.practically.io/copyright/

file(GLOB_RECURSE FRAMEWORK_HEADER ${CMAKE_CURRENT_LIST_DIR} *.hpp)
file(GLOB_RECURSE FRAMEWORK_SOURCE ${CMAKE_CURRENT_LIST_DIR} *.cpp)
list(FILTER FRAMEWORK_SOURCE EXCLUDE REGEX "_test\\.cpp$")

set(LIBRARIES nlohmann_json::nlohmann_json fmt::fmt)

add_library(framework ${FRAMEWORK_SOURCE} ${FRAMEWORK_HEADER})
target_link_libraries(framework ${LIBRARIES})

if(NOT BUILD_TESTING MATCHES "OFF")
  find_package(GTest CONFIG REQUIRED)
  file(GLOB_RECURSE FRAMEWORK_TEST_SOURCE ${CMAKE_CURRENT_LIST_DIR} *_test.cpp)

  add_executable(framework_test ${FRAMEWORK_TEST_SOURCE} ${FRAMEWORK_SOURCE} ${FRAMEWORK_HEADER})
  target_link_libraries(framework_test framework ${LIBRARIES} ${GTEST_LIB})
  include(GoogleTest)
  add_test(NAME framework COMMAND  ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/framework_test)
endif()