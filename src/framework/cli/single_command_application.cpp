// Copyright 2021 Practically.io All rights reserved
//
// Use of this source is governed by a BSD-style
// licence that can be found in the LICENCE file or at
// https://www.practically.io/copyright/

#include "single_command_application.hpp"

#include <fmt/core.h>

namespace framework::cli {
void SingleCommandApplication::help() {
  write_line(fmt::format("<fg:green>{} {}<reset>", m_name, m_version_string));
  if (!arguments().empty()) {
    write_line("");
    write_line("<fg:yellow>Arguments<reset>");
    for (auto &argument : m_arguments) {
      write_line(fmt::format("  [{}] {}", argument.name, argument.description));
    }
  }

  int flag_padding = 8;
  for (auto &[name, _] : m_flags) {
    if (name.size() > flag_padding) {
      flag_padding = name.size();
    }
  }

  auto flag_padding_string = fmt::format(":<{}", flag_padding + 1);

  write_line("");
  write_line("<fg:yellow>Flags<reset>");
  for (auto &[name, flag] : m_flags) {
    if (flag.flag == ' ') {
      write_line(fmt::format("      --{" + flag_padding_string + "} {}", name, flag.description));
    } else {
      write_line(fmt::format("  -{}, --{" + flag_padding_string + "} {}", flag.flag, name, flag.description));
    }
  }

  write_line(fmt::format("      --{" + flag_padding_string + "} Disable color output", "no-color"));
  write_line(fmt::format("  -v, --{" + flag_padding_string + "} Show version information", "version"));
  write_line(fmt::format("  -h, --{" + flag_padding_string + "} Display this message", "help"));
  write_line("");
}

int SingleCommandApplication::run(int argc, char *argv[]) {  // NOLINT(modernize-avoid-c-arrays)
  std::vector<std::string> args;
  args.reserve(argc);
  // Skip the first argument because that will be the programme name.
  for (int i = 1; i < argc; i++) {
    args.push_back(argv[i]);
  }

  return run(args);
}

int SingleCommandApplication::run(std::vector<std::string> args) {
  int argument_index = 0;
  for (int i = 0; i < args.size(); i++) {
    std::string arg = args[i];

    if (arg.starts_with("--")) {
      auto flag_name = arg.substr(2);
      if (arg == "--version") {
        write_line(m_version_string);
        return 0;
      }

      if (arg == "--help") {
        help();
        return 0;
      }

      if (arg == "--no-color") {
        m_color = false;
        continue;
      }

      if (!m_flags.contains(flag_name)) {
        // TODO(ade): Invalid long flag
      }

      if (m_flags[flag_name].type == Flag::Boolean) {
        m_flags[flag_name].value = true;
      } else {
        m_flags[flag_name].set_value(args[i++ + 1]);
      }
      continue;
    }

    if (arg.starts_with('-')) {
      if (arg == "-v") {
        write_line(m_version_string);
        return 0;
      }

      if (arg == "-h") {
        help();
        return 0;
      }

      for (auto &[name, flag] : m_flags) {
        if (arg.substr(1) == std::string(1, flag.flag)) {
          if (m_flags[name].type == Flag::Boolean) {
            m_flags[name].value = true;
          } else {
            m_flags[name].set_value(args[i++ + 1]);
          }

          break;
        }
      }

      // TODO(ade): Invalid short flag
      continue;
    }

    if (m_arguments.size() > argument_index) {
      if (m_arguments[argument_index].type == Argument::Integer) {
        m_arguments[argument_index].value = std::stoi(arg);
      } else {
        m_arguments[argument_index].value = arg;
      }

      argument_index++;
      continue;
    }

    // TODO(ade): Invalid argument
  }

  return m_callback(*this);
}
}  // namespace framework::cli
