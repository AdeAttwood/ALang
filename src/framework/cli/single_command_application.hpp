// Copyright 2021 Practically.io All rights reserved
//
// Use of this source is governed by a BSD-style
// licence that can be found in the LICENCE file or at
// https://www.practically.io/copyright/
#pragma once

#include <string>

#include "command.hpp"

namespace framework::cli {
class SingleCommandApplication : public Command {
  std::string m_name;
  std::string m_version_string;

 public:
  SingleCommandApplication(std::string name, std::string version_string)
      : m_name(std::move(name)),
        m_version_string(std::move(version_string)) {}
  int run(int, char*[]);  // NOLINT(modernize-avoid-c-arrays)
  int run(std::vector<std::string>);
  void help();
};
}  // namespace framework::cli
