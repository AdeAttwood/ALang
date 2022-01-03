
// Generated from ALang.g4 by ANTLR 4.9


#include "ALangListener.h"

#include "ALangParser.h"


using namespace antlrcpp;
using namespace parser::alang;
using namespace antlr4;

ALangParser::ALangParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ALangParser::~ALangParser() {
  delete _interpreter;
}

std::string ALangParser::getGrammarFileName() const {
  return "ALang.g4";
}

const std::vector<std::string>& ALangParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ALangParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- RootContext ------------------------------------------------------------------

ALangParser::RootContext::RootContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ALangParser::InnerStatementListContext* ALangParser::RootContext::innerStatementList() {
  return getRuleContext<ALangParser::InnerStatementListContext>(0);
}

tree::TerminalNode* ALangParser::RootContext::EOF() {
  return getToken(ALangParser::EOF, 0);
}


size_t ALangParser::RootContext::getRuleIndex() const {
  return ALangParser::RuleRoot;
}

void ALangParser::RootContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRoot(this);
}

void ALangParser::RootContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRoot(this);
}

ALangParser::RootContext* ALangParser::root() {
  RootContext *_localctx = _tracker.createInstance<RootContext>(_ctx, getState());
  enterRule(_localctx, 0, ALangParser::RuleRoot);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(46);
    innerStatementList();
    setState(47);
    match(ALangParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclarationContext ------------------------------------------------------------------

ALangParser::FunctionDeclarationContext::FunctionDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ALangParser::FunctionDeclarationContext::Function_() {
  return getToken(ALangParser::Function_, 0);
}

tree::TerminalNode* ALangParser::FunctionDeclarationContext::ID() {
  return getToken(ALangParser::ID, 0);
}

tree::TerminalNode* ALangParser::FunctionDeclarationContext::OpenRoundBracket() {
  return getToken(ALangParser::OpenRoundBracket, 0);
}

tree::TerminalNode* ALangParser::FunctionDeclarationContext::CloseRoundBracket() {
  return getToken(ALangParser::CloseRoundBracket, 0);
}

tree::TerminalNode* ALangParser::FunctionDeclarationContext::Colon() {
  return getToken(ALangParser::Colon, 0);
}

ALangParser::TypeContext* ALangParser::FunctionDeclarationContext::type() {
  return getRuleContext<ALangParser::TypeContext>(0);
}

ALangParser::BlockStatementContext* ALangParser::FunctionDeclarationContext::blockStatement() {
  return getRuleContext<ALangParser::BlockStatementContext>(0);
}

std::vector<tree::TerminalNode *> ALangParser::FunctionDeclarationContext::DocumentationComment() {
  return getTokens(ALangParser::DocumentationComment);
}

tree::TerminalNode* ALangParser::FunctionDeclarationContext::DocumentationComment(size_t i) {
  return getToken(ALangParser::DocumentationComment, i);
}

ALangParser::ParametersContext* ALangParser::FunctionDeclarationContext::parameters() {
  return getRuleContext<ALangParser::ParametersContext>(0);
}


size_t ALangParser::FunctionDeclarationContext::getRuleIndex() const {
  return ALangParser::RuleFunctionDeclaration;
}

void ALangParser::FunctionDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDeclaration(this);
}

void ALangParser::FunctionDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDeclaration(this);
}

ALangParser::FunctionDeclarationContext* ALangParser::functionDeclaration() {
  FunctionDeclarationContext *_localctx = _tracker.createInstance<FunctionDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 2, ALangParser::RuleFunctionDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(52);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ALangParser::DocumentationComment) {
      setState(49);
      match(ALangParser::DocumentationComment);
      setState(54);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(55);
    match(ALangParser::Function_);
    setState(56);
    match(ALangParser::ID);
    setState(57);
    match(ALangParser::OpenRoundBracket);
    setState(59);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ALangParser::Int)
      | (1ULL << ALangParser::Void)
      | (1ULL << ALangParser::String)
      | (1ULL << ALangParser::Boolean)
      | (1ULL << ALangParser::ID))) != 0)) {
      setState(58);
      parameters();
    }
    setState(61);
    match(ALangParser::CloseRoundBracket);
    setState(62);
    match(ALangParser::Colon);
    setState(63);
    type();
    setState(64);
    blockStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

ALangParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ALangParser::ParameterContext *> ALangParser::ParametersContext::parameter() {
  return getRuleContexts<ALangParser::ParameterContext>();
}

ALangParser::ParameterContext* ALangParser::ParametersContext::parameter(size_t i) {
  return getRuleContext<ALangParser::ParameterContext>(i);
}


size_t ALangParser::ParametersContext::getRuleIndex() const {
  return ALangParser::RuleParameters;
}

void ALangParser::ParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameters(this);
}

void ALangParser::ParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameters(this);
}

ALangParser::ParametersContext* ALangParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 4, ALangParser::RuleParameters);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(66);
    parameter();
    setState(71);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ALangParser::T__0) {
      setState(67);
      match(ALangParser::T__0);
      setState(68);
      parameter();
      setState(73);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterContext ------------------------------------------------------------------

ALangParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ALangParser::TypeContext* ALangParser::ParameterContext::type() {
  return getRuleContext<ALangParser::TypeContext>(0);
}

tree::TerminalNode* ALangParser::ParameterContext::ID() {
  return getToken(ALangParser::ID, 0);
}


size_t ALangParser::ParameterContext::getRuleIndex() const {
  return ALangParser::RuleParameter;
}

void ALangParser::ParameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter(this);
}

void ALangParser::ParameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter(this);
}

ALangParser::ParameterContext* ALangParser::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 6, ALangParser::RuleParameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(74);
    type();
    setState(75);
    match(ALangParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallContext ------------------------------------------------------------------

ALangParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ALangParser::FunctionCallContext::ID() {
  return getToken(ALangParser::ID, 0);
}

tree::TerminalNode* ALangParser::FunctionCallContext::OpenRoundBracket() {
  return getToken(ALangParser::OpenRoundBracket, 0);
}

tree::TerminalNode* ALangParser::FunctionCallContext::CloseRoundBracket() {
  return getToken(ALangParser::CloseRoundBracket, 0);
}

tree::TerminalNode* ALangParser::FunctionCallContext::SemiColon() {
  return getToken(ALangParser::SemiColon, 0);
}

ALangParser::ArgumentsContext* ALangParser::FunctionCallContext::arguments() {
  return getRuleContext<ALangParser::ArgumentsContext>(0);
}


size_t ALangParser::FunctionCallContext::getRuleIndex() const {
  return ALangParser::RuleFunctionCall;
}

void ALangParser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}

void ALangParser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}

