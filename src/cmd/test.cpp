// Copyright 2021 Practically.io All rights reserved
//
// Use of this source is governed by a BSD-style
// licence that can be found in the LICENCE file or at
// https://www.practically.io/copyright/

#include <alangvm/builder.hpp>
#include <alangvm/runner.hpp>
#include <filesystem>
#include <framework/cli/single_command_application.hpp>
#include <iostream>

#include "config.h"

bool run_test(framework::cli::Command &command, int &index, int &failures, const std::filesystem::path &path) {
  auto test_path = path.string();
  auto module_name = path.filename().string();
  module_name = module_name.substr(0, module_name.length() - 11);

  command.write_line("<fg:yellow>Module: <reset>" + module_name);

  std::shared_ptr<alangvm::LLVMBuilderListener> builder;

  try {
    builder = alangvm::build(std::filesystem::absolute(test_path));
    auto runner = alangvm::LLVMRunner(builder->module());
    for (auto &test : builder->test_functions()) {
      auto test_name = test.name;
      index++;

      auto result = runner.run_function(test.name);
      if (result == 0) {
        command.write_line("  <fg:green>PASS<reset> " + test_name);
      } else {
        command.write_line("  <fg:red>FAIL<reset> " + test_name);
        failures++;
      }
    }
  } catch (const std::exception &e) {
    command.write_line(std::string("  <fg:red>ERROR<reset> ") + e.what());
    failures++;
  }

  return true;
}

framework::cli::ExitCode run(framework::cli::Command command) {
  auto directory = command.arguments().at(0);
  if (directory.empty()) {
    command.write_line("<fg:red>Error:<reset> Missing required directory");
    return framework::cli::ExitCode::ERROR;
  }

  int index = 0;
  int failures = 0;
  for (auto &entry : std::filesystem::recursive_directory_iterator(directory.string())) {
    if (entry.is_regular_file() && entry.path().string().ends_with(".test.alang")) {
      run_test(command, index, failures, entry.path());
    }
  }

  return failures > 0 ? framework::cli::ExitCode::ERROR : framework::cli::ExitCode::OK;
}

int main(int argc, char *argv[]) {
  framework::cli::SingleCommandApplication app("ALang Test", VERSION_NAME);
  app.set_output(&std::cout);

  app.add_argument({"directory", "Path to your where all of your tests are"});

  app.set_callback(*run);
  return app.run(argc, argv);
}
