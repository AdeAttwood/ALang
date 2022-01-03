// Copyright 2021-2022 Practically.io All rights reserved
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

static llvm::LLVMContext context;

bool run_test(framework::cli::Command &command, int &index, int &failures, const std::filesystem::path &path) {
  auto test_path = path.string();
  auto module_name = path.filename().string();
  module_name = module_name.substr(0, module_name.length() - 11);

  command.write_line(std::string("<fg:yellow>Module:<reset> " + module_name));

  auto owned_module = std::make_unique<llvm::Module>(module_name, context);
  auto module = owned_module.get();
  std::vector<alangvm::AlangTestFunction> test_functions;

  try {
    auto listener = alangvm::LLVMBuilderListener(context, *module);
    auto parser = parser::alang::Parser(std::filesystem::absolute(test_path));
    parser.pass(listener);

    test_functions = listener.test_functions();
  } catch (const std::exception &e) {
    command.write_line(std::string("  <fg:red>ERROR<reset> ") + e.what());
    failures++;
  }

  auto runner = alangvm::LLVMRunner(std::move(owned_module));
  for (auto &test : test_functions) {
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

  if (std::filesystem::is_regular_file(directory.string())) {
    run_test(command, index, failures, directory.string());
  } else {
    for (auto &entry : std::filesystem::recursive_directory_iterator(directory.string())) {
      if (entry.is_regular_file() && entry.path().string().ends_with(".test.alang")) {
        run_test(command, index, failures, entry.path());
      }
    }
  }

  command.write_line("");
  if (failures > 0) {
    command.write_line("<fg:red>Error:<reset> " + std::to_string(failures) + " tests failed out of " + std::to_string(index));
  } else {
    command.write_line("<fg:green>Success:<reset> All tests has passed");
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
