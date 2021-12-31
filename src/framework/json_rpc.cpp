// Copyright 2021 Practically.io All rights reserved
//
// Use of this source is governed by a BSD-style
// licence that can be found in the LICENCE file or at
// https://www.practically.io/copyright/

#include "json_rpc.hpp"

#include <iostream>

using framework::json_rpc::Header;
using framework::json_rpc::Message;
using framework::json_rpc::Response;

const std::string HEADER_DELEMITRE = ": ";
const std::string RPC_EOL = "\r\n";

Header framework::json_rpc::parse_header(const std::string &header_line) {
  std::string key = header_line.substr(0, header_line.find(HEADER_DELEMITRE));
  return Header{key, header_line.substr(key.length() + HEADER_DELEMITRE.length())};
}

void framework::json_rpc::Response::write(nlohmann::json j) const {
  std::string response_content = j.dump();
  std::cout << "Content-Length: " << response_content.length() << RPC_EOL;
  std::cout << RPC_EOL;
  std::cout << j.dump() << RPC_EOL;
}

void framework::json_rpc::Context::write(nlohmann::json j) const {
  SuccessResponse success_response;
  success_response.result = j;
  if (message.id.has_value()) {
    success_response.id = message.id.value();
  }

  response.write(success_response);
};

void framework::json_rpc::server(std::function<void(const Context &)> callback) {
  Context context;
  context.response = Response{};
  framework::stdio::server([&](const std::string &line) {
    if (line.rfind('{', 0) == 0) {
      context.message = nlohmann::json::parse(line);
      callback(context);
      context = Context{};
      context.response = Response{};
    } else if (line.length() > 1) {
      auto header = framework::json_rpc::parse_header(line);
      context.headers.push_back(header);
    }
  });
}
