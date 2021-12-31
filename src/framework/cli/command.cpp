// Copyright 2021 Practically.io All rights reserved
//
// Use of this source is governed by a BSD-style
// licence that can be found in the LICENCE file or at
// https://www.practically.io/copyright/

#include "command.hpp"

#include <string>

namespace framework::cli {
const std::map<std::string, std::string> color_map = {
    {"reset", "\u001b[0m"}, {"fg:red", "\u001b[31m"}, {"fg:yellow", "\u001b[33m"}, {"fg:green", "\u001b[32m"}};

void Command::write(std::string message) {
  for (auto &[color, code] : color_map) {
    std::string place_holder = "<" + color + ">";
    while (message.find(place_holder) != std::string::npos) {
      message.replace(message.find(place_holder), place_holder.size(), m_color ? code : "");
    }
  }

  *m_stream << message;
}
}  // namespace framework::cli
