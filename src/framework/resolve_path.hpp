// Copyright 2021 Practically.io All rights reserved
//
// Use of this source is governed by a BSD-style
// licence that can be found in the LICENCE file or at
// https://www.practically.io/copyright/
#pragma once

#include <filesystem>
#include <string>

namespace framework {
std::string resolve_path(const std::string &path) {
  auto baseDir = std::filesystem::current_path();
  while (baseDir.has_parent_path()) {
    auto combinePath = baseDir / path;
    if (std::filesystem::exists(combinePath)) {
      return combinePath.string();
    }
    baseDir = baseDir.parent_path();
  }

  throw std::runtime_error("File not found!");
}
}  // namespace framework
