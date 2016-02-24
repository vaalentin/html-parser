#include <string>
#include "Token.h"

Token::Token(const char* type, std::string val, int row, int col) {
  m_type = type;
  m_val = val;
  m_row = row;
  m_col = col;
}
