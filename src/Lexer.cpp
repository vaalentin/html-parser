#include <cstring>
#include <string>
#include <vector>
#include "Lexer.h"

Lexer::Lexer(const std::string* src) {
  m_src = src;
  m_pos = 0;
  m_char = m_src->at(m_pos);
  m_row = 1;
  m_col = 1;
}

std::vector<Token> Lexer::getToks() {
  m_toks.clear();

  while(m_char != EOF) {
    next();
  }

  m_toks.push_back(Token ("EOF", "", m_row, m_col));

  return m_toks;
}

void Lexer::consume() {
  if(match('\n')) {
    m_row++;
    m_col = 1;
  }
  else {
    m_col++;
  }

  unsigned npos = m_pos + 1;

  if(npos == m_src->length()) {
    m_char = EOF;
  }
  else {
    m_pos = npos;
    m_char = m_src->at(m_pos);
  }
}

void Lexer::consume(int n) {
  for(int i = 0; i < n; ++i) {
    consume();
  }
}

bool Lexer::match(const char* s) {
  unsigned len = std::strlen(s);

  unsigned npos;
  char c;

  for(unsigned i = 0; i < len; ++i) {
    npos = m_pos + i;
    c = *(s + i);

    if(npos >= m_src->length() || m_src->at(npos) != c) {
      return false;
    }
  }

  return true;
}

bool Lexer::match(char c) {
  return m_char == c;
}

bool Lexer::peek(char c) {
  return m_pos + 1 < m_src->length()
    && m_src->at(m_pos + 1) == c;
}

void Lexer::next() {
  consume();
}
