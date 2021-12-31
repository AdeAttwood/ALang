// Copyright 2021 Practically.io All rights reserved
//
// Use of this source is governed by a BSD-style
// licence that can be found in the LICENCE file or at
// https://www.practically.io/copyright/

#include <gtest/gtest.h>

#include <framework/cli/single_command_application.hpp>
#include <sstream>

using framework::cli::Command;
using framework::cli::ExitCode;

TEST(framework_cli, create_a_base_single_command_application) {
  std::stringstream stream;
  framework::cli::SingleCommandApplication app("My App", "v0.0.1");
  app.set_output(&stream);

  std::vector<std::string> args({"-v"});
  auto exit_code = app.run(args);

  EXPECT_EQ("v0.0.1\n", stream.str());
  EXPECT_EQ(ExitCode::OK, exit_code);
}

TEST(framework_cli, run_a_basic_callback) {
  std::stringstream stream;
  framework::cli::SingleCommandApplication app_one("My App", "v0.0.1");
  app_one.set_output(&stream);

  bool callback_run = false;
  app_one.set_callback([&callback_run](Command) -> ExitCode {
    callback_run = true;
    return ExitCode::OK;
  });

  std::vector<std::string> args;
  auto exit_code = app_one.run(args);

  EXPECT_EQ("", stream.str());
  EXPECT_EQ(ExitCode::OK, exit_code);
  EXPECT_TRUE(callback_run);
}

TEST(framework_cli, print_output_from_in_a_command) {
  std::stringstream stream;
  framework::cli::SingleCommandApplication app_one("My App", "v0.0.1");
  app_one.set_output(&stream);

  app_one.set_callback([](Command command) -> ExitCode {
    command.write_line("This is a message");
    return ExitCode::OK;
  });

  std::vector<std::string> args;
  auto exit_code = app_one.run(args);

  EXPECT_EQ("This is a message\n", stream.str());
  EXPECT_EQ(ExitCode::OK, exit_code);
}

TEST(framework_cli, parse_with_an_argument) {
  std::stringstream stream;
  framework::cli::SingleCommandApplication app_one("My App", "v0.0.1");
  app_one.set_output(&stream);
  app_one.add_argument({"file", "A description of the file"});

  app_one.set_callback([](Command command) -> ExitCode {
    command.write_line("The file is " + command.arguments().at(0).string());
    return ExitCode::OK;
  });

  std::vector<std::string> args({"/tmp/some/file"});
  auto exit_code = app_one.run(args);

  EXPECT_EQ("The file is /tmp/some/file\n", stream.str());
  EXPECT_EQ(ExitCode::OK, exit_code);
}

TEST(framework_cli, parse_with_mutiple_aguments) {
  std::stringstream stream;
  framework::cli::SingleCommandApplication app_one("My App", "v0.0.1");
  app_one.set_output(&stream);
  app_one.add_argument({"file-one", "A description of the file"});
  app_one.add_argument({"file-two", "A description of the file"});

  app_one.set_callback([](Command command) -> ExitCode {
    command.write_line("The file is " + command.arguments().at(0).string() + " and " + command.arguments().at(1).string() + "");

    return ExitCode::OK;
  });

  std::vector<std::string> args({"/tmp/some/file", "/tmp/some/other/file"});
  auto exit_code = app_one.run(args);

  EXPECT_EQ("The file is /tmp/some/file and /tmp/some/other/file\n", stream.str());
  EXPECT_EQ(ExitCode::OK, exit_code);
}

TEST(framework_cli, parse_string_flag) {
  auto run_app = [](std::vector<std::string> args) {
    framework::cli::SingleCommandApplication app("My App", "v0.0.1");

    std::stringstream stream;
    app.set_output(&stream);

    app.add_flag({"file", 'f', "A description of the file"});
    app.set_callback([](Command command) -> ExitCode {
      command.write_line("The file is " + command.flags().at("file").string());

      return ExitCode::OK;
    });

    app.run(args);

    return stream.str();
  };

  std::string output;

  output = run_app({"--file", "/tmp/some/file"});
  EXPECT_EQ("The file is /tmp/some/file\n", output);

  output = run_app({"-f", "/tmp/some/file"});
  EXPECT_EQ("The file is /tmp/some/file\n", output);
}

TEST(framework_cli, parse_boolean_flag) {
  auto run_app = [](std::vector<std::string> args) {
    framework::cli::SingleCommandApplication app("My App", "v0.0.1");

    std::stringstream stream;
    app.set_output(&stream);

    app.add_flag({"verbose", 'v', "If you want to print output", framework::cli::Flag::Boolean});
    app.set_callback([](Command command) -> ExitCode {
      if (command.flags().at("verbose").boolean()) {
        command.write_line("Outputting some text!");
      } else {
        command.write_line("Not outputting some text!");
      }

      return ExitCode::OK;
    });

    app.run(args);

    return stream.str();
  };

  std::string output;

  output = run_app({"--verbose"});
  EXPECT_EQ("Outputting some text!\n", output);

  output = run_app({});
  EXPECT_EQ("Not outputting some text!\n", output);
}

TEST(framework_cli, parse_missing_arguments) {
  auto run_app = [](std::vector<std::string> args) {
    framework::cli::SingleCommandApplication app("My App", "v0.0.1");

    std::stringstream stream;
    app.set_output(&stream);

    app.add_argument({"path", "The file path"});
    app.set_callback([](Command command) -> ExitCode {
      auto path = command.arguments().at(0);
      if (path.empty()) {
        command.write_line("No path");
      } else {
        command.write_line("The path is " + path.string());
      }

      return ExitCode::OK;
    });

    app.run(args);

    return stream.str();
  };

  std::string output;

  output = run_app({});
  EXPECT_EQ("No path\n", output);

  output = run_app({"/tmp/path"});
  EXPECT_EQ("The path is /tmp/path\n", output);
}
