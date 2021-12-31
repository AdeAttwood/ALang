// Copyright 2021 Practically.io All rights reserved
//
// Use of this source is governed by a BSD-style
// licence that can be found in the LICENCE file or at
// https://www.practically.io/copyright/
#pragma once

#include <ctype.h>

#include <string>

namespace framework::inflector {

void to_snake_case(std::string &input) {
  for (int i = 0; i < input.length(); i++) {
    if (input.at(i) == ' ') {
      input[i] = '_';
    } else if (i != 0 && input.at(i - 1) != '_' && std::isupper(input.at(i))) {
      input.insert(i, "_");
      i++;
    }
    input[i] = std::tolower(input.at(i));
  }
}

}  // namespace framework::inflector
