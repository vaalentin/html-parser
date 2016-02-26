#ifndef H_HTML_LEXER
#define H_HTML_LEXER

#include "Lexer.h"

class HtmlLexer : public Lexer {
  private:
    virtual void next();

    void whitespace();
    void comment();
    void tag();
    void id();
    void value();
    void text();

  public:
    using Lexer::Lexer;
};

#endif
