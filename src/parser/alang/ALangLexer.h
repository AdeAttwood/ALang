
// Generated from ALang.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"


namespace parser::alang {


class  ALangLexer : public antlr4::Lexer {
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
