
// Generated from ALang.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"
#include "ALangListener.h"


namespace parser::alang {

/**
 * This class provides an empty implementation of ALangListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ALangBaseListener : public ALangListener {
public:

  virtual void enterRoot(ALangParser::RootContext * /*ctx*/) override { }
  virtual void exitRoot(ALangParser::RootContext * /*ctx*/) override { }

  virtual void enterFunctionDeclaration(ALangParser::FunctionDeclarationContext * /*ctx*/) override { }
  virtual void exitFunctionDeclaration(ALangParser::FunctionDeclarationContext * /*ctx*/) override { }

  virtual void enterParameters(ALangParser::ParametersContext * /*ctx*/) override { }
  virtual void exitParameters(ALangParser::ParametersContext * /*ctx*/) override { }

  virtual void enterParameter(ALangParser::ParameterContext * /*ctx*/) override { }
  virtual void exitParameter(ALangParser::ParameterContext * /*ctx*/) override { }

  virtual void enterFunctionCall(ALangParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(ALangParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterFunctionCallExpression(ALangParser::FunctionCallExpressionContext * /*ctx*/) override { }
  virtual void exitFunctionCallExpression(ALangParser::FunctionCallExpressionContext * /*ctx*/) override { }

  virtual void enterArguments(ALangParser::ArgumentsContext * /*ctx*/) override { }
  virtual void exitArguments(ALangParser::ArgumentsContext * /*ctx*/) override { }

  virtual void enterBlockStatement(ALangParser::BlockStatementContext * /*ctx*/) override { }
  virtual void exitBlockStatement(ALangParser::BlockStatementContext * /*ctx*/) override { }

  virtual void enterInnerStatementList(ALangParser::InnerStatementListContext * /*ctx*/) override { }
  virtual void exitInnerStatementList(ALangParser::InnerStatementListContext * /*ctx*/) override { }

  virtual void enterInnerStatement(ALangParser::InnerStatementContext * /*ctx*/) override { }
  virtual void exitInnerStatement(ALangParser::InnerStatementContext * /*ctx*/) override { }

  virtual void enterVariableDeclaration(ALangParser::VariableDeclarationContext * /*ctx*/) override { }
  virtual void exitVariableDeclaration(ALangParser::VariableDeclarationContext * /*ctx*/) override { }

  virtual void enterVariableAssignment(ALangParser::VariableAssignmentContext * /*ctx*/) override { }
  virtual void exitVariableAssignment(ALangParser::VariableAssignmentContext * /*ctx*/) override { }

  virtual void enterReturnStatement(ALangParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(ALangParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterIfElseIfElseStatement(ALangParser::IfElseIfElseStatementContext * /*ctx*/) override { }
  virtual void exitIfElseIfElseStatement(ALangParser::IfElseIfElseStatementContext * /*ctx*/) override { }

  virtual void enterIfStatement(ALangParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(ALangParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterElseIfStatement(ALangParser::ElseIfStatementContext * /*ctx*/) override { }
  virtual void exitElseIfStatement(ALangParser::ElseIfStatementContext * /*ctx*/) override { }

  virtual void enterElseStatement(ALangParser::ElseStatementContext * /*ctx*/) override { }
  virtual void exitElseStatement(ALangParser::ElseStatementContext * /*ctx*/) override { }

  virtual void enterExpression(ALangParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(ALangParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterType(ALangParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(ALangParser::TypeContext * /*ctx*/) override { }

  virtual void enterAssignmentOperator(ALangParser::AssignmentOperatorContext * /*ctx*/) override { }
  virtual void exitAssignmentOperator(ALangParser::AssignmentOperatorContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace parser::alang
