// Copyright 2021 Practically.io All rights reserved
//
// Use of this source is governed by a BSD-style
// licence that can be found in the LICENCE file or at
// https://www.practically.io/copyright/

#include <gtest/gtest.h>

#include <framework/inflector.hpp>
#include <map>
#include <string>

static const std::map<std::string, std::string> to_snake_case = {
    {"Some String", "some_string"},
    {"SomeString", "some_string"},
    {"some_string", "some_string"},
};

TEST(framework_inflector, to_snake_case) {
  for (auto const& [key, expected] : to_snake_case) {
    std::string source = key;
    framework::inflector::to_snake_case(source);
    EXPECT_EQ(source, expected);
  }
}