// Copyright 2021 Practically.io All rights reserved
//
// Use of this source is governed by a BSD-style
// licence that can be found in the LICENCE file or at
// https://www.practically.io/copyright/

#include "logger.hpp"

#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

namespace framework::logger {

void Logger::log(Level /*level*/, const std::string& message) { *m_stream << message << std::endl; }

void Log::set(const std::string& name, std::shared_ptr<Logger>& logger) { m_loggers[name] = logger; }
std::shared_ptr<Logger> Log::get(const std::string& name = "default") {
  if (!Log::m_loggers.contains(name)) {
    throw std::runtime_error("Logger '" + name + "' has not been registered");
  }

  return m_loggers[name];
}

}  // namespace framework::logger
