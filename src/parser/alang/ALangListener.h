
// Generated from ALang.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"
#include "ALangParser.h"


namespace parser::alang {

/**
 * This interface defines an abstract listener for a parse tree produced by ALangParser.
 */
class  ALangListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterRoot(ALangParser::RootContext *ctx) = 0;
  virtual void exitRoot(ALangParser::RootContext *ctx) = 0;

  virtual void enterFunctionDeclaration(ALangParser::FunctionDeclarationContext *ctx) = 0;
  virtual void exitFunctionDeclaration(ALangParser::FunctionDeclarationContext *ctx) = 0;

  virtual void enterParameters(ALangParser::ParametersContext *ctx) = 0;
  virtual void exitParameters(ALangParser::ParametersContext *ctx) = 0;

  virtual void enterParameter(ALangParser::ParameterContext *ctx) = 0;
  virtual void exitParameter(ALangParser::ParameterContext *ctx) = 0;

  virtual void enterFunctionCall(ALangParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(ALangParser::FunctionCallContext *ctx) = 0;

  virtual void enterFunctionCallExpression(ALangParser::FunctionCallExpressionContext *ctx) = 0;
  virtual void exitFunctionCallExpression(ALangParser::FunctionCallExpressionContext *ctx) = 0;

  virtual void enterArguments(ALangParser::ArgumentsContext *ctx) = 0;
  virtual void exitArguments(ALangParser::ArgumentsContext *ctx) = 0;

  virtual void enterBlockStatement(ALangParser::BlockStatementContext *ctx) = 0;
  virtual void exitBlockStatement(ALangParser::BlockStatementContext *ctx) = 0;

  virtual void enterInnerStatementList(ALangParser::InnerStatementListContext *ctx) = 0;
  virtual void exitInnerStatementList(ALangParser::InnerStatementListContext *ctx) = 0;

  virtual void enterInnerStatement(ALangParser::InnerStatementContext *ctx) = 0;
  virtual void exitInnerStatement(ALangParser::InnerStatementContext *ctx) = 0;

  virtual void enterVariableDeclaration(ALangParser::VariableDeclarationContext *ctx) = 0;
  virtual void exitVariableDeclaration(ALangParser::VariableDeclarationContext *ctx) = 0;

  virtual void enterVariableDeclarationFragment(ALangParser::VariableDeclarationFragmentContext *ctx) = 0;
  virtual void exitVariableDeclarationFragment(ALangParser::VariableDeclarationFragmentContext *ctx) = 0;

  virtual void enterVariableAssignment(ALangParser::VariableAssignmentContext *ctx) = 0;
  virtual void exitVariableAssignment(ALangParser::VariableAssignmentContext *ctx) = 0;

  virtual void enterVariableAssignmentFragment(ALangParser::VariableAssignmentFragmentContext *ctx) = 0;
  virtual void exitVariableAssignmentFragment(ALangParser::VariableAssignmentFragmentContext *ctx) = 0;

  virtual void enterReturnStatement(ALangParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(ALangParser::ReturnStatementContext *ctx) = 0;

  virtual void enterIfElseIfElseStatement(ALangParser::IfElseIfElseStatementContext *ctx) = 0;
  virtual void exitIfElseIfElseStatement(ALangParser::IfElseIfElseStatementContext *ctx) = 0;

  virtual void enterIfStatement(ALangParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(ALangParser::IfStatementContext *ctx) = 0;

  virtual void enterElseIfStatement(ALangParser::ElseIfStatementContext *ctx) = 0;
  virtual void exitElseIfStatement(ALangParser::ElseIfStatementContext *ctx) = 0;

  virtual void enterElseStatement(ALangParser::ElseStatementContext *ctx) = 0;
  virtual void exitElseStatement(ALangParser::ElseStatementContext *ctx) = 0;

  virtual void enterForStatement(ALangParser::ForStatementContext *ctx) = 0;
  virtual void exitForStatement(ALangParser::ForStatementContext *ctx) = 0;

  virtual void enterExpression(ALangParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(ALangParser::ExpressionContext *ctx) = 0;

  virtual void enterType(ALangParser::TypeContext *ctx) = 0;
  virtual void exitType(ALangParser::TypeContext *ctx) = 0;

  virtual void enterAssignmentOperator(ALangParser::AssignmentOperatorContext *ctx) = 0;
  virtual void exitAssignmentOperator(ALangParser::AssignmentOperatorContext *ctx) = 0;


};

}  // namespace parser::alang