ALangParser::FunctionCallContext* ALangParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 8, ALangParser::RuleFunctionCall);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(77);
    match(ALangParser::ID);
    setState(78);
    match(ALangParser::OpenRoundBracket);
    setState(80);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ALangParser::BooleanConstant)
      | (1ULL << ALangParser::ID)
      | (1ULL << ALangParser::NUMBER)
      | (1ULL << ALangParser::OpenRoundBracket)
      | (1ULL << ALangParser::DoubleQuoteString))) != 0)) {
      setState(79);
      arguments();
    }
    setState(82);
    match(ALangParser::CloseRoundBracket);
    setState(83);
    match(ALangParser::SemiColon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallExpressionContext ------------------------------------------------------------------

ALangParser::FunctionCallExpressionContext::FunctionCallExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ALangParser::FunctionCallExpressionContext::ID() {
  return getToken(ALangParser::ID, 0);
}

tree::TerminalNode* ALangParser::FunctionCallExpressionContext::OpenRoundBracket() {
  return getToken(ALangParser::OpenRoundBracket, 0);
}

tree::TerminalNode* ALangParser::FunctionCallExpressionContext::CloseRoundBracket() {
  return getToken(ALangParser::CloseRoundBracket, 0);
}

ALangParser::ArgumentsContext* ALangParser::FunctionCallExpressionContext::arguments() {
  return getRuleContext<ALangParser::ArgumentsContext>(0);
}


size_t ALangParser::FunctionCallExpressionContext::getRuleIndex() const {
  return ALangParser::RuleFunctionCallExpression;
}

void ALangParser::FunctionCallExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallExpression(this);
}

void ALangParser::FunctionCallExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallExpression(this);
}

ALangParser::FunctionCallExpressionContext* ALangParser::functionCallExpression() {
  FunctionCallExpressionContext *_localctx = _tracker.createInstance<FunctionCallExpressionContext>(_ctx, getState());
  enterRule(_localctx, 10, ALangParser::RuleFunctionCallExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(85);
    match(ALangParser::ID);
    setState(86);
    match(ALangParser::OpenRoundBracket);
    setState(88);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ALangParser::BooleanConstant)
      | (1ULL << ALangParser::ID)
      | (1ULL << ALangParser::NUMBER)
      | (1ULL << ALangParser::OpenRoundBracket)
      | (1ULL << ALangParser::DoubleQuoteString))) != 0)) {
      setState(87);
      arguments();
    }
    setState(90);
    match(ALangParser::CloseRoundBracket);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

ALangParser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ALangParser::ExpressionContext *> ALangParser::ArgumentsContext::expression() {
  return getRuleContexts<ALangParser::ExpressionContext>();
}

ALangParser::ExpressionContext* ALangParser::ArgumentsContext::expression(size_t i) {
  return getRuleContext<ALangParser::ExpressionContext>(i);
}


size_t ALangParser::ArgumentsContext::getRuleIndex() const {
  return ALangParser::RuleArguments;
}

void ALangParser::ArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArguments(this);
}

void ALangParser::ArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArguments(this);
}

ALangParser::ArgumentsContext* ALangParser::arguments() {
  ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 12, ALangParser::RuleArguments);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(92);
    expression(0);
    setState(97);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ALangParser::T__0) {
      setState(93);
      match(ALangParser::T__0);
      setState(94);
      expression(0);
      setState(99);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockStatementContext ------------------------------------------------------------------

ALangParser::BlockStatementContext::BlockStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ALangParser::BlockStatementContext::OpenCurlyBracket() {
  return getToken(ALangParser::OpenCurlyBracket, 0);
}

ALangParser::InnerStatementListContext* ALangParser::BlockStatementContext::innerStatementList() {
  return getRuleContext<ALangParser::InnerStatementListContext>(0);
}

tree::TerminalNode* ALangParser::BlockStatementContext::CloseCurlyBracket() {
  return getToken(ALangParser::CloseCurlyBracket, 0);
}


size_t ALangParser::BlockStatementContext::getRuleIndex() const {
  return ALangParser::RuleBlockStatement;
}

void ALangParser::BlockStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockStatement(this);
}

void ALangParser::BlockStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockStatement(this);
}

ALangParser::BlockStatementContext* ALangParser::blockStatement() {
  BlockStatementContext *_localctx = _tracker.createInstance<BlockStatementContext>(_ctx, getState());
  enterRule(_localctx, 14, ALangParser::RuleBlockStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(100);
    match(ALangParser::OpenCurlyBracket);
    setState(101);
    innerStatementList();
    setState(102);
    match(ALangParser::CloseCurlyBracket);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InnerStatementListContext ------------------------------------------------------------------

ALangParser::InnerStatementListContext::InnerStatementListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ALangParser::InnerStatementContext *> ALangParser::InnerStatementListContext::innerStatement() {
  return getRuleContexts<ALangParser::InnerStatementContext>();
}

ALangParser::InnerStatementContext* ALangParser::InnerStatementListContext::innerStatement(size_t i) {
  return getRuleContext<ALangParser::InnerStatementContext>(i);
}


size_t ALangParser::InnerStatementListContext::getRuleIndex() const {
  return ALangParser::RuleInnerStatementList;
}

void ALangParser::InnerStatementListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInnerStatementList(this);
}

void ALangParser::InnerStatementListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInnerStatementList(this);
}

ALangParser::InnerStatementListContext* ALangParser::innerStatementList() {
  InnerStatementListContext *_localctx = _tracker.createInstance<InnerStatementListContext>(_ctx, getState());
  enterRule(_localctx, 16, ALangParser::RuleInnerStatementList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(107);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ALangParser::DocumentationComment)
      | (1ULL << ALangParser::Return)
      | (1ULL << ALangParser::Function_)
      | (1ULL << ALangParser::For)
      | (1ULL << ALangParser::If)
      | (1ULL << ALangParser::Int)
      | (1ULL << ALangParser::Void)
      | (1ULL << ALangParser::String)
      | (1ULL << ALangParser::Boolean)
      | (1ULL << ALangParser::ID))) != 0)) {
      setState(104);
      innerStatement();
      setState(109);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InnerStatementContext ------------------------------------------------------------------

ALangParser::InnerStatementContext::InnerStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ALangParser::FunctionDeclarationContext* ALangParser::InnerStatementContext::functionDeclaration() {
  return getRuleContext<ALangParser::FunctionDeclarationContext>(0);
}

ALangParser::FunctionCallContext* ALangParser::InnerStatementContext::functionCall() {
  return getRuleContext<ALangParser::FunctionCallContext>(0);
}

ALangParser::IfElseIfElseStatementContext* ALangParser::InnerStatementContext::ifElseIfElseStatement() {
  return getRuleContext<ALangParser::IfElseIfElseStatementContext>(0);
}

ALangParser::ForStatementContext* ALangParser::InnerStatementContext::forStatement() {
  return getRuleContext<ALangParser::ForStatementContext>(0);
}

ALangParser::ReturnStatementContext* ALangParser::InnerStatementContext::returnStatement() {
  return getRuleContext<ALangParser::ReturnStatementContext>(0);
}

ALangParser::VariableDeclarationContext* ALangParser::InnerStatementContext::variableDeclaration() {
  return getRuleContext<ALangParser::VariableDeclarationContext>(0);
}

ALangParser::VariableAssignmentContext* ALangParser::InnerStatementContext::variableAssignment() {
  return getRuleContext<ALangParser::VariableAssignmentContext>(0);
}


size_t ALangParser::InnerStatementContext::getRuleIndex() const {
  return ALangParser::RuleInnerStatement;
}

void ALangParser::InnerStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInnerStatement(this);
}

