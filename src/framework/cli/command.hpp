// Copyright 2021 Practically.io All rights reserved
//
// Use of this source is governed by a BSD-style
// licence that can be found in the LICENCE file or at
// https://www.practically.io/copyright/
#pragma once

#include <functional>
#include <map>
#include <string>
#include <vector>

#include "argument.hpp"
#include "exit_code.hpp"
#include "flag.hpp"

namespace framework::cli {
class Command {
 protected:
  std::vector<Argument> m_arguments;
  std::map<std::string, Flag> m_flags;
  std::function<ExitCode(Command)> m_callback;
  bool m_color = true;
  std::ostream *m_stream;

 public:
  std::vector<Argument> arguments() const { return m_arguments; }
  std::map<std::string, Flag> flags() const { return m_flags; }

  // Set the call back for the command that will get run with all parsed flags
  void set_callback(std::function<ExitCode(Command)> callback) { m_callback = callback; }
  // Overrides the output stream where all the command output will be printed. This is useful when testing the commands
  void set_output(std::ostream *stream) { m_stream = stream; }

  void add_argument(const Argument &argument) { m_arguments.emplace_back(argument); }
  void add_flag(const Flag flag) { m_flags[flag.name] = flag; }

  void write(std::string);
  void write_line(const std::string &message) { write(message + "\n"); };
};
}  // namespace framework::cli
