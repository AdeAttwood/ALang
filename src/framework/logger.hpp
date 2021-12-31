// Copyright 2021 Practically.io All rights reserved
//
// Use of this source is governed by a BSD-style
// licence that can be found in the LICENCE file or at
// https://www.practically.io/copyright/
#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <istream>
#include <map>
#include <memory>
#include <string>
#include <utility>

namespace framework::logger {

inline static const char *DEFAULT = "default";
// The log level to log. Some log message will be filtered out if the global log
// level is configured
enum Level {
  DEBUG,
  INFO,
  WARNING,
  ERROR,
};

// auto logger = Logger("default", &std::cout);
//
// std::ofstream stream("/tmp/file.log", std::ios::app);
// auto file_logger = Logger("file", &stream);
//
// auto another_logger = Logger("file", "/tmp/another-log.log");
//
class Logger {
  std::string m_id;
  std::ostream *m_stream;

 public:
  Logger(std::string id, std::ostream *stream) : m_id(std::move(id)), m_stream(stream){};
  Logger(std::string id, const std::string &file_path) : m_id(std::move(id)) {
    auto *stream = new std::ofstream;  // NOLINT(cppcoreguidelines-owning-memory)
    stream->open(file_path, std::ostream::app);
    m_stream = stream;
  }
  void log(Level, const std::string &message);
  void debug(const std::string &message) { log(DEBUG, message); }
  void info(const std::string &message) { log(INFO, message); }
  void error(const std::string &message) { log(ERROR, message); }
  void warning(const std::string &message) { log(WARNING, message); }
};

class Log {
  inline static std::map<std::string, std::shared_ptr<Logger>> m_loggers;

 public:
  Log() = delete;
  void operator=(Logger const &) = delete;

  static std::shared_ptr<Logger> get(const std::string &);
  static void set(const std::string &name, std::shared_ptr<Logger> &logger);
};

}  // namespace framework::logger

// Helper macros to make logg       ing more convenient
#define DEBUG(message) framework::logger::Log::get(framework::logger::DEFAULT)->debug(message)
