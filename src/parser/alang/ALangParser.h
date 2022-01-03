
// Generated from ALang.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"


namespace parser::alang {


class  ALangParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, DocumentationComment = 14, 
    Comment = 15, Return = 16, Function_ = 17, For = 18, If = 19, Else = 20, 
    ElseIf = 21, Int = 22, Void = 23, String = 24, Boolean = 25, BooleanConstant = 26, 
    ID = 27, NUMBER = 28, OpenCurlyBracket = 29, CloseCurlyBracket = 30, 
    OpenRoundBracket = 31, CloseRoundBracket = 32, OpenSquareBracket = 33, 
    CloseSquareBracket = 34, Colon = 35, SemiColon = 36, Equals = 37, DoubleQuote = 38, 
    DoubleQuoteString = 39, SPACE = 40
  };

  enum {
    RuleRoot = 0, RuleFunctionDeclaration = 1, RuleParameters = 2, RuleParameter = 3, 
    RuleFunctionCall = 4, RuleFunctionCallExpression = 5, RuleArguments = 6, 
    RuleBlockStatement = 7, RuleInnerStatementList = 8, RuleInnerStatement = 9, 
    RuleVariableDeclaration = 10, RuleVariableDeclarationFragment = 11, 
    RuleVariableAssignment = 12, RuleVariableAssignmentFragment = 13, RuleReturnStatement = 14, 
    RuleIfElseIfElseStatement = 15, RuleIfStatement = 16, RuleElseIfStatement = 17, 
    RuleElseStatement = 18, RuleForStatement = 19, RuleExpression = 20, 
    RuleType = 21, RuleAssignmentOperator = 22
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
  class VariableDeclarationFragmentContext;
  class VariableAssignmentContext;
  class VariableAssignmentFragmentContext;
  class ReturnStatementContext;
  class IfElseIfElseStatementContext;
  class IfStatementContext;
  class ElseIfStatementContext;
  class ElseStatementContext;
  class ForStatementContext;
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
    ForStatementContext *forStatement();
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

  class  VariableDeclarationFragmentContext : public antlr4::ParserRuleContext {
  public:
    VariableDeclarationFragmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *Equals();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VariableDeclarationFragmentContext* variableDeclarationFragment();

  class  VariableAssignmentContext : public antlr4::ParserRuleContext {
  public:
    VariableAssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    AssignmentOperatorContext *assignmentOperator();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SemiColon();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VariableAssignmentContext* variableAssignment();

  class  VariableAssignmentFragmentContext : public antlr4::ParserRuleContext {
  public:
    VariableAssignmentFragmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    AssignmentOperatorContext *assignmentOperator();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VariableAssignmentFragmentContext* variableAssignmentFragment();

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

  class  ForStatementContext : public antlr4::ParserRuleContext {
  public:
    ALangParser::ExpressionContext *test = nullptr;
    ALangParser::ExpressionContext *increment = nullptr;
    ForStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *For();
    antlr4::tree::TerminalNode *OpenRoundBracket();
    std::vector<antlr4::tree::TerminalNode *> SemiColon();
    antlr4::tree::TerminalNode* SemiColon(size_t i);
    antlr4::tree::TerminalNode *CloseRoundBracket();
    BlockStatementContext *blockStatement();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    VariableDeclarationFragmentContext *variableDeclarationFragment();
    VariableAssignmentFragmentContext *variableAssignmentFragment();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ForStatementContext* forStatement();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *operation = nullptr;
    antlr4::Token *test = nullptr;
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OpenRoundBracket();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *CloseRoundBracket();
    FunctionCallExpressionContext *functionCallExpression();
    VariableAssignmentFragmentContext *variableAssignmentFragment();
    antlr4::tree::TerminalNode *BooleanConstant();
    antlr4::tree::TerminalNode *DoubleQuoteString();
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *ID();

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
