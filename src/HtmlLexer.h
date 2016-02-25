#ifndef H_HTML_LEXER
#define H_HTML_LEXER

#include "Lexer.h"

class HtmlLexer : public Lexer {
  private:
    virtual void next();
  public:
    using Lexer::Lexer;
};

#endif
