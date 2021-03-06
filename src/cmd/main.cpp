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
#include <memory>
#include <parser/alang.hpp>

#include "config.h"
#include "llvm/IR/Module.h"

static llvm::LLVMContext context;

framework::cli::ExitCode run(framework::cli::Command command) {
  auto path = command.arguments().at(0);
  if (path.empty()) {
    command.write_line("<fg:red>Error:<reset> Missing required path");
    return framework::cli::ExitCode::ERROR;
  }

  if (command.flags().at("tree").boolean()) {
    auto absolute_path = std::filesystem::absolute(path.string());
    auto parser = parser::alang::Parser(absolute_path);
    command.write_line(parser.to_string_tree());
    return framework::cli::ExitCode::OK;
  }

  auto absolute_path = std::filesystem::absolute(path.string());

  try {
    auto owned_module = std::make_unique<llvm::Module>("main", context);
    auto module = owned_module.get();

    {
      auto listener = alangvm::LLVMBuilderListener(context, *module);
      auto parser = parser::alang::Parser(absolute_path);
      parser.pass(listener);
    }

    if (command.flags().at("ir").boolean()) {
      module->print(llvm::outs(), nullptr);
      owned_module.release();
      return framework::cli::ExitCode::OK;
    }

    auto runner = alangvm::LLVMRunner(std::move(owned_module));
    return static_cast<framework::cli::ExitCode>(runner.run_main());
  } catch (const std::exception& e) {
    command.write_line(std::string("<fg:red>Error:<reset> ") + e.what());
    return framework::cli::ExitCode::ERROR;
  }
}

int main(int argc, char* argv[]) {
  framework::cli::SingleCommandApplication app("ALang", VERSION_NAME);
  app.set_output(&std::cout);

  app.add_argument({"path", "Path to your programme entry point"});
  app.add_flag({"tree", 't', "Print out a tree representation of the programme.", framework::cli::Flag::Boolean});
  app.add_flag({"ir", 'i', "Print out a llvm ir representation of the programme.", framework::cli::Flag::Boolean});

  app.set_callback(*run);
  return app.run(argc, argv);
}
