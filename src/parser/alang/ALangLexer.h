
// Generated from ALang.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"


namespace parser::alang {


class  ALangLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    DocumentationComment = 8, Comment = 9, Return = 10, Function_ = 11, 
    If = 12, Else = 13, ElseIf = 14, Int = 15, Void = 16, String = 17, Boolean = 18, 
    BooleanConstant = 19, ID = 20, NUMBER = 21, OpenCurlyBracket = 22, CloseCurlyBracket = 23, 
    OpenRoundBracket = 24, CloseRoundBracket = 25, OpenSquareBracket = 26, 
    CloseSquareBracket = 27, Colon = 28, SemiColon = 29, Equals = 30, DoubleQuote = 31, 
    DoubleQuoteString = 32, SPACE = 33
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
