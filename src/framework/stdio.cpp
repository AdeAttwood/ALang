// Copyright 2021 Practically.io All rights reserved
//
// Use of this source is governed by a BSD-style
// licence that can be found in the LICENCE file or at
// https://www.practically.io/copyright/

#include "stdio.hpp"

#include <iostream>

#include "logger.hpp"

namespace framework::stdio {

void server(std::function<void(const std::string &)> callback) {
  while (1) {
    std::string line;
    for (std::string line; std::getline(std::cin, line);) {
      callback(line);
    }
  }
}

}  // namespace framework::stdio
