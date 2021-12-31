// Copyright 2021 Practically.io All rights reserved
//
// Use of this source is governed by a BSD-style
// licence that can be found in the LICENCE file or at
// https://www.practically.io/copyright/

#include <gtest/gtest.h>

#include <filesystem>
#include <framework/logger.hpp>
#include <framework/read_file.hpp>

TEST(framework_logger, do_something_with_the_logger) {
  framework::logger::Logger logger("basic", "/tmp/logger.log");
  logger.info("This is some info");

  auto file = framework::read_file("/tmp/logger.log");
  EXPECT_EQ(file, "This is some info\n");
  std::filesystem::remove("/tmp/logger.log");
}

TEST(framework_logger, create_the_static_logger_with_a_name) {
  auto logger = std::make_shared<framework::logger::Logger>("basic", "/tmp/logger.log");
  framework::logger::Log::set("testing", logger);
  framework::logger::Log::get("testing")->info("this is some info from the global logger");

  auto file = framework::read_file("/tmp/logger.log");
  EXPECT_EQ(file, "this is some info from the global logger\n");
  std::filesystem::remove("/tmp/logger.log");
}
