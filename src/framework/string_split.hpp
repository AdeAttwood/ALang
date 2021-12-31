// Copyright 2021 Practically.io All rights reserved
//
// Use of this source is governed by a BSD-style
// licence that can be found in the LICENCE file or at
// https://www.practically.io/copyright/
#pragma once

#include <string>
#include <vector>

namespace framework {
inline std::vector<std::string> string_split(const std::string& source, const std::string& delimiter) {
  std::string string = source;
  std::vector<std::string> output;

  size_t position = 0;
  while ((position = string.find(delimiter)) != std::string::npos) {
    output.push_back(string.substr(0, position));
    string.erase(0, position + delimiter.length());
  }

  if (string.length() > 0) {
    output.push_back(string);
  }

  return output;
}
}  // namespace framework