void ALangParser::InnerStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInnerStatement(this);
}

ALangParser::InnerStatementContext* ALangParser::innerStatement() {
  InnerStatementContext *_localctx = _tracker.createInstance<InnerStatementContext>(_ctx, getState());
  enterRule(_localctx, 18, ALangParser::RuleInnerStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(117);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(110);
      functionDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(111);
      functionCall();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(112);
      ifElseIfElseStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(113);
      forStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(114);
      returnStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(115);
      variableDeclaration();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(116);
      variableAssignment();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationContext ------------------------------------------------------------------

ALangParser::VariableDeclarationContext::VariableDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ALangParser::TypeContext* ALangParser::VariableDeclarationContext::type() {
  return getRuleContext<ALangParser::TypeContext>(0);
}

tree::TerminalNode* ALangParser::VariableDeclarationContext::ID() {
  return getToken(ALangParser::ID, 0);
}

tree::TerminalNode* ALangParser::VariableDeclarationContext::Equals() {
  return getToken(ALangParser::Equals, 0);
}

ALangParser::ExpressionContext* ALangParser::VariableDeclarationContext::expression() {
  return getRuleContext<ALangParser::ExpressionContext>(0);
}

tree::TerminalNode* ALangParser::VariableDeclarationContext::SemiColon() {
  return getToken(ALangParser::SemiColon, 0);
}


size_t ALangParser::VariableDeclarationContext::getRuleIndex() const {
  return ALangParser::RuleVariableDeclaration;
}

void ALangParser::VariableDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableDeclaration(this);
}

void ALangParser::VariableDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableDeclaration(this);
}

ALangParser::VariableDeclarationContext* ALangParser::variableDeclaration() {
  VariableDeclarationContext *_localctx = _tracker.createInstance<VariableDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 20, ALangParser::RuleVariableDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(119);
    type();
    setState(120);
    match(ALangParser::ID);
    setState(121);
    match(ALangParser::Equals);
    setState(122);
    expression(0);
    setState(123);
    match(ALangParser::SemiColon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationFragmentContext ------------------------------------------------------------------

ALangParser::VariableDeclarationFragmentContext::VariableDeclarationFragmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ALangParser::TypeContext* ALangParser::VariableDeclarationFragmentContext::type() {
  return getRuleContext<ALangParser::TypeContext>(0);
}

tree::TerminalNode* ALangParser::VariableDeclarationFragmentContext::ID() {
  return getToken(ALangParser::ID, 0);
}

tree::TerminalNode* ALangParser::VariableDeclarationFragmentContext::Equals() {
  return getToken(ALangParser::Equals, 0);
}

ALangParser::ExpressionContext* ALangParser::VariableDeclarationFragmentContext::expression() {
  return getRuleContext<ALangParser::ExpressionContext>(0);
}


size_t ALangParser::VariableDeclarationFragmentContext::getRuleIndex() const {
  return ALangParser::RuleVariableDeclarationFragment;
}

void ALangParser::VariableDeclarationFragmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableDeclarationFragment(this);
}

void ALangParser::VariableDeclarationFragmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableDeclarationFragment(this);
}

ALangParser::VariableDeclarationFragmentContext* ALangParser::variableDeclarationFragment() {
  VariableDeclarationFragmentContext *_localctx = _tracker.createInstance<VariableDeclarationFragmentContext>(_ctx, getState());
  enterRule(_localctx, 22, ALangParser::RuleVariableDeclarationFragment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(125);
    type();
    setState(126);
    match(ALangParser::ID);
    setState(127);
    match(ALangParser::Equals);
    setState(128);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableAssignmentContext ------------------------------------------------------------------

ALangParser::VariableAssignmentContext::VariableAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ALangParser::VariableAssignmentContext::ID() {
  return getToken(ALangParser::ID, 0);
}

ALangParser::AssignmentOperatorContext* ALangParser::VariableAssignmentContext::assignmentOperator() {
  return getRuleContext<ALangParser::AssignmentOperatorContext>(0);
}

ALangParser::ExpressionContext* ALangParser::VariableAssignmentContext::expression() {
  return getRuleContext<ALangParser::ExpressionContext>(0);
}

tree::TerminalNode* ALangParser::VariableAssignmentContext::SemiColon() {
  return getToken(ALangParser::SemiColon, 0);
}


size_t ALangParser::VariableAssignmentContext::getRuleIndex() const {
  return ALangParser::RuleVariableAssignment;
}

void ALangParser::VariableAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableAssignment(this);
}

void ALangParser::VariableAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableAssignment(this);
}

ALangParser::VariableAssignmentContext* ALangParser::variableAssignment() {
  VariableAssignmentContext *_localctx = _tracker.createInstance<VariableAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 24, ALangParser::RuleVariableAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(130);
    match(ALangParser::ID);
    setState(131);
    assignmentOperator();
    setState(132);
    expression(0);
    setState(133);
    match(ALangParser::SemiColon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableAssignmentFragmentContext ------------------------------------------------------------------

ALangParser::VariableAssignmentFragmentContext::VariableAssignmentFragmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ALangParser::VariableAssignmentFragmentContext::ID() {
  return getToken(ALangParser::ID, 0);
}

ALangParser::AssignmentOperatorContext* ALangParser::VariableAssignmentFragmentContext::assignmentOperator() {
  return getRuleContext<ALangParser::AssignmentOperatorContext>(0);
}

ALangParser::ExpressionContext* ALangParser::VariableAssignmentFragmentContext::expression() {
  return getRuleContext<ALangParser::ExpressionContext>(0);
}


size_t ALangParser::VariableAssignmentFragmentContext::getRuleIndex() const {
  return ALangParser::RuleVariableAssignmentFragment;
}

void ALangParser::VariableAssignmentFragmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableAssignmentFragment(this);
}

void ALangParser::VariableAssignmentFragmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableAssignmentFragment(this);
}

