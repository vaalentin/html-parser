#ifndef H_HTML_PARSER
#define H_HTML_PARSER

#include "Parser.h"

class HtmlParser : public Parser {
  private:
    virtual void next();

    void openTag();
    void closeTag();
    void option();

  public:
    using Parser::Parser;
};

#endif
