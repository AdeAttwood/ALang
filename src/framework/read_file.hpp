// Copyright 2021 Practically.io All rights reserved
//
// Use of this source is governed by a BSD-style
// licence that can be found in the LICENCE file or at
// https://www.practically.io/copyright/
#pragma once

#include <fstream>
#include <string>

namespace framework {
std::string read_file(std::string path) {
  std::ifstream stream(path);
  return std::string((std::istreambuf_iterator<char>(stream)), (std::istreambuf_iterator<char>()));
}
}  // namespace framework