ALangParser::VariableAssignmentFragmentContext* ALangParser::variableAssignmentFragment() {
  VariableAssignmentFragmentContext *_localctx = _tracker.createInstance<VariableAssignmentFragmentContext>(_ctx, getState());
  enterRule(_localctx, 26, ALangParser::RuleVariableAssignmentFragment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(135);
    match(ALangParser::ID);
    setState(136);
    assignmentOperator();
    setState(137);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

ALangParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ALangParser::ReturnStatementContext::Return() {
  return getToken(ALangParser::Return, 0);
}

ALangParser::ExpressionContext* ALangParser::ReturnStatementContext::expression() {
  return getRuleContext<ALangParser::ExpressionContext>(0);
}

tree::TerminalNode* ALangParser::ReturnStatementContext::SemiColon() {
  return getToken(ALangParser::SemiColon, 0);
}


size_t ALangParser::ReturnStatementContext::getRuleIndex() const {
  return ALangParser::RuleReturnStatement;
}

void ALangParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}

void ALangParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}

ALangParser::ReturnStatementContext* ALangParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 28, ALangParser::RuleReturnStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(139);
    match(ALangParser::Return);
    setState(140);
    expression(0);
    setState(141);
    match(ALangParser::SemiColon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfElseIfElseStatementContext ------------------------------------------------------------------

ALangParser::IfElseIfElseStatementContext::IfElseIfElseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ALangParser::IfStatementContext* ALangParser::IfElseIfElseStatementContext::ifStatement() {
  return getRuleContext<ALangParser::IfStatementContext>(0);
}

std::vector<ALangParser::ElseIfStatementContext *> ALangParser::IfElseIfElseStatementContext::elseIfStatement() {
  return getRuleContexts<ALangParser::ElseIfStatementContext>();
}

ALangParser::ElseIfStatementContext* ALangParser::IfElseIfElseStatementContext::elseIfStatement(size_t i) {
  return getRuleContext<ALangParser::ElseIfStatementContext>(i);
}

ALangParser::ElseStatementContext* ALangParser::IfElseIfElseStatementContext::elseStatement() {
  return getRuleContext<ALangParser::ElseStatementContext>(0);
}


size_t ALangParser::IfElseIfElseStatementContext::getRuleIndex() const {
  return ALangParser::RuleIfElseIfElseStatement;
}

void ALangParser::IfElseIfElseStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfElseIfElseStatement(this);
}

void ALangParser::IfElseIfElseStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfElseIfElseStatement(this);
}

ALangParser::IfElseIfElseStatementContext* ALangParser::ifElseIfElseStatement() {
  IfElseIfElseStatementContext *_localctx = _tracker.createInstance<IfElseIfElseStatementContext>(_ctx, getState());
  enterRule(_localctx, 30, ALangParser::RuleIfElseIfElseStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(143);
    ifStatement();
    setState(147);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ALangParser::ElseIf) {
      setState(144);
      elseIfStatement();
      setState(149);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(151);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ALangParser::Else) {
      setState(150);
      elseStatement();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

ALangParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ALangParser::IfStatementContext::If() {
  return getToken(ALangParser::If, 0);
}

tree::TerminalNode* ALangParser::IfStatementContext::OpenRoundBracket() {
  return getToken(ALangParser::OpenRoundBracket, 0);
}

ALangParser::ExpressionContext* ALangParser::IfStatementContext::expression() {
  return getRuleContext<ALangParser::ExpressionContext>(0);
}

tree::TerminalNode* ALangParser::IfStatementContext::CloseRoundBracket() {
  return getToken(ALangParser::CloseRoundBracket, 0);
}

ALangParser::BlockStatementContext* ALangParser::IfStatementContext::blockStatement() {
  return getRuleContext<ALangParser::BlockStatementContext>(0);
}


size_t ALangParser::IfStatementContext::getRuleIndex() const {
  return ALangParser::RuleIfStatement;
}

void ALangParser::IfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStatement(this);
}

void ALangParser::IfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStatement(this);
}

ALangParser::IfStatementContext* ALangParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 32, ALangParser::RuleIfStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(153);
    match(ALangParser::If);
    setState(154);
    match(ALangParser::OpenRoundBracket);
    setState(155);
    expression(0);
    setState(156);
    match(ALangParser::CloseRoundBracket);
    setState(157);
    blockStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseIfStatementContext ------------------------------------------------------------------

ALangParser::ElseIfStatementContext::ElseIfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ALangParser::ElseIfStatementContext::ElseIf() {
  return getToken(ALangParser::ElseIf, 0);
}

tree::TerminalNode* ALangParser::ElseIfStatementContext::OpenRoundBracket() {
  return getToken(ALangParser::OpenRoundBracket, 0);
}

ALangParser::ExpressionContext* ALangParser::ElseIfStatementContext::expression() {
  return getRuleContext<ALangParser::ExpressionContext>(0);
}

tree::TerminalNode* ALangParser::ElseIfStatementContext::CloseRoundBracket() {
  return getToken(ALangParser::CloseRoundBracket, 0);
}

ALangParser::BlockStatementContext* ALangParser::ElseIfStatementContext::blockStatement() {
  return getRuleContext<ALangParser::BlockStatementContext>(0);
}


size_t ALangParser::ElseIfStatementContext::getRuleIndex() const {
  return ALangParser::RuleElseIfStatement;
}

void ALangParser::ElseIfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElseIfStatement(this);
}

void ALangParser::ElseIfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElseIfStatement(this);
}

ALangParser::ElseIfStatementContext* ALangParser::elseIfStatement() {
  ElseIfStatementContext *_localctx = _tracker.createInstance<ElseIfStatementContext>(_ctx, getState());
  enterRule(_localctx, 34, ALangParser::RuleElseIfStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
    match(ALangParser::ElseIf);
    setState(160);
    match(ALangParser::OpenRoundBracket);
    setState(161);
    expression(0);
    setState(162);
    match(ALangParser::CloseRoundBracket);
    setState(163);
    blockStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseStatementContext ------------------------------------------------------------------

ALangParser::ElseStatementContext::ElseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ALangParser::ElseStatementContext::Else() {
  return getToken(ALangParser::Else, 0);
}

ALangParser::BlockStatementContext* ALangParser::ElseStatementContext::blockStatement() {
  return getRuleContext<ALangParser::BlockStatementContext>(0);
}


size_t ALangParser::ElseStatementContext::getRuleIndex() const {
  return ALangParser::RuleElseStatement;
}

void ALangParser::ElseStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElseStatement(this);
}

void ALangParser::ElseStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElseStatement(this);
}

