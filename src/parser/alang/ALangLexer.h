
// Generated from ALang.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"


namespace parser::alang {


class  ALangLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, DocumentationComment = 14, 
    Comment = 15, Return = 16, Function_ = 17, If = 18, Else = 19, ElseIf = 20, 
    Int = 21, Void = 22, String = 23, Boolean = 24, BooleanConstant = 25, 
    ID = 26, NUMBER = 27, OpenCurlyBracket = 28, CloseCurlyBracket = 29, 
    OpenRoundBracket = 30, CloseRoundBracket = 31, OpenSquareBracket = 32, 
    CloseSquareBracket = 33, Colon = 34, SemiColon = 35, Equals = 36, DoubleQuote = 37, 
    DoubleQuoteString = 38, SPACE = 39
  };

  explicit ALangLexer(antlr4::CharStream *input);
  ~ALangLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace parser::alang
