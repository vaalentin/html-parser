#include <string>
#include "Token.h"
#include "TokenType.h"
#include "utils.h"

Token::Token(TokenType type, int row, int col) {
  m_type = type;
  m_row = row;
  m_col = col;
}

Token::Token(TokenType type, std::string val, int row, int col) {
  m_type = type;
  m_val = val;
  m_row = row;
  m_col = col;
}

TokenType Token::getType() const {
  return m_type;
}

const char* Token::strPatt = "(%r, %c) %t %v";

std::string Token::toStr() const {
  std::string s (strPatt);
  utils::replace(s, "%r", std::to_string(m_row));
  utils::replace(s, "%c", std::to_string(m_col));
  utils::replace(s, "%t", m_type);
  utils::replace(s, "%v", m_val);
  return s;
}