ALangParser::ElseStatementContext* ALangParser::elseStatement() {
  ElseStatementContext *_localctx = _tracker.createInstance<ElseStatementContext>(_ctx, getState());
  enterRule(_localctx, 36, ALangParser::RuleElseStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(165);
    match(ALangParser::Else);
    setState(166);
    blockStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStatementContext ------------------------------------------------------------------

ALangParser::ForStatementContext::ForStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ALangParser::ForStatementContext::For() {
  return getToken(ALangParser::For, 0);
}

tree::TerminalNode* ALangParser::ForStatementContext::OpenRoundBracket() {
  return getToken(ALangParser::OpenRoundBracket, 0);
}

std::vector<tree::TerminalNode *> ALangParser::ForStatementContext::SemiColon() {
  return getTokens(ALangParser::SemiColon);
}

tree::TerminalNode* ALangParser::ForStatementContext::SemiColon(size_t i) {
  return getToken(ALangParser::SemiColon, i);
}

tree::TerminalNode* ALangParser::ForStatementContext::CloseRoundBracket() {
  return getToken(ALangParser::CloseRoundBracket, 0);
}

ALangParser::BlockStatementContext* ALangParser::ForStatementContext::blockStatement() {
  return getRuleContext<ALangParser::BlockStatementContext>(0);
}

std::vector<ALangParser::ExpressionContext *> ALangParser::ForStatementContext::expression() {
  return getRuleContexts<ALangParser::ExpressionContext>();
}

ALangParser::ExpressionContext* ALangParser::ForStatementContext::expression(size_t i) {
  return getRuleContext<ALangParser::ExpressionContext>(i);
}

ALangParser::VariableDeclarationFragmentContext* ALangParser::ForStatementContext::variableDeclarationFragment() {
  return getRuleContext<ALangParser::VariableDeclarationFragmentContext>(0);
}

ALangParser::VariableAssignmentFragmentContext* ALangParser::ForStatementContext::variableAssignmentFragment() {
  return getRuleContext<ALangParser::VariableAssignmentFragmentContext>(0);
}


size_t ALangParser::ForStatementContext::getRuleIndex() const {
  return ALangParser::RuleForStatement;
}

void ALangParser::ForStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForStatement(this);
}

void ALangParser::ForStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForStatement(this);
}

ALangParser::ForStatementContext* ALangParser::forStatement() {
  ForStatementContext *_localctx = _tracker.createInstance<ForStatementContext>(_ctx, getState());
  enterRule(_localctx, 38, ALangParser::RuleForStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(168);
    match(ALangParser::For);
    setState(169);
    match(ALangParser::OpenRoundBracket);
    setState(172);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      setState(170);
      variableDeclarationFragment();
      break;
    }

    case 2: {
      setState(171);
      variableAssignmentFragment();
      break;
    }

    default:
      break;
    }
    setState(174);
    match(ALangParser::SemiColon);
    setState(175);
    dynamic_cast<ForStatementContext *>(_localctx)->test = expression(0);
    setState(176);
    match(ALangParser::SemiColon);
    setState(177);
    dynamic_cast<ForStatementContext *>(_localctx)->increment = expression(0);
    setState(178);
    match(ALangParser::CloseRoundBracket);
    setState(179);
    blockStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

ALangParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ALangParser::ExpressionContext::OpenRoundBracket() {
  return getToken(ALangParser::OpenRoundBracket, 0);
}

std::vector<ALangParser::ExpressionContext *> ALangParser::ExpressionContext::expression() {
  return getRuleContexts<ALangParser::ExpressionContext>();
}

ALangParser::ExpressionContext* ALangParser::ExpressionContext::expression(size_t i) {
  return getRuleContext<ALangParser::ExpressionContext>(i);
}

tree::TerminalNode* ALangParser::ExpressionContext::CloseRoundBracket() {
  return getToken(ALangParser::CloseRoundBracket, 0);
}

ALangParser::FunctionCallExpressionContext* ALangParser::ExpressionContext::functionCallExpression() {
  return getRuleContext<ALangParser::FunctionCallExpressionContext>(0);
}

ALangParser::VariableAssignmentFragmentContext* ALangParser::ExpressionContext::variableAssignmentFragment() {
  return getRuleContext<ALangParser::VariableAssignmentFragmentContext>(0);
}

tree::TerminalNode* ALangParser::ExpressionContext::BooleanConstant() {
  return getToken(ALangParser::BooleanConstant, 0);
}

tree::TerminalNode* ALangParser::ExpressionContext::DoubleQuoteString() {
  return getToken(ALangParser::DoubleQuoteString, 0);
}

tree::TerminalNode* ALangParser::ExpressionContext::NUMBER() {
  return getToken(ALangParser::NUMBER, 0);
}

tree::TerminalNode* ALangParser::ExpressionContext::ID() {
  return getToken(ALangParser::ID, 0);
}


size_t ALangParser::ExpressionContext::getRuleIndex() const {
  return ALangParser::RuleExpression;
}

void ALangParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void ALangParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


ALangParser::ExpressionContext* ALangParser::expression() {
   return expression(0);
}

ALangParser::ExpressionContext* ALangParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ALangParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  ALangParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, ALangParser::RuleExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(192);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      setState(182);
      match(ALangParser::OpenRoundBracket);
      setState(183);
      expression(0);
      setState(184);
      match(ALangParser::CloseRoundBracket);
      break;
    }

    case 2: {
      setState(186);
      functionCallExpression();
      break;
    }

    case 3: {
      setState(187);
      variableAssignmentFragment();
      break;
    }

    case 4: {
      setState(188);
      match(ALangParser::BooleanConstant);
      break;
    }

    case 5: {
      setState(189);
      match(ALangParser::DoubleQuoteString);
      break;
    }

    case 6: {
      setState(190);
      match(ALangParser::NUMBER);
      break;
    }

    case 7: {
      setState(191);
      match(ALangParser::ID);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(214);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(212);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(194);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(195);
          dynamic_cast<ExpressionContext *>(_localctx)->operation = match(ALangParser::T__1);
          setState(196);
          expression(13);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(197);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(198);
          dynamic_cast<ExpressionContext *>(_localctx)->operation = match(ALangParser::T__2);
          setState(199);
          expression(12);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(200);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(201);
          dynamic_cast<ExpressionContext *>(_localctx)->operation = match(ALangParser::T__3);
          setState(202);
          expression(11);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(203);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(204);
          dynamic_cast<ExpressionContext *>(_localctx)->operation = match(ALangParser::T__4);
          setState(205);
          expression(10);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(206);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(207);
          dynamic_cast<ExpressionContext *>(_localctx)->test = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << ALangParser::T__5)
            | (1ULL << ALangParser::T__6)
            | (1ULL << ALangParser::T__7)
            | (1ULL << ALangParser::T__8)
            | (1ULL << ALangParser::T__9)
            | (1ULL << ALangParser::T__10))) != 0))) {
            dynamic_cast<ExpressionContext *>(_localctx)->test = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(208);
          expression(9);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(209);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(210);
          dynamic_cast<ExpressionContext *>(_localctx)->test = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == ALangParser::T__11

          || _la == ALangParser::T__12)) {
            dynamic_cast<ExpressionContext *>(_localctx)->test = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(211);
          expression(8);
          break;
        }

        default:
          break;
        } 
      }
      setState(216);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

ALangParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ALangParser::TypeContext::Int() {
  return getToken(ALangParser::Int, 0);
}

tree::TerminalNode* ALangParser::TypeContext::Boolean() {
  return getToken(ALangParser::Boolean, 0);
}

tree::TerminalNode* ALangParser::TypeContext::String() {
  return getToken(ALangParser::String, 0);
}

tree::TerminalNode* ALangParser::TypeContext::Void() {
  return getToken(ALangParser::Void, 0);
}

tree::TerminalNode* ALangParser::TypeContext::ID() {
  return getToken(ALangParser::ID, 0);
}


size_t ALangParser::TypeContext::getRuleIndex() const {
  return ALangParser::RuleType;
}

void ALangParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void ALangParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}

ALangParser::TypeContext* ALangParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 42, ALangParser::RuleType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(217);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ALangParser::Int)
      | (1ULL << ALangParser::Void)
      | (1ULL << ALangParser::String)
      | (1ULL << ALangParser::Boolean)
      | (1ULL << ALangParser::ID))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentOperatorContext ------------------------------------------------------------------

ALangParser::AssignmentOperatorContext::AssignmentOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ALangParser::AssignmentOperatorContext::Equals() {
  return getToken(ALangParser::Equals, 0);
}


size_t ALangParser::AssignmentOperatorContext::getRuleIndex() const {
  return ALangParser::RuleAssignmentOperator;
}

void ALangParser::AssignmentOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentOperator(this);
}

void ALangParser::AssignmentOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ALangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentOperator(this);
}

ALangParser::AssignmentOperatorContext* ALangParser::assignmentOperator() {
  AssignmentOperatorContext *_localctx = _tracker.createInstance<AssignmentOperatorContext>(_ctx, getState());
  enterRule(_localctx, 44, ALangParser::RuleAssignmentOperator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(219);
    match(ALangParser::Equals);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool ALangParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 20: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ALangParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 12);
    case 1: return precpred(_ctx, 11);
    case 2: return precpred(_ctx, 10);
    case 3: return precpred(_ctx, 9);
    case 4: return precpred(_ctx, 8);
    case 5: return precpred(_ctx, 7);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> ALangParser::_decisionToDFA;
atn::PredictionContextCache ALangParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ALangParser::_atn;
std::vector<uint16_t> ALangParser::_serializedATN;

std::vector<std::string> ALangParser::_ruleNames = {
  "root", "functionDeclaration", "parameters", "parameter", "functionCall", 
  "functionCallExpression", "arguments", "blockStatement", "innerStatementList", 
  "innerStatement", "variableDeclaration", "variableDeclarationFragment", 
  "variableAssignment", "variableAssignmentFragment", "returnStatement", 
  "ifElseIfElseStatement", "ifStatement", "elseIfStatement", "elseStatement", 
  "forStatement", "expression", "type", "assignmentOperator"
};

std::vector<std::string> ALangParser::_literalNames = {
  "", "','", "'*'", "'/'", "'+'", "'-'", "'=='", "'!='", "'<'", "'<='", 
  "'>'", "'>='", "'&&'", "'||'", "", "", "'return'", "'function'", "'for'", 
  "'if'", "'else'", "'else if'", "'int'", "'void'", "'string'", "'bool'", 
  "", "", "", "'{'", "'}'", "'('", "')'", "'['", "']'", "':'", "';'", "'='", 
  "'\"'"
};

std::vector<std::string> ALangParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "DocumentationComment", 
  "Comment", "Return", "Function_", "For", "If", "Else", "ElseIf", "Int", 
  "Void", "String", "Boolean", "BooleanConstant", "ID", "NUMBER", "OpenCurlyBracket", 
  "CloseCurlyBracket", "OpenRoundBracket", "CloseRoundBracket", "OpenSquareBracket", 
  "CloseSquareBracket", "Colon", "SemiColon", "Equals", "DoubleQuote", "DoubleQuoteString", 
  "SPACE"
};

dfa::Vocabulary ALangParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ALangParser::_tokenNames;

ALangParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x2a, 0xe0, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 
    0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x7, 0x3, 0x35, 0xa, 0x3, 0xc, 
    0x3, 0xe, 0x3, 0x38, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x5, 0x3, 0x3e, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x48, 0xa, 0x4, 0xc, 0x4, 
    0xe, 0x4, 0x4b, 0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x5, 0x6, 0x53, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x5b, 0xa, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x62, 0xa, 0x8, 0xc, 0x8, 
    0xe, 0x8, 0x65, 0xb, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0xa, 0x7, 0xa, 0x6c, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x6f, 0xb, 0xa, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 
    0xb, 0x78, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 
    0x11, 0x7, 0x11, 0x94, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x97, 0xb, 0x11, 
    0x3, 0x11, 0x5, 0x11, 0x9a, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0xaf, 0xa, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0xc3, 0xa, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x7, 0x16, 0xd7, 
    0xa, 0x16, 0xc, 0x16, 0xe, 0x16, 0xda, 0xb, 0x16, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x2, 0x3, 0x2a, 0x19, 0x2, 0x4, 0x6, 
    0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
    0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x2, 0x5, 0x3, 0x2, 
    0x8, 0xd, 0x3, 0x2, 0xe, 0xf, 0x4, 0x2, 0x18, 0x1b, 0x1d, 0x1d, 0x2, 
    0xe4, 0x2, 0x30, 0x3, 0x2, 0x2, 0x2, 0x4, 0x36, 0x3, 0x2, 0x2, 0x2, 
    0x6, 0x44, 0x3, 0x2, 0x2, 0x2, 0x8, 0x4c, 0x3, 0x2, 0x2, 0x2, 0xa, 0x4f, 
    0x3, 0x2, 0x2, 0x2, 0xc, 0x57, 0x3, 0x2, 0x2, 0x2, 0xe, 0x5e, 0x3, 0x2, 
    0x2, 0x2, 0x10, 0x66, 0x3, 0x2, 0x2, 0x2, 0x12, 0x6d, 0x3, 0x2, 0x2, 
    0x2, 0x14, 0x77, 0x3, 0x2, 0x2, 0x2, 0x16, 0x79, 0x3, 0x2, 0x2, 0x2, 
    0x18, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x84, 0x3, 0x2, 0x2, 0x2, 0x1c, 
    0x89, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x20, 0x91, 
    0x3, 0x2, 0x2, 0x2, 0x22, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x24, 0xa1, 0x3, 
    0x2, 0x2, 0x2, 0x26, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x28, 0xaa, 0x3, 0x2, 
    0x2, 0x2, 0x2a, 0xc2, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xdb, 0x3, 0x2, 0x2, 
    0x2, 0x2e, 0xdd, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0x5, 0x12, 0xa, 0x2, 
    0x31, 0x32, 0x7, 0x2, 0x2, 0x3, 0x32, 0x3, 0x3, 0x2, 0x2, 0x2, 0x33, 
    0x35, 0x7, 0x10, 0x2, 0x2, 0x34, 0x33, 0x3, 0x2, 0x2, 0x2, 0x35, 0x38, 
    0x3, 0x2, 0x2, 0x2, 0x36, 0x34, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x3, 
    0x2, 0x2, 0x2, 0x37, 0x39, 0x3, 0x2, 0x2, 0x2, 0x38, 0x36, 0x3, 0x2, 
    0x2, 0x2, 0x39, 0x3a, 0x7, 0x13, 0x2, 0x2, 0x3a, 0x3b, 0x7, 0x1d, 0x2, 
    0x2, 0x3b, 0x3d, 0x7, 0x21, 0x2, 0x2, 0x3c, 0x3e, 0x5, 0x6, 0x4, 0x2, 
    0x3d, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x3e, 
    0x3f, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x7, 0x22, 0x2, 0x2, 0x40, 0x41, 
    0x7, 0x25, 0x2, 0x2, 0x41, 0x42, 0x5, 0x2c, 0x17, 0x2, 0x42, 0x43, 0x5, 
    0x10, 0x9, 0x2, 0x43, 0x5, 0x3, 0x2, 0x2, 0x2, 0x44, 0x49, 0x5, 0x8, 
    0x5, 0x2, 0x45, 0x46, 0x7, 0x3, 0x2, 0x2, 0x46, 0x48, 0x5, 0x8, 0x5, 
    0x2, 0x47, 0x45, 0x3, 0x2, 0x2, 0x2, 0x48, 0x4b, 0x3, 0x2, 0x2, 0x2, 
    0x49, 0x47, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4a, 
    0x7, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 
    0x5, 0x2c, 0x17, 0x2, 0x4d, 0x4e, 0x7, 0x1d, 0x2, 0x2, 0x4e, 0x9, 0x3, 
    0x2, 0x2, 0x2, 0x4f, 0x50, 0x7, 0x1d, 0x2, 0x2, 0x50, 0x52, 0x7, 0x21, 
    0x2, 0x2, 0x51, 0x53, 0x5, 0xe, 0x8, 0x2, 0x52, 0x51, 0x3, 0x2, 0x2, 
    0x2, 0x52, 0x53, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x3, 0x2, 0x2, 0x2, 
    0x54, 0x55, 0x7, 0x22, 0x2, 0x2, 0x55, 0x56, 0x7, 0x26, 0x2, 0x2, 0x56, 
    0xb, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x7, 0x1d, 0x2, 0x2, 0x58, 0x5a, 
    0x7, 0x21, 0x2, 0x2, 0x59, 0x5b, 0x5, 0xe, 0x8, 0x2, 0x5a, 0x59, 0x3, 
    0x2, 0x2, 0x2, 0x5a, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 0x3, 0x2, 
    0x2, 0x2, 0x5c, 0x5d, 0x7, 0x22, 0x2, 0x2, 0x5d, 0xd, 0x3, 0x2, 0x2, 
    0x2, 0x5e, 0x63, 0x5, 0x2a, 0x16, 0x2, 0x5f, 0x60, 0x7, 0x3, 0x2, 0x2, 
    0x60, 0x62, 0x5, 0x2a, 0x16, 0x2, 0x61, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x62, 
    0x65, 0x3, 0x2, 0x2, 0x2, 0x63, 0x61, 0x3, 0x2, 0x2, 0x2, 0x63, 0x64, 
    0x3, 0x2, 0x2, 0x2, 0x64, 0xf, 0x3, 0x2, 0x2, 0x2, 0x65, 0x63, 0x3, 
    0x2, 0x2, 0x2, 0x66, 0x67, 0x7, 0x1f, 0x2, 0x2, 0x67, 0x68, 0x5, 0x12, 
    0xa, 0x2, 0x68, 0x69, 0x7, 0x20, 0x2, 0x2, 0x69, 0x11, 0x3, 0x2, 0x2, 
    0x2, 0x6a, 0x6c, 0x5, 0x14, 0xb, 0x2, 0x6b, 0x6a, 0x3, 0x2, 0x2, 0x2, 
    0x6c, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6d, 
    0x6e, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x13, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x6d, 
    0x3, 0x2, 0x2, 0x2, 0x70, 0x78, 0x5, 0x4, 0x3, 0x2, 0x71, 0x78, 0x5, 
    0xa, 0x6, 0x2, 0x72, 0x78, 0x5, 0x20, 0x11, 0x2, 0x73, 0x78, 0x5, 0x28, 
    0x15, 0x2, 0x74, 0x78, 0x5, 0x1e, 0x10, 0x2, 0x75, 0x78, 0x5, 0x16, 
    0xc, 0x2, 0x76, 0x78, 0x5, 0x1a, 0xe, 0x2, 0x77, 0x70, 0x3, 0x2, 0x2, 
    0x2, 0x77, 0x71, 0x3, 0x2, 0x2, 0x2, 0x77, 0x72, 0x3, 0x2, 0x2, 0x2, 
    0x77, 0x73, 0x3, 0x2, 0x2, 0x2, 0x77, 0x74, 0x3, 0x2, 0x2, 0x2, 0x77, 
    0x75, 0x3, 0x2, 0x2, 0x2, 0x77, 0x76, 0x3, 0x2, 0x2, 0x2, 0x78, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 0x5, 0x2c, 0x17, 0x2, 0x7a, 0x7b, 0x7, 
    0x1d, 0x2, 0x2, 0x7b, 0x7c, 0x7, 0x27, 0x2, 0x2, 0x7c, 0x7d, 0x5, 0x2a, 
    0x16, 0x2, 0x7d, 0x7e, 0x7, 0x26, 0x2, 0x2, 0x7e, 0x17, 0x3, 0x2, 0x2, 
    0x2, 0x7f, 0x80, 0x5, 0x2c, 0x17, 0x2, 0x80, 0x81, 0x7, 0x1d, 0x2, 0x2, 
    0x81, 0x82, 0x7, 0x27, 0x2, 0x2, 0x82, 0x83, 0x5, 0x2a, 0x16, 0x2, 0x83, 
    0x19, 0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0x7, 0x1d, 0x2, 0x2, 0x85, 0x86, 
    0x5, 0x2e, 0x18, 0x2, 0x86, 0x87, 0x5, 0x2a, 0x16, 0x2, 0x87, 0x88, 
    0x7, 0x26, 0x2, 0x2, 0x88, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x7, 
    0x1d, 0x2, 0x2, 0x8a, 0x8b, 0x5, 0x2e, 0x18, 0x2, 0x8b, 0x8c, 0x5, 0x2a, 
    0x16, 0x2, 0x8c, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x7, 0x12, 0x2, 
    0x2, 0x8e, 0x8f, 0x5, 0x2a, 0x16, 0x2, 0x8f, 0x90, 0x7, 0x26, 0x2, 0x2, 
    0x90, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x91, 0x95, 0x5, 0x22, 0x12, 0x2, 0x92, 
    0x94, 0x5, 0x24, 0x13, 0x2, 0x93, 0x92, 0x3, 0x2, 0x2, 0x2, 0x94, 0x97, 
    0x3, 0x2, 0x2, 0x2, 0x95, 0x93, 0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 0x3, 
    0x2, 0x2, 0x2, 0x96, 0x99, 0x3, 0x2, 0x2, 0x2, 0x97, 0x95, 0x3, 0x2, 
    0x2, 0x2, 0x98, 0x9a, 0x5, 0x26, 0x14, 0x2, 0x99, 0x98, 0x3, 0x2, 0x2, 
    0x2, 0x99, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x21, 0x3, 0x2, 0x2, 0x2, 
    0x9b, 0x9c, 0x7, 0x15, 0x2, 0x2, 0x9c, 0x9d, 0x7, 0x21, 0x2, 0x2, 0x9d, 
    0x9e, 0x5, 0x2a, 0x16, 0x2, 0x9e, 0x9f, 0x7, 0x22, 0x2, 0x2, 0x9f, 0xa0, 
    0x5, 0x10, 0x9, 0x2, 0xa0, 0x23, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x7, 
    0x17, 0x2, 0x2, 0xa2, 0xa3, 0x7, 0x21, 0x2, 0x2, 0xa3, 0xa4, 0x5, 0x2a, 
    0x16, 0x2, 0xa4, 0xa5, 0x7, 0x22, 0x2, 0x2, 0xa5, 0xa6, 0x5, 0x10, 0x9, 
    0x2, 0xa6, 0x25, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x7, 0x16, 0x2, 0x2, 
    0xa8, 0xa9, 0x5, 0x10, 0x9, 0x2, 0xa9, 0x27, 0x3, 0x2, 0x2, 0x2, 0xaa, 
    0xab, 0x7, 0x14, 0x2, 0x2, 0xab, 0xae, 0x7, 0x21, 0x2, 0x2, 0xac, 0xaf, 
    0x5, 0x18, 0xd, 0x2, 0xad, 0xaf, 0x5, 0x1c, 0xf, 0x2, 0xae, 0xac, 0x3, 
    0x2, 0x2, 0x2, 0xae, 0xad, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb0, 0x3, 0x2, 
    0x2, 0x2, 0xb0, 0xb1, 0x7, 0x26, 0x2, 0x2, 0xb1, 0xb2, 0x5, 0x2a, 0x16, 
    0x2, 0xb2, 0xb3, 0x7, 0x26, 0x2, 0x2, 0xb3, 0xb4, 0x5, 0x2a, 0x16, 0x2, 
    0xb4, 0xb5, 0x7, 0x22, 0x2, 0x2, 0xb5, 0xb6, 0x5, 0x10, 0x9, 0x2, 0xb6, 
    0x29, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x8, 0x16, 0x1, 0x2, 0xb8, 0xb9, 
    0x7, 0x21, 0x2, 0x2, 0xb9, 0xba, 0x5, 0x2a, 0x16, 0x2, 0xba, 0xbb, 0x7, 
    0x22, 0x2, 0x2, 0xbb, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xc3, 0x5, 0xc, 
    0x7, 0x2, 0xbd, 0xc3, 0x5, 0x1c, 0xf, 0x2, 0xbe, 0xc3, 0x7, 0x1c, 0x2, 
    0x2, 0xbf, 0xc3, 0x7, 0x29, 0x2, 0x2, 0xc0, 0xc3, 0x7, 0x1e, 0x2, 0x2, 
    0xc1, 0xc3, 0x7, 0x1d, 0x2, 0x2, 0xc2, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xc2, 
    0xbc, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xbe, 
    0x3, 0x2, 0x2, 0x2, 0xc2, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc0, 0x3, 
    0x2, 0x2, 0x2, 0xc2, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xd8, 0x3, 0x2, 
    0x2, 0x2, 0xc4, 0xc5, 0xc, 0xe, 0x2, 0x2, 0xc5, 0xc6, 0x7, 0x4, 0x2, 
    0x2, 0xc6, 0xd7, 0x5, 0x2a, 0x16, 0xf, 0xc7, 0xc8, 0xc, 0xd, 0x2, 0x2, 
    0xc8, 0xc9, 0x7, 0x5, 0x2, 0x2, 0xc9, 0xd7, 0x5, 0x2a, 0x16, 0xe, 0xca, 
    0xcb, 0xc, 0xc, 0x2, 0x2, 0xcb, 0xcc, 0x7, 0x6, 0x2, 0x2, 0xcc, 0xd7, 
    0x5, 0x2a, 0x16, 0xd, 0xcd, 0xce, 0xc, 0xb, 0x2, 0x2, 0xce, 0xcf, 0x7, 
    0x7, 0x2, 0x2, 0xcf, 0xd7, 0x5, 0x2a, 0x16, 0xc, 0xd0, 0xd1, 0xc, 0xa, 
    0x2, 0x2, 0xd1, 0xd2, 0x9, 0x2, 0x2, 0x2, 0xd2, 0xd7, 0x5, 0x2a, 0x16, 
    0xb, 0xd3, 0xd4, 0xc, 0x9, 0x2, 0x2, 0xd4, 0xd5, 0x9, 0x3, 0x2, 0x2, 
    0xd5, 0xd7, 0x5, 0x2a, 0x16, 0xa, 0xd6, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xd6, 
    0xc7, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xca, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xcd, 
    0x3, 0x2, 0x2, 0x2, 0xd6, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd3, 0x3, 
    0x2, 0x2, 0x2, 0xd7, 0xda, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd6, 0x3, 0x2, 
    0x2, 0x2, 0xd8, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xd9, 0x2b, 0x3, 0x2, 0x2, 
    0x2, 0xda, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x9, 0x4, 0x2, 0x2, 
    0xdc, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xde, 0x7, 0x27, 0x2, 0x2, 0xde, 
    0x2f, 0x3, 0x2, 0x2, 0x2, 0x10, 0x36, 0x3d, 0x49, 0x52, 0x5a, 0x63, 
    0x6d, 0x77, 0x95, 0x99, 0xae, 0xc2, 0xd6, 0xd8, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ALangParser::Initializer ALangParser::_init;
