# Copyright 2021 Practically.io All rights reserved
#
# Use of this source is governed by a BSD-style
# licence that can be found in the LICENCE file or at
# https://www.practically.io/copyright/

file(GLOB_RECURSE PARSER_HEADER ${CMAKE_CURRENT_LIST_DIR} *.hpp)
file(GLOB_RECURSE PARSER_SOURCE ${CMAKE_CURRENT_LIST_DIR} *.cpp)
list(FILTER PARSER_SOURCE EXCLUDE REGEX "_test\\.cpp$")

set(LIBRARIES ${ANTLR4_LIB})

add_library(parser ${PARSER_SOURCE} ${PARSER_HEADER})
target_link_libraries(parser PRIVATE ${LIBRARIES})

add_custom_command(
        OUTPUT ${CMAKE_CURRENT_LIST_DIR}/ALang.interp ${CMAKE_CURRENT_LIST_DIR}/ALang.tokens
        COMMAND antlr4 -Dlanguage=Cpp -package 'parser::alang' -o alang ALang.g4
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
        DEPENDS ALang.g4)

add_custom_target(parser_antlr DEPENDS ALang.interp ALang.tokens)

if(NOT BUILD_TESTING MATCHES "OFF")
    find_package(GTest CONFIG REQUIRED)
    file(GLOB_RECURSE PARSER_TEST_SOURCE ${CMAKE_CURRENT_LIST_DIR} *_test.cpp)

    add_executable(parser_test ${PARSER_TEST_SOURCE} ${PARSER_SOURCE} ${PARSER_HEADER})
    target_link_libraries(parser_test parser ${LIBRARIES} ${GTEST_LIB})
    include(GoogleTest)
    add_test(NAME parser COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/parser_test)
endif()
