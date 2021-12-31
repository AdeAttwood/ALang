
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
    setState(38);
    innerStatementList();
    setState(39);
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
    setState(44);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ALangParser::DocumentationComment) {
      setState(41);
      match(ALangParser::DocumentationComment);
      setState(46);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(47);
    match(ALangParser::Function_);
    setState(48);
    match(ALangParser::ID);
    setState(49);
    match(ALangParser::OpenRoundBracket);
    setState(51);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ALangParser::Int)
      | (1ULL << ALangParser::Void)
      | (1ULL << ALangParser::String)
      | (1ULL << ALangParser::Boolean)
      | (1ULL << ALangParser::ID))) != 0)) {
      setState(50);
      parameters();
    }
    setState(53);
    match(ALangParser::CloseRoundBracket);
    setState(54);
    match(ALangParser::Colon);
    setState(55);
    type();
    setState(56);
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
    setState(58);
    parameter();
    setState(63);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ALangParser::T__0) {
      setState(59);
      match(ALangParser::T__0);
      setState(60);
      parameter();
      setState(65);
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
    setState(66);
    type();
    setState(67);
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
    setState(69);
    match(ALangParser::ID);
    setState(70);
    match(ALangParser::OpenRoundBracket);
    setState(72);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ALangParser::BooleanConstant)
      | (1ULL << ALangParser::ID)
      | (1ULL << ALangParser::NUMBER)
      | (1ULL << ALangParser::DoubleQuoteString))) != 0)) {
      setState(71);
      arguments();
    }
    setState(74);
    match(ALangParser::CloseRoundBracket);
    setState(75);
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
      | (1ULL << ALangParser::DoubleQuoteString))) != 0)) {
      setState(79);
      arguments();
    }
    setState(82);
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
    setState(84);
    expression(0);
    setState(89);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ALangParser::T__0) {
      setState(85);
      match(ALangParser::T__0);
      setState(86);
      expression(0);
      setState(91);
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
    setState(92);
    match(ALangParser::OpenCurlyBracket);
    setState(93);
    innerStatementList();
    setState(94);
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
    setState(99);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ALangParser::DocumentationComment)
      | (1ULL << ALangParser::Return)
      | (1ULL << ALangParser::Function_)
      | (1ULL << ALangParser::If)
      | (1ULL << ALangParser::Int)
      | (1ULL << ALangParser::Void)
      | (1ULL << ALangParser::String)
      | (1ULL << ALangParser::Boolean)
      | (1ULL << ALangParser::ID))) != 0)) {
      setState(96);
      innerStatement();
      setState(101);
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

ALangParser::ReturnStatementContext* ALangParser::InnerStatementContext::returnStatement() {
  return getRuleContext<ALangParser::ReturnStatementContext>(0);
}

ALangParser::VariableDeclarationContext* ALangParser::InnerStatementContext::variableDeclaration() {
  return getRuleContext<ALangParser::VariableDeclarationContext>(0);
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
    setState(107);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(102);
      functionDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(103);
      functionCall();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(104);
      ifElseIfElseStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(105);
      returnStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(106);
      variableDeclaration();
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
    setState(109);
    type();
    setState(110);
    match(ALangParser::ID);
    setState(111);
    match(ALangParser::Equals);
    setState(112);
    expression(0);
    setState(113);
    match(ALangParser::SemiColon);
   
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
  enterRule(_localctx, 22, ALangParser::RuleReturnStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(115);
    match(ALangParser::Return);
    setState(116);
    expression(0);
    setState(117);
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
  enterRule(_localctx, 24, ALangParser::RuleIfElseIfElseStatement);
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
    setState(119);
    ifStatement();
    setState(123);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ALangParser::ElseIf) {
      setState(120);
      elseIfStatement();
      setState(125);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(127);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ALangParser::Else) {
      setState(126);
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
  enterRule(_localctx, 26, ALangParser::RuleIfStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(129);
    match(ALangParser::If);
    setState(130);
    match(ALangParser::OpenRoundBracket);
    setState(131);
    expression(0);
    setState(132);
    match(ALangParser::CloseRoundBracket);
    setState(133);
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
  enterRule(_localctx, 28, ALangParser::RuleElseIfStatement);

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
    match(ALangParser::ElseIf);
    setState(136);
    match(ALangParser::OpenRoundBracket);
    setState(137);
    expression(0);
    setState(138);
    match(ALangParser::CloseRoundBracket);
    setState(139);
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
  enterRule(_localctx, 30, ALangParser::RuleElseStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(141);
    match(ALangParser::Else);
    setState(142);
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

ALangParser::FunctionCallExpressionContext* ALangParser::ExpressionContext::functionCallExpression() {
  return getRuleContext<ALangParser::FunctionCallExpressionContext>(0);
}

tree::TerminalNode* ALangParser::ExpressionContext::ID() {
  return getToken(ALangParser::ID, 0);
}

ALangParser::AssignmentOperatorContext* ALangParser::ExpressionContext::assignmentOperator() {
  return getRuleContext<ALangParser::AssignmentOperatorContext>(0);
}

std::vector<ALangParser::ExpressionContext *> ALangParser::ExpressionContext::expression() {
  return getRuleContexts<ALangParser::ExpressionContext>();
}

ALangParser::ExpressionContext* ALangParser::ExpressionContext::expression(size_t i) {
  return getRuleContext<ALangParser::ExpressionContext>(i);
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
  size_t startState = 32;
  enterRecursionRule(_localctx, 32, ALangParser::RuleExpression, precedence);

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
    setState(154);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      setState(145);
      functionCallExpression();
      break;
    }

    case 2: {
      setState(146);
      match(ALangParser::ID);
      setState(147);
      assignmentOperator();
      setState(148);
      expression(5);
      break;
    }

    case 3: {
      setState(150);
      match(ALangParser::BooleanConstant);
      break;
    }

    case 4: {
      setState(151);
      match(ALangParser::DoubleQuoteString);
      break;
    }

    case 5: {
      setState(152);
      match(ALangParser::NUMBER);
      break;
    }

    case 6: {
      setState(153);
      match(ALangParser::ID);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(164);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(162);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(156);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(157);
          dynamic_cast<ExpressionContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == ALangParser::T__1

          || _la == ALangParser::T__2)) {
            dynamic_cast<ExpressionContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(158);
          expression(9);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(159);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(160);
          dynamic_cast<ExpressionContext *>(_localctx)->test = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == ALangParser::T__3

          || _la == ALangParser::T__4)) {
            dynamic_cast<ExpressionContext *>(_localctx)->test = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(161);
          expression(8);
          break;
        }

        default:
          break;
        } 
      }
      setState(166);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
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
  enterRule(_localctx, 34, ALangParser::RuleType);
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
    setState(167);
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
  enterRule(_localctx, 36, ALangParser::RuleAssignmentOperator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(169);
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
    case 16: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ALangParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 8);
    case 1: return precpred(_ctx, 7);

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
  "innerStatement", "variableDeclaration", "returnStatement", "ifElseIfElseStatement", 
  "ifStatement", "elseIfStatement", "elseStatement", "expression", "type", 
  "assignmentOperator"
};

