#ifndef H_TOKEN
#define H_TOKEN

#include <string>
#include "TokenType.h"

class Token {
  private:
    TokenType m_type;
    std::string m_val;
    int m_row;
    int m_col;

  public:
    static const char* strPatt;
    Token(TokenType type, int row, int col);
    Token(TokenType type, std::string val, int row, int col);
    std::string toStr();
};

#endif
