# Copyright 2021 Practically.io All rights reserved
#
# Use of this source is governed by a BSD-style
# licence that can be found in the LICENCE file or at
# https://www.practically.io/copyright/

file(GLOB_RECURSE ALANGVM_HEADER ${CMAKE_CURRENT_LIST_DIR} *.hpp)
file(GLOB_RECURSE ALANGVM_SOURCE ${CMAKE_CURRENT_LIST_DIR} *.cpp)
list(FILTER ALANGVM_SOURCE EXCLUDE REGEX "_test\\.cpp$")

set(LIBRARIES ${LLVM_LIB})

add_library(alangvm ${ALANGVM_SOURCE} ${ALANGVM_HEADER})
target_link_libraries(alangvm ${LIBRARIES})

#file(GLOB_RECURSE ALANGVM_TEST_SOURCE ${CMAKE_CURRENT_LIST_DIR} *_test.cpp)

#if(NOT BUILD_TESTING MATCHES "OFF")
#  find_package(GTest CONFIG REQUIRED)
#  add_executable(php_paser_test ${ALANGVM_TEST_SOURCE} ${ALANGVM_SOURCE} ${ALANGVM_HEADER})
#  target_link_libraries(php_paser_test framework ${GTEST_LIB} ${LIBRARIES})
#  include(GoogleTest)
#  add_test(NAME php_paser COMMAND  ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/php_paser_test)
#endif()
