// Copyright 2021 Practically.io All rights reserved
//
// Use of this source is governed by a BSD-style
// licence that can be found in the LICENCE file or at
// https://www.practically.io/copyright/
#pragma once

#include <functional>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include "stdio.hpp"

// https://www.jsonrpc.org/specification
namespace framework::json_rpc {

// A header object for storing HTTP style headers that are split by the
// delimiter of ": ".
struct Header {
  std::string key;
  std::string value;
};

struct Message {
  std::optional<int> id;
  std::string version;
  std::string method;
  nlohmann::json params;
};

struct SuccessResponse {
  std::optional<int> id;
  nlohmann::json result;
};

class Response {
 public:
  void write(nlohmann::json) const;
};

struct Context {
  std::vector<Header> headers;
  Message message;
  Response response;
  void write(nlohmann::json j) const;
};

Header parse_header(const std::string &header_line);
void server(std::function<void(const Context &)> callback);

}  // namespace framework::json_rpc

namespace nlohmann {
void from_json(const json &j, framework::json_rpc::Message &message);
void to_json(json &j, const framework::json_rpc::Message &mesasge);
void from_json(const json &j, framework::json_rpc::SuccessResponse &success_response);
void to_json(json &j, const framework::json_rpc::SuccessResponse &success_mesasge);

inline void from_json(const json &j, framework::json_rpc::Message &message) {
  if (j.contains("jsonrpc")) {
    message.version = j.at("jsonrpc").get<std::string>();
  }
  if (j.contains("id")) {
    message.id = j.at("id").get<int>();
  };

  if (j.contains("method")) {
    message.method = j.at("method").get<std::string>();
  }

  if (j.contains("params")) {
    message.params = j.at("params");
  }
}

inline void to_json(json &j, const framework::json_rpc::Message &mesasge) {
  j = json::object();
  if (mesasge.id.has_value()) {
    j["id"] = mesasge.id.value();
  }
  j["jsonrpc"] = mesasge.version;
  j["method"] = mesasge.method;
}

inline void from_json(const json &j, framework::json_rpc::SuccessResponse &success_response) {
  if (j.contains("id")) {
    success_response.id = j.at("id").get<int>();
  };
  success_response.result = j.at("result");
}

inline void to_json(json &j, const framework::json_rpc::SuccessResponse &success_response) {
  j = json::object();
  if (success_response.id.has_value()) {
    j["id"] = success_response.id.value();
  }
  j["result"] = success_response.result;
}
}  // namespace nlohmann
