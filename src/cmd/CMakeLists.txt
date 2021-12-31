# Copyright 2021 Practically.io All rights reserved
#
# Use of this source is governed by a BSD-style
# licence that can be found in the LICENCE file or at
# https://www.practically.io/copyright/

file(GLOB_RECURSE ALANG_HEADER ${CMAKE_CURRENT_LIST_DIR} *.hpp)
file(GLOB_RECURSE ALANG_SOURCE ${CMAKE_CURRENT_LIST_DIR} *.cpp)
list(FILTER ALANG_SOURCE EXCLUDE REGEX "_test\\.cpp$")

set(LIBRARIES framework parser alangvm)

add_executable(alang ${CMAKE_CURRENT_LIST_DIR}/main.cpp)
target_link_libraries(alang ${LIBRARIES})

add_executable(alang-test ${CMAKE_CURRENT_LIST_DIR}/test.cpp)
target_link_libraries(alang-test ${LIBRARIES})
