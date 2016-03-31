#ifndef H_PARSER
#define H_PARSER

#include <vector>
#include "Token.h"
#include "TokenType.h"

class Parser {
  protected:
    const std::vector<Token>* m_toks;
    unsigned m_pos;
    const Token* m_tok;

    void consume();
    void expect(const TokenType& t);
    bool match(const TokenType& t);

    virtual void next();

  public:
    Parser(const std::vector<Token>* toks);
    void parse();
};

#endif
