// Copyright 2021-2022 Practically.io All rights reserved
//
// Use of this source is governed by a BSD-style
// licence that can be found in the LICENCE file or at
// https://www.practically.io/copyright/

#include "builder.hpp"

namespace alangvm {

llvm::Function *LLVMBuilderListener::get_current_function() {
  if (m_scopes.empty()) {
    return nullptr;
  }

  return m_scopes.back().current_function;
}

llvm::Function *LLVMBuilderListener::get_function(antlr4::tree::TerminalNode *node) {
  auto name = node->getText();
  for (int i = m_scopes.size() - 1; i >= 0; i--) {
    if (m_scopes.at(i).functions.contains(name)) {
      return m_scopes.at(i).functions.at(name);
    }
  }

  // TODO(ade): Add better exceptions with the line and maybe some context
  throw std::runtime_error("Undefined function " + name);
}

llvm::AllocaInst *LLVMBuilderListener::get_variable(antlr4::tree::TerminalNode *node) {
  auto name = node->getText();
  for (int i = m_scopes.size() - 1; i >= 0; i--) {
    if (m_scopes.at(i).variables.contains(name)) {
      return m_scopes.at(i).variables.at(name);
    }
  }

  // TODO(ade): Add better exceptions with the line and maybe some context
  throw std::runtime_error("Undefined variable " + name);
}

llvm::Type *LLVMBuilderListener::get_type(parser::alang::ALangParser::TypeContext *type_context) {
  if (type_context->Int()) {
    return m_builder->getInt32Ty();
  }

  if (type_context->Boolean()) {
    return m_builder->getInt1Ty();
  }

  if (type_context->String()) {
    return m_builder->getInt8PtrTy();
  }

  if (type_context->Void()) {
    return m_builder->getVoidTy();
  }

  throw std::runtime_error("Invalid type");
}

llvm::Value *LLVMBuilderListener::evaluate_expression(parser::alang::ALangParser::ExpressionContext *expression) {
  auto variable = expression->ID();
  if (variable) {
    auto variable_value = get_variable(variable);
    return m_builder->CreateLoad(variable_value->getAllocatedType(), variable_value);
  }

  auto number = expression->NUMBER();
  if (number) {
    return llvm::ConstantInt::get(m_context, llvm::APInt(32, std::stoi(number->getText())));
  }

  auto boolean = expression->BooleanConstant();
  if (boolean) {
    auto boolean_value = boolean->getText() == "true" ? 1 : 0;
    return llvm::ConstantInt::get(m_context, llvm::APInt(1, boolean_value));
  }

  auto string = expression->DoubleQuoteString();
  if (string) {
    auto string_value = string->getText();
    string_value.erase(std::remove(string_value.begin(), string_value.end(), '\"'), string_value.end());
    return m_builder->CreateGlobalStringPtr(string_value);
  }

  auto function_call = expression->functionCallExpression();
  if (function_call) {
    auto function = get_function(function_call->ID());
    std::vector<llvm::Value *> arguments;
    auto argument_list = function_call->arguments();
    if (argument_list) {
      for (auto argument : argument_list->expression()) {
        arguments.push_back(evaluate_expression(argument));
      }

      return m_builder->CreateCall(function, arguments);
    } else {
      return m_builder->CreateCall(function);
    }
  }

  auto operation = expression->operation;
  if (operation) {
    auto text = operation->getText();
    auto left = evaluate_expression(expression->expression(0));
    auto right = evaluate_expression(expression->expression(1));

    if (text == "/") {
      return m_builder->CreateSDiv(left, right);
    }

    if (text == "*") {
      return m_builder->CreateMul(left, right);
    }

    if (text == "+") {
      return m_builder->CreateAdd(left, right);
    }

    if (text == "-") {
      return m_builder->CreateSub(left, right);
    }
  }

  auto test = expression->test;
  if (test) {
    auto text = test->getText();
    auto left = evaluate_expression(expression->expression(0));
    auto right = evaluate_expression(expression->expression(1));

    if (text == "==") {
      auto a = m_builder->CreateICmpEQ(left, right);
      auto b = a->getType();
      return a;
    }

    if (text == "!=") {
      return m_builder->CreateICmpNE(left, right);
    }

    if (text == ">") {
      return m_builder->CreateICmpSGT(left, right);
    }

    if (text == ">=") {
      return m_builder->CreateICmpSGE(left, right);
    }

    if (text == "<") {
      return m_builder->CreateICmpSLT(left, right);
    }

    if (text == "<=") {
      return m_builder->CreateICmpSLE(left, right);
    }

    if (text == "||") {
      return m_builder->CreateOr(left, right);
    }

    if (text == "&&") {
      return m_builder->CreateAnd(left, right);
    }
  }

  auto nested = expression->expression(0);
  auto length = expression->expression().size();
  if (nested && length == 1) {
    return evaluate_expression(nested);
  }

  throw std::runtime_error("Unable to evaluate expression");
}

void LLVMBuilderListener::enterFunctionDeclaration(parser::alang::ALangParser::FunctionDeclarationContext *context) {
  auto function_name = context->ID()->getText();
  auto parameter_list = context->parameters();
  auto return_type = get_type(context->type());

  llvm::FunctionType *prototype;
  if (parameter_list) {
    std::vector<llvm::Type *> parameters;
    for (auto parameter : parameter_list->parameter()) {
      parameters.push_back(get_type(parameter->type()));
    }

    prototype = llvm::FunctionType::get(return_type, parameters, false);
  } else {
    prototype = llvm::FunctionType::get(return_type, false);
  }

  auto function = llvm::Function::Create(prototype, llvm::Function::ExternalLinkage, function_name, m_module);
  llvm::BasicBlock *body = llvm::BasicBlock::Create(m_context, "body", function);
  m_builder->SetInsertPoint(body);

  m_scopes.back().functions.insert({function_name, function});
  m_scopes.push_back(LLVMBuilderScope{
      .current_function_name = function_name,
      .current_function = function});

  if (parameter_list) {
    std::vector<llvm::Type *> parameters;
    int index = 0;
    for (auto parameter : parameter_list->parameter()) {
      auto variable_name = parameter->ID()->getText();
      auto argument = function->getArg(index++);
      argument->setName(variable_name + "_param");

      auto allocation = m_builder->CreateAlloca(argument->getType(), nullptr, argument->getName());
      m_scopes.back().variables.insert({variable_name, allocation});
      m_builder->CreateStore(argument, allocation);
    }
  }
}

void LLVMBuilderListener::exitFunctionDeclaration(parser::alang::ALangParser::FunctionDeclarationContext *context) {
  if (context->type()->Void()) {
    m_builder->CreateRetVoid();
  }

  m_scopes.erase(m_scopes.end());
}

void LLVMBuilderListener::enterIfElseIfElseStatement(parser::alang::ALangParser::IfElseIfElseStatementContext *context) {
  m_scopes.push_back(LLVMBuilderScope{
      .current_function_name = m_scopes.back().current_function_name,
      .current_function = m_scopes.back().current_function,
  });

  m_scopes.back().block_stack.push_back(llvm::BasicBlock::Create(m_context));
  if (context->elseStatement()) {
    m_scopes.back().block_stack.push_back(llvm::BasicBlock::Create(m_context));
  }

  for (auto else_if : context->elseIfStatement()) {
    m_scopes.back().block_stack.push_back(llvm::BasicBlock::Create(m_context));
  }

  m_scopes.back().block_stack.push_back(llvm::BasicBlock::Create(m_context));
}

void LLVMBuilderListener::enterIfStatement(parser::alang::ALangParser::IfStatementContext *context) {
  auto my_block = m_scopes.back().block_stack.back();
  m_scopes.back().block_stack.erase(
      std::remove(m_scopes.back().block_stack.begin(), m_scopes.back().block_stack.end(), my_block),
      m_scopes.back().block_stack.end());

  auto value = evaluate_expression(context->expression());
  m_builder->CreateCondBr(value, my_block, m_scopes.back().block_stack.back());

  get_current_function()->getBasicBlockList().push_back(my_block);
  m_builder->SetInsertPoint(my_block);

  m_scopes.push_back(LLVMBuilderScope{
      .current_function_name = m_scopes.back().current_function_name,
      .current_function = m_scopes.back().current_function});
}

void LLVMBuilderListener::exitIfStatement(parser::alang::ALangParser::IfStatementContext *) {
  m_scopes.erase(m_scopes.end());
  m_builder->CreateBr(m_scopes.back().block_stack.front());
}

void LLVMBuilderListener::enterElseIfStatement(parser::alang::ALangParser::ElseIfStatementContext *context) {
  auto my_block = m_scopes.back().block_stack.back();
  m_scopes.back().block_stack.erase(
      std::remove(m_scopes.back().block_stack.begin(), m_scopes.back().block_stack.end(), my_block),
      m_scopes.back().block_stack.end());

  get_current_function()->getBasicBlockList().push_back(my_block);
  m_builder->SetInsertPoint(my_block);

  auto then_block = llvm::BasicBlock::Create(m_context, "elseifthen");

  auto value = evaluate_expression(context->expression());
  m_builder->CreateCondBr(value, then_block, m_scopes.back().block_stack.back());

  get_current_function()->getBasicBlockList().push_back(then_block);
  m_builder->SetInsertPoint(then_block);

  m_scopes.push_back(LLVMBuilderScope{
      .current_function_name = m_scopes.back().current_function_name,
      .current_function = m_scopes.back().current_function});
}

void LLVMBuilderListener::exitElseIfStatement(parser::alang::ALangParser::ElseIfStatementContext *) {
  m_scopes.erase(m_scopes.end());
  m_builder->CreateBr(m_scopes.back().block_stack.front());
}

void LLVMBuilderListener::enterElseStatement(parser::alang::ALangParser::ElseStatementContext *context) {
  auto my_block = m_scopes.back().block_stack.back();
  m_scopes.back().block_stack.erase(
      std::remove(m_scopes.back().block_stack.begin(), m_scopes.back().block_stack.end(), my_block),
      m_scopes.back().block_stack.end());

  get_current_function()->getBasicBlockList().push_back(my_block);
  m_builder->SetInsertPoint(my_block);

  m_scopes.push_back(LLVMBuilderScope{
      .current_function_name = m_scopes.back().current_function_name,
      .current_function = m_scopes.back().current_function});
}

void LLVMBuilderListener::exitElseStatement(parser::alang::ALangParser::ElseStatementContext *context) {
  m_scopes.erase(m_scopes.end());
  m_builder->CreateBr(m_scopes.back().block_stack.front());
}

void LLVMBuilderListener::exitIfElseIfElseStatement(parser::alang::ALangParser::IfElseIfElseStatementContext *) {
  auto end_block = m_scopes.back().block_stack.back();
  get_current_function()->getBasicBlockList().push_back(end_block);
  m_builder->SetInsertPoint(end_block);
  m_scopes.erase(m_scopes.end());
}

void LLVMBuilderListener::enterVariableDeclaration(parser::alang::ALangParser::VariableDeclarationContext *context) {
  auto variable_name = context->ID()->getText();
  auto type = get_type(context->type());
  auto allocation = m_builder->CreateAlloca(type, nullptr, variable_name);
  m_scopes.back().variables.insert({variable_name, allocation});

  auto variable_value = evaluate_expression(context->expression());
  if (variable_value) {
    m_builder->CreateStore(variable_value, allocation);
  }
}

void LLVMBuilderListener::enterVariableAssignment(parser::alang::ALangParser::VariableAssignmentContext *context) {
  auto allocation = get_variable(context->ID());
  auto variable_value = evaluate_expression(context->expression());
  m_builder->CreateStore(variable_value, allocation);
}

void LLVMBuilderListener::enterReturnStatement(parser::alang::ALangParser::ReturnStatementContext *context) {
  auto return_value = evaluate_expression(context->expression());
  if (return_value) {
    m_builder->CreateRet(return_value);
  }
}

void LLVMBuilderListener::enterFunctionCall(parser::alang::ALangParser::FunctionCallContext *context) {
  auto function = get_function(context->ID());
  std::vector<llvm::Value *> arguments;
  auto argument_list = context->arguments();
  if (argument_list) {
    for (auto argument : argument_list->expression()) {
      arguments.push_back(evaluate_expression(argument));
    }

    m_builder->CreateCall(function, arguments);
  } else {
    m_builder->CreateCall(function);
  }
}

}  // namespace alangvm
