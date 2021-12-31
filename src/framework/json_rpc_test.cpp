// Copyright 2021 Practically.io All rights reserved
//
// Use of this source is governed by a BSD-style
// licence that can be found in the LICENCE file or at
// https://www.practically.io/copyright/

#include <gtest/gtest.h>

#include <framework/json_rpc.hpp>

using framework::json_rpc::Message;

TEST(framework_json_rpc, parse_headers) {
  auto header_one = framework::json_rpc::parse_header("Content-Length: 100");
  EXPECT_EQ(header_one.key, "Content-Length");
  EXPECT_EQ(header_one.value, "100");

  auto header_two = framework::json_rpc::parse_header("X-Header-Value: This is a value");
  EXPECT_EQ(header_two.key, "X-Header-Value");
  EXPECT_EQ(header_two.value, "This is a value");
}

TEST(framework_json_rpc, message_with_an_id) {
  std::string message_json = "{\"jsonrpc\":\"2.0\",\"id\": 1,\"method\":\"testing\",\"params\":{}}";
  auto message = static_cast<Message>(nlohmann::json::parse(message_json));
  EXPECT_EQ(message.id.value(), 1);
  EXPECT_EQ(message.method, "testing");
}

TEST(framework_json_rpc, message_without_an_id) {
  std::string message_json = "{\"jsonrpc\":\"2.0\",\"method\":\"testing\",\"params\":{}}";
  auto message = static_cast<Message>(nlohmann::json::parse(message_json));
  EXPECT_FALSE(message.id.has_value());
  EXPECT_EQ(message.method, "testing");
}