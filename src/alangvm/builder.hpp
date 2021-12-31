// Copyright 2021 Practically.io All rights reserved
//
// Use of this source is governed by a BSD-style
// licence that can be found in the LICENCE file or at
// https://www.practically.io/copyright/
#pragma once

#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/Support/TargetSelect.h>

#include <map>
#include <memory>
#include <parser/alang.hpp>

#include "llvm/ExecutionEngine/Interpreter.h"
#include "llvm/IR/Module.h"

namespace alangvm {

struct AlangTestFunction {
  std::string name;
};

struct LLVMBuilderScope {
  std::string current_function_name;
  llvm::Function *current_function = nullptr;
  std::vector<llvm::BasicBlock *> block_stack;
  std::map<std::string, llvm::AllocaInst *> variables;
  std::map<std::string, llvm::Function *> functions;
};

class LLVMBuilderListener : public parser::alang::ALangBaseListener {
  std::unique_ptr<llvm::LLVMContext> m_context;
  std::unique_ptr<llvm::Module> m_module;
  std::unique_ptr<llvm::IRBuilder<>> m_builder;

  std::vector<LLVMBuilderScope> m_scopes;

 public:
  LLVMBuilderListener() {
    m_context = std::make_unique<llvm::LLVMContext>();
    m_module = std::make_unique<llvm::Module>("main", *m_context);
    m_builder = std::make_unique<llvm::IRBuilder<>>(*m_context);

    m_scopes.push_back(LLVMBuilderScope{});

    auto type = m_builder->getInt8PtrTy();
    auto printf_prototype = llvm::FunctionType::get(type, true);
    auto printf_fn = llvm::Function::Create(printf_prototype, llvm::Function::ExternalLinkage, "printf", m_module.get());
    m_scopes.back().functions.insert({"printf", printf_fn});
  }

  std::unique_ptr<llvm::Module> module() { return std::move(m_module); }

  void print() { m_module->print(llvm::outs(), nullptr); }

  std::vector<AlangTestFunction> test_functions() {
    std::vector<AlangTestFunction> tests;
    for (auto function : m_scopes.back().functions) {
      if (function.first.ends_with("_test")) {
        tests.push_back({function.first});
      }
    }

    return tests;
  }

  llvm::Function *get_current_function();
  llvm::Function *get_function(antlr4::tree::TerminalNode *);
  llvm::AllocaInst *get_variable(antlr4::tree::TerminalNode *);
  llvm::Type *get_type(parser::alang::ALangParser::TypeContext *);
  llvm::Value *evaluate_expression(parser::alang::ALangParser::ExpressionContext *);

  void enterFunctionDeclaration(parser::alang::ALangParser::FunctionDeclarationContext *) override;
  void exitFunctionDeclaration(parser::alang::ALangParser::FunctionDeclarationContext *) override;
  void enterReturnStatement(parser::alang::ALangParser::ReturnStatementContext *) override;

  void enterVariableDeclaration(parser::alang::ALangParser::VariableDeclarationContext *) override;

  void enterIfElseIfElseStatement(parser::alang::ALangParser::IfElseIfElseStatementContext *) override;
  void enterIfStatement(parser::alang::ALangParser::IfStatementContext *) override;
  void exitIfStatement(parser::alang::ALangParser::IfStatementContext *) override;
  void enterElseIfStatement(parser::alang::ALangParser::ElseIfStatementContext *) override;
  void exitElseIfStatement(parser::alang::ALangParser::ElseIfStatementContext *) override;
  void enterElseStatement(parser::alang::ALangParser::ElseStatementContext *) override;
  void exitElseStatement(parser::alang::ALangParser::ElseStatementContext *) override;
  void exitIfElseIfElseStatement(parser::alang::ALangParser::IfElseIfElseStatementContext *) override;

  void enterFunctionCall(parser::alang::ALangParser::FunctionCallContext *) override;
};

inline std::shared_ptr<LLVMBuilderListener> build(const std::string &file_path) {
  auto parser = parser::alang::Parser(file_path);

  auto listener = std::make_shared<LLVMBuilderListener>();
  parser.pass(listener.get());

  return listener;
}

}  // namespace alangvm
