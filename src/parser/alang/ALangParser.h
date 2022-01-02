
// Generated from ALang.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"


namespace parser::alang {


class  ALangParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, DocumentationComment = 6, 
    Comment = 7, Return = 8, Function_ = 9, If = 10, Else = 11, ElseIf = 12, 
    Int = 13, Void = 14, String = 15, Boolean = 16, BooleanConstant = 17, 
    ID = 18, NUMBER = 19, OpenCurlyBracket = 20, CloseCurlyBracket = 21, 
    OpenRoundBracket = 22, CloseRoundBracket = 23, OpenSquareBracket = 24, 
    CloseSquareBracket = 25, Colon = 26, SemiColon = 27, Equals = 28, DoubleQuote = 29, 
    DoubleQuoteString = 30, SPACE = 31
  };

  enum {
    RuleRoot = 0, RuleFunctionDeclaration = 1, RuleParameters = 2, RuleParameter = 3, 
    RuleFunctionCall = 4, RuleFunctionCallExpression = 5, RuleArguments = 6, 
    RuleBlockStatement = 7, RuleInnerStatementList = 8, RuleInnerStatement = 9, 
    RuleVariableDeclaration = 10, RuleVariableAssignment = 11, RuleReturnStatement = 12, 
    RuleIfElseIfElseStatement = 13, RuleIfStatement = 14, RuleElseIfStatement = 15, 
    RuleElseStatement = 16, RuleExpression = 17, RuleType = 18, RuleAssignmentOperator = 19
  };

  explicit ALangParser(antlr4::TokenStream *input);
  ~ALangParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class RootContext;
  class FunctionDeclarationContext;
  class ParametersContext;
  class ParameterContext;
  class FunctionCallContext;
  class FunctionCallExpressionContext;
  class ArgumentsContext;
  class BlockStatementContext;
  class InnerStatementListContext;
  class InnerStatementContext;
  class VariableDeclarationContext;
  class VariableAssignmentContext;
  class ReturnStatementContext;
  class IfElseIfElseStatementContext;
  class IfStatementContext;
  class ElseIfStatementContext;
  class ElseStatementContext;
  class ExpressionContext;
  class TypeContext;
  class AssignmentOperatorContext; 

  class  RootContext : public antlr4::ParserRuleContext {
  public:
    RootContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    InnerStatementListContext *innerStatementList();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RootContext* root();

  class  FunctionDeclarationContext : public antlr4::ParserRuleContext {
  public:
    FunctionDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Function_();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *OpenRoundBracket();
    antlr4::tree::TerminalNode *CloseRoundBracket();
    antlr4::tree::TerminalNode *Colon();
    TypeContext *type();
    BlockStatementContext *blockStatement();
    std::vector<antlr4::tree::TerminalNode *> DocumentationComment();
    antlr4::tree::TerminalNode* DocumentationComment(size_t i);
    ParametersContext *parameters();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunctionDeclarationContext* functionDeclaration();

  class  ParametersContext : public antlr4::ParserRuleContext {
  public:
    ParametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ParameterContext *> parameter();
    ParameterContext* parameter(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ParametersContext* parameters();

  class  ParameterContext : public antlr4::ParserRuleContext {
  public:
    ParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ParameterContext* parameter();

  class  FunctionCallContext : public antlr4::ParserRuleContext {
  public:
    FunctionCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *OpenRoundBracket();
    antlr4::tree::TerminalNode *CloseRoundBracket();
    antlr4::tree::TerminalNode *SemiColon();
    ArgumentsContext *arguments();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunctionCallContext* functionCall();

  class  FunctionCallExpressionContext : public antlr4::ParserRuleContext {
  public:
    FunctionCallExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *OpenRoundBracket();
    antlr4::tree::TerminalNode *CloseRoundBracket();
    ArgumentsContext *arguments();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunctionCallExpressionContext* functionCallExpression();

  class  ArgumentsContext : public antlr4::ParserRuleContext {
  public:
    ArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ArgumentsContext* arguments();

  class  BlockStatementContext : public antlr4::ParserRuleContext {
  public:
    BlockStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OpenCurlyBracket();
    InnerStatementListContext *innerStatementList();
    antlr4::tree::TerminalNode *CloseCurlyBracket();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BlockStatementContext* blockStatement();

  class  InnerStatementListContext : public antlr4::ParserRuleContext {
  public:
    InnerStatementListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<InnerStatementContext *> innerStatement();
    InnerStatementContext* innerStatement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  InnerStatementListContext* innerStatementList();

  class  InnerStatementContext : public antlr4::ParserRuleContext {
  public:
    InnerStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionDeclarationContext *functionDeclaration();
    FunctionCallContext *functionCall();
    IfElseIfElseStatementContext *ifElseIfElseStatement();
    ReturnStatementContext *returnStatement();
    VariableDeclarationContext *variableDeclaration();
    VariableAssignmentContext *variableAssignment();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  InnerStatementContext* innerStatement();

  class  VariableDeclarationContext : public antlr4::ParserRuleContext {
  public:
    VariableDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *Equals();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SemiColon();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VariableDeclarationContext* variableDeclaration();

  class  VariableAssignmentContext : public antlr4::ParserRuleContext {
  public:
    VariableAssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *Equals();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SemiColon();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VariableAssignmentContext* variableAssignment();

  class  ReturnStatementContext : public antlr4::ParserRuleContext {
  public:
    ReturnStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Return();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SemiColon();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ReturnStatementContext* returnStatement();

  class  IfElseIfElseStatementContext : public antlr4::ParserRuleContext {
  public:
    IfElseIfElseStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IfStatementContext *ifStatement();
    std::vector<ElseIfStatementContext *> elseIfStatement();
    ElseIfStatementContext* elseIfStatement(size_t i);
    ElseStatementContext *elseStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IfElseIfElseStatementContext* ifElseIfElseStatement();

  class  IfStatementContext : public antlr4::ParserRuleContext {
  public:
    IfStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *If();
    antlr4::tree::TerminalNode *OpenRoundBracket();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *CloseRoundBracket();
    BlockStatementContext *blockStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IfStatementContext* ifStatement();

  class  ElseIfStatementContext : public antlr4::ParserRuleContext {
  public:
    ElseIfStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ElseIf();
    antlr4::tree::TerminalNode *OpenRoundBracket();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *CloseRoundBracket();
    BlockStatementContext *blockStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ElseIfStatementContext* elseIfStatement();

  class  ElseStatementContext : public antlr4::ParserRuleContext {
  public:
    ElseStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Else();
    BlockStatementContext *blockStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ElseStatementContext* elseStatement();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *op = nullptr;
    antlr4::Token *test = nullptr;
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionCallExpressionContext *functionCallExpression();
    antlr4::tree::TerminalNode *ID();
    AssignmentOperatorContext *assignmentOperator();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *BooleanConstant();
    antlr4::tree::TerminalNode *DoubleQuoteString();
    antlr4::tree::TerminalNode *NUMBER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Int();
    antlr4::tree::TerminalNode *Boolean();
    antlr4::tree::TerminalNode *String();
    antlr4::tree::TerminalNode *Void();
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TypeContext* type();

  class  AssignmentOperatorContext : public antlr4::ParserRuleContext {
  public:
    AssignmentOperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Equals();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AssignmentOperatorContext* assignmentOperator();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace parser::alang
