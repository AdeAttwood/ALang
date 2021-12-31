// Copyright 2021 Practically.io All rights reserved
//
// Use of this source is governed by a BSD-style
// licence that can be found in the LICENCE file or at
// https://www.practically.io/copyright/
#pragma once

#include <string>
#include <variant>

namespace framework::cli {
struct Argument {
  std::string name;
  std::string description;
  enum { String,
         Integer } type = String;
  std::variant<std::string, int> value;

  [[nodiscard]] bool empty() const { return value.index() == 0 && string().empty(); }
  [[nodiscard]] std::string string() const { return std::get<std::string>(value); }
  [[nodiscard]] int integer() const { return empty() ? 0 : std::get<int>(value); }
};
}  // namespace framework::cli