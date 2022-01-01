// Copyright 2021 Practically.io All rights reserved
//
// Use of this source is governed by a BSD-style
// licence that can be found in the LICENCE file or at
// https://www.practically.io/copyright/
#pragma once

#include "alang/ALangBaseListener.h"
#include "alang/ALangLexer.h"
#include "alang/ALangParser.h"
#include "antlr4-runtime.h"

namespace parser::alang {

class ErrorListener : public alang::ALangBaseListener {
 public:
  virtual void visitErrorNode(antlr4::tree::ErrorNode *node) override {
    auto a = 'b';
  }
};

class Parser {
  std::ifstream m_input_stream;
  antlr4::ANTLRInputStream m_input;
  alang::ALangLexer m_lexer;
  antlr4::CommonTokenStream m_token_stream;
  alang::ALangParser m_parser;

 public:
  explicit Parser(const std::string &file_path)
      : m_input_stream(file_path),
        m_input(antlr4::ANTLRInputStream(m_input_stream)),
        m_lexer(alang::ALangLexer(&m_input)),
        m_token_stream(antlr4::CommonTokenStream(&m_lexer)),
        m_parser(alang::ALangParser(&m_token_stream)) {}

  std::string to_string_tree() { return m_parser.root()->toStringTree(true); }

  void pass(alang::ALangBaseListener &listener) {
    antlr4::tree::ParseTree *tree = m_parser.root();
    antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
    m_parser.reset();
  }
};

}  // namespace parser::alang
