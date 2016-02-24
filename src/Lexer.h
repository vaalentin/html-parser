#ifndef H_LEXER
#define H_LEXER

#include <string>
#include <vector>
#include "Token.h"

class Lexer {
  protected:
    const std::string* m_src;
    unsigned m_pos;
    char m_char;
    std::vector<Token> m_toks;
    std::string m_buf;

    int m_row;
    int m_col;

    void consume();
    bool match(const char* s);
    bool match(char c);
    bool peek(char c);

    virtual void next();

  public:
    Lexer(const std::string* src);
    std::vector<Token> getToks();
};

#endif
