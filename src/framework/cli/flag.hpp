// Copyright 2021 Practically.io All rights reserved
//
// Use of this source is governed by a BSD-style
// licence that can be found in the LICENCE file or at
// https://www.practically.io/copyright/
#pragma once

#include <string>
#include <variant>
#include <vector>

namespace framework::cli {
struct Flag {
  std::string name;
  char flag;
  std::string description;
  enum { String,
         Integer,
         Boolean } type = String;
  std::variant<std::string, bool, int> value;

  bool empty() const {
    return value.index() == 0 && string().empty();
  }

  void set_value(std::string value_to_set) {
    if (type == Flag::Integer) {
      value = std::stoi(value_to_set);
      return;
    }

    value = value_to_set;
  }

  [[nodiscard]] std::string string() const { return std::get<std::string>(value); }
  [[nodiscard]] bool boolean() const { return empty() ? false : std::get<bool>(value); }
  [[nodiscard]] int integer() const { return empty() ? 0 : std::get<int>(value); }
};
}  // namespace framework::cli
