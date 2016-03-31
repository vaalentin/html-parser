#include <iostream>
#include<vector>
#include "Parser.h"
#include "Token.h"

Parser::Parser(const std::vector<Token>* toks) {
  m_toks = toks;
  m_pos = 0;
  m_tok = &m_toks->at(m_pos);
}

void Parser::parse() {
  while(m_pos < m_toks->size()) {
    next();
  }
}

void Parser::consume() {
  m_pos++;

  if(m_pos >= m_toks->size()) {
    m_pos = m_toks->size();
    return;
  }

  m_tok = &m_toks->at(m_pos);
}

void Parser::expect(const TokenType& t) {
  if(!match(t)) {
    std::cout << "ERROR: '" << t << "' expected" << std::endl;
    exit(1);
  }

  std::cout << t << " ";

  consume();
}

bool Parser::match(const TokenType& t) {
  return m_tok->getType() == t;
}

void Parser::next() {
  consume();
}
