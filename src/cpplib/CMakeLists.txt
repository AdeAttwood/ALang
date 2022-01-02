# Copyright 2021-2022 Practically.io All rights reserved
#
# Use of this source is governed by a BSD-style
# licence that can be found in the LICENCE file or at
# https://www.practically.io/copyright/

file(GLOB_RECURSE CPPLIB_SOURCE ${CMAKE_CURRENT_LIST_DIR} *.cpp)
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/alang-ext/cpplib)

foreach(SOURCE ${CPPLIB_SOURCE})
  file(RELATIVE_PATH SOURCE_RELATIVE ${CMAKE_CURRENT_LIST_DIR}  ${SOURCE})
  string(REGEX REPLACE "[.]cpp$" ".ll" OUTPUT_LL ${SOURCE_RELATIVE})

  string(REGEX REPLACE "[.]cpp$" ".hpp" HEADER_SOURCE ${SOURCE})
  if(EXISTS "${HEADER_SOURCE}")
    set(SOURCE_DEPENDS ${HEADER_SOURCE})
  endif()

  add_custom_command(
    OUTPUT ${CMAKE_BINARY_DIR}/alang-ext/cpplib/${OUTPUT_LL}
    COMMAND clang++ -S -emit-llvm ${SOURCE} -o ${CMAKE_BINARY_DIR}/alang-ext/cpplib/${OUTPUT_LL}
    DEPENDS ${SOURCE_DEPENDS})

  list(APPEND SOURCE_RESULTS ${CMAKE_BINARY_DIR}/alang-ext/cpplib/${OUTPUT_LL})
endforeach()

add_custom_target(cpplib ALL DEPENDS ${SOURCE_RESULTS})
