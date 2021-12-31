// Copyright 2021 Practically.io All rights reserved
//
// Use of this source is governed by a BSD-style
// licence that can be found in the LICENCE file or at
// https://www.practically.io/copyright/

#include <gtest/gtest.h>

#include <framework/string_split.hpp>

TEST(framework_string_split, split_some_strings) {
  auto parts = framework::string_split("some,string", ",");

  EXPECT_EQ(parts.size(), 2);
  EXPECT_EQ(parts.at(0), "some");
  EXPECT_EQ(parts.at(1), "string");
}

TEST(framework_string_split, splits_strings_on_multi_char_strings) {
  auto parts = framework::string_split("some//other//string", "//");

  EXPECT_EQ(parts.size(), 3);
  EXPECT_EQ(parts.at(0), "some");
  EXPECT_EQ(parts.at(1), "other");
  EXPECT_EQ(parts.at(2), "string");
}