std::vector<std::string> ALangParser::_literalNames = {
  "", "','", "'+'", "'-'", "'=='", "'!='", "", "", "'return'", "'function'", 
  "'if'", "'else'", "'else if'", "'int'", "'void'", "'string'", "'bool'", 
  "", "", "", "'{'", "'}'", "'('", "')'", "'['", "']'", "':'", "';'", "'='", 
  "'\"'"
};

std::vector<std::string> ALangParser::_symbolicNames = {
  "", "", "", "", "", "", "DocumentationComment", "Comment", "Return", "Function_", 
  "If", "Else", "ElseIf", "Int", "Void", "String", "Boolean", "BooleanConstant", 
  "ID", "NUMBER", "OpenCurlyBracket", "CloseCurlyBracket", "OpenRoundBracket", 
  "CloseRoundBracket", "OpenSquareBracket", "CloseSquareBracket", "Colon", 
  "SemiColon", "Equals", "DoubleQuote", "DoubleQuoteString", "SPACE"
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
    0x3, 0x21, 0xae, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x3, 0x7, 0x3, 0x2d, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 
    0x30, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x36, 
    0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x40, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x43, 
    0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x5, 0x6, 0x4b, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x5, 0x7, 0x53, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x5a, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x5d, 
    0xb, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x7, 0xa, 
    0x64, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x67, 0xb, 0xa, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x6e, 0xa, 0xb, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x7c, 0xa, 0xe, 0xc, 0xe, 
    0xe, 0xe, 0x7f, 0xb, 0xe, 0x3, 0xe, 0x5, 0xe, 0x82, 0xa, 0xe, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x9d, 0xa, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 
    0x12, 0xa5, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0xa8, 0xb, 0x12, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x2, 0x3, 0x22, 0x15, 0x2, 
    0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 
    0x1e, 0x20, 0x22, 0x24, 0x26, 0x2, 0x5, 0x3, 0x2, 0x4, 0x5, 0x3, 0x2, 
    0x6, 0x7, 0x4, 0x2, 0xf, 0x12, 0x14, 0x14, 0x2, 0xae, 0x2, 0x28, 0x3, 
    0x2, 0x2, 0x2, 0x4, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x6, 0x3c, 0x3, 0x2, 0x2, 
    0x2, 0x8, 0x44, 0x3, 0x2, 0x2, 0x2, 0xa, 0x47, 0x3, 0x2, 0x2, 0x2, 0xc, 
    0x4f, 0x3, 0x2, 0x2, 0x2, 0xe, 0x56, 0x3, 0x2, 0x2, 0x2, 0x10, 0x5e, 
    0x3, 0x2, 0x2, 0x2, 0x12, 0x65, 0x3, 0x2, 0x2, 0x2, 0x14, 0x6d, 0x3, 
    0x2, 0x2, 0x2, 0x16, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x18, 0x75, 0x3, 0x2, 
    0x2, 0x2, 0x1a, 0x79, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x83, 0x3, 0x2, 0x2, 
    0x2, 0x1e, 0x89, 0x3, 0x2, 0x2, 0x2, 0x20, 0x8f, 0x3, 0x2, 0x2, 0x2, 
    0x22, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x24, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x26, 
    0xab, 0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 0x5, 0x12, 0xa, 0x2, 0x29, 0x2a, 
    0x7, 0x2, 0x2, 0x3, 0x2a, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2d, 0x7, 
    0x8, 0x2, 0x2, 0x2c, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x30, 0x3, 0x2, 
    0x2, 0x2, 0x2e, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2f, 0x3, 0x2, 0x2, 
    0x2, 0x2f, 0x31, 0x3, 0x2, 0x2, 0x2, 0x30, 0x2e, 0x3, 0x2, 0x2, 0x2, 
    0x31, 0x32, 0x7, 0xb, 0x2, 0x2, 0x32, 0x33, 0x7, 0x14, 0x2, 0x2, 0x33, 
    0x35, 0x7, 0x18, 0x2, 0x2, 0x34, 0x36, 0x5, 0x6, 0x4, 0x2, 0x35, 0x34, 
    0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x3, 
    0x2, 0x2, 0x2, 0x37, 0x38, 0x7, 0x19, 0x2, 0x2, 0x38, 0x39, 0x7, 0x1c, 
    0x2, 0x2, 0x39, 0x3a, 0x5, 0x24, 0x13, 0x2, 0x3a, 0x3b, 0x5, 0x10, 0x9, 
    0x2, 0x3b, 0x5, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x41, 0x5, 0x8, 0x5, 0x2, 
    0x3d, 0x3e, 0x7, 0x3, 0x2, 0x2, 0x3e, 0x40, 0x5, 0x8, 0x5, 0x2, 0x3f, 
    0x3d, 0x3, 0x2, 0x2, 0x2, 0x40, 0x43, 0x3, 0x2, 0x2, 0x2, 0x41, 0x3f, 
    0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x3, 0x2, 0x2, 0x2, 0x42, 0x7, 0x3, 
    0x2, 0x2, 0x2, 0x43, 0x41, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x5, 0x24, 
    0x13, 0x2, 0x45, 0x46, 0x7, 0x14, 0x2, 0x2, 0x46, 0x9, 0x3, 0x2, 0x2, 
    0x2, 0x47, 0x48, 0x7, 0x14, 0x2, 0x2, 0x48, 0x4a, 0x7, 0x18, 0x2, 0x2, 
    0x49, 0x4b, 0x5, 0xe, 0x8, 0x2, 0x4a, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4a, 
    0x4b, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 
    0x7, 0x19, 0x2, 0x2, 0x4d, 0x4e, 0x7, 0x1d, 0x2, 0x2, 0x4e, 0xb, 0x3, 
    0x2, 0x2, 0x2, 0x4f, 0x50, 0x7, 0x14, 0x2, 0x2, 0x50, 0x52, 0x7, 0x18, 
    0x2, 0x2, 0x51, 0x53, 0x5, 0xe, 0x8, 0x2, 0x52, 0x51, 0x3, 0x2, 0x2, 
    0x2, 0x52, 0x53, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x3, 0x2, 0x2, 0x2, 
    0x54, 0x55, 0x7, 0x19, 0x2, 0x2, 0x55, 0xd, 0x3, 0x2, 0x2, 0x2, 0x56, 
    0x5b, 0x5, 0x22, 0x12, 0x2, 0x57, 0x58, 0x7, 0x3, 0x2, 0x2, 0x58, 0x5a, 
    0x5, 0x22, 0x12, 0x2, 0x59, 0x57, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5d, 0x3, 
    0x2, 0x2, 0x2, 0x5b, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 0x3, 0x2, 
    0x2, 0x2, 0x5c, 0xf, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5b, 0x3, 0x2, 0x2, 
    0x2, 0x5e, 0x5f, 0x7, 0x16, 0x2, 0x2, 0x5f, 0x60, 0x5, 0x12, 0xa, 0x2, 
    0x60, 0x61, 0x7, 0x17, 0x2, 0x2, 0x61, 0x11, 0x3, 0x2, 0x2, 0x2, 0x62, 
    0x64, 0x5, 0x14, 0xb, 0x2, 0x63, 0x62, 0x3, 0x2, 0x2, 0x2, 0x64, 0x67, 
    0x3, 0x2, 0x2, 0x2, 0x65, 0x63, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 0x3, 
    0x2, 0x2, 0x2, 0x66, 0x13, 0x3, 0x2, 0x2, 0x2, 0x67, 0x65, 0x3, 0x2, 
    0x2, 0x2, 0x68, 0x6e, 0x5, 0x4, 0x3, 0x2, 0x69, 0x6e, 0x5, 0xa, 0x6, 
    0x2, 0x6a, 0x6e, 0x5, 0x1a, 0xe, 0x2, 0x6b, 0x6e, 0x5, 0x18, 0xd, 0x2, 
    0x6c, 0x6e, 0x5, 0x16, 0xc, 0x2, 0x6d, 0x68, 0x3, 0x2, 0x2, 0x2, 0x6d, 
    0x69, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6b, 
    0x3, 0x2, 0x2, 0x2, 0x6d, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x15, 0x3, 
    0x2, 0x2, 0x2, 0x6f, 0x70, 0x5, 0x24, 0x13, 0x2, 0x70, 0x71, 0x7, 0x14, 
    0x2, 0x2, 0x71, 0x72, 0x7, 0x1e, 0x2, 0x2, 0x72, 0x73, 0x5, 0x22, 0x12, 
    0x2, 0x73, 0x74, 0x7, 0x1d, 0x2, 0x2, 0x74, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x75, 0x76, 0x7, 0xa, 0x2, 0x2, 0x76, 0x77, 0x5, 0x22, 0x12, 0x2, 0x77, 
    0x78, 0x7, 0x1d, 0x2, 0x2, 0x78, 0x19, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7d, 
    0x5, 0x1c, 0xf, 0x2, 0x7a, 0x7c, 0x5, 0x1e, 0x10, 0x2, 0x7b, 0x7a, 0x3, 
    0x2, 0x2, 0x2, 0x7c, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7b, 0x3, 0x2, 
    0x2, 0x2, 0x7d, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x81, 0x3, 0x2, 0x2, 
    0x2, 0x7f, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x80, 0x82, 0x5, 0x20, 0x11, 0x2, 
    0x81, 0x80, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x3, 0x2, 0x2, 0x2, 0x82, 
    0x1b, 0x3, 0x2, 0x2, 0x2, 0x83, 0x84, 0x7, 0xc, 0x2, 0x2, 0x84, 0x85, 
    0x7, 0x18, 0x2, 0x2, 0x85, 0x86, 0x5, 0x22, 0x12, 0x2, 0x86, 0x87, 0x7, 
    0x19, 0x2, 0x2, 0x87, 0x88, 0x5, 0x10, 0x9, 0x2, 0x88, 0x1d, 0x3, 0x2, 
    0x2, 0x2, 0x89, 0x8a, 0x7, 0xe, 0x2, 0x2, 0x8a, 0x8b, 0x7, 0x18, 0x2, 
    0x2, 0x8b, 0x8c, 0x5, 0x22, 0x12, 0x2, 0x8c, 0x8d, 0x7, 0x19, 0x2, 0x2, 
    0x8d, 0x8e, 0x5, 0x10, 0x9, 0x2, 0x8e, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x8f, 
    0x90, 0x7, 0xd, 0x2, 0x2, 0x90, 0x91, 0x5, 0x10, 0x9, 0x2, 0x91, 0x21, 
    0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x8, 0x12, 0x1, 0x2, 0x93, 0x9d, 0x5, 
    0xc, 0x7, 0x2, 0x94, 0x95, 0x7, 0x14, 0x2, 0x2, 0x95, 0x96, 0x5, 0x26, 
    0x14, 0x2, 0x96, 0x97, 0x5, 0x22, 0x12, 0x7, 0x97, 0x9d, 0x3, 0x2, 0x2, 
    0x2, 0x98, 0x9d, 0x7, 0x13, 0x2, 0x2, 0x99, 0x9d, 0x7, 0x20, 0x2, 0x2, 
    0x9a, 0x9d, 0x7, 0x15, 0x2, 0x2, 0x9b, 0x9d, 0x7, 0x14, 0x2, 0x2, 0x9c, 
    0x92, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x94, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x98, 
    0x3, 0x2, 0x2, 0x2, 0x9c, 0x99, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9a, 0x3, 
    0x2, 0x2, 0x2, 0x9c, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9d, 0xa6, 0x3, 0x2, 
    0x2, 0x2, 0x9e, 0x9f, 0xc, 0xa, 0x2, 0x2, 0x9f, 0xa0, 0x9, 0x2, 0x2, 
    0x2, 0xa0, 0xa5, 0x5, 0x22, 0x12, 0xb, 0xa1, 0xa2, 0xc, 0x9, 0x2, 0x2, 
    0xa2, 0xa3, 0x9, 0x3, 0x2, 0x2, 0xa3, 0xa5, 0x5, 0x22, 0x12, 0xa, 0xa4, 
    0x9e, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa8, 
    0x3, 0x2, 0x2, 0x2, 0xa6, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0x3, 
    0x2, 0x2, 0x2, 0xa7, 0x23, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa6, 0x3, 0x2, 
    0x2, 0x2, 0xa9, 0xaa, 0x9, 0x4, 0x2, 0x2, 0xaa, 0x25, 0x3, 0x2, 0x2, 
    0x2, 0xab, 0xac, 0x7, 0x1e, 0x2, 0x2, 0xac, 0x27, 0x3, 0x2, 0x2, 0x2, 
    0xf, 0x2e, 0x35, 0x41, 0x4a, 0x52, 0x5b, 0x65, 0x6d, 0x7d, 0x81, 0x9c, 
    0xa4, 0xa6, 
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
