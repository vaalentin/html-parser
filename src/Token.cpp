#include <string>
#include "Token.h"

Token::Token(const char* type, std::string val, int row, int col) {
  m_type = type;
  m_val = val;
  m_row = row;
  m_col = col;
}

std::string Token::toStr() {
  return std::string ("(" + std::to_string(m_row) + ", " + std::to_string(m_col) + ")"
    + " " + std::string(m_type)
    + " " + m_val);
}
