#include <iostream>
#include "HtmlLexer.h"
#include "utils.h"
#include "HtmlTokenType.h"

void HtmlLexer::next() {
  if(match("<!--")) {
    comment();
  }
  else if(match('<')) {
    tag();
  }
  else {
    text();
  }
}

void HtmlLexer::whitespace() {
  while(utils::isWs(m_char)) {
    consume();
  }
}

void HtmlLexer::tag() {
  if(peek('!')) {
    m_toks.push_back(Token (HtmlTokenType::L_TAG_DOCTYPE, m_row, m_col));
    consume(2); // <!
  }
  else if(peek('/')) {
    m_toks.push_back(Token (HtmlTokenType::L_TAG_CLOSE, m_row, m_col));
    consume(2); // </
  }
  else {
    m_toks.push_back(Token (HtmlTokenType::L_TAG_OPEN, m_row, m_col));
    consume(); // <
  }

  whitespace();

  id();

  TokenType type;

  int row;
  int col;

  while(true) {
    if(match('=')) {
      m_toks.push_back(Token (HtmlTokenType::ASSIGN, m_row, m_col));
      consume();
    }
    else if(match('"')) {
      value();
    }
    else if(match("/>")) {
      type = HtmlTokenType::R_TAG_CLOSE;
      row = m_row;
      col = m_col;
      consume(2); // />
      break;
    }
    else if(match('>')) {
      type = HtmlTokenType::R_TAG_OPEN;
      row = m_row;
      col = m_col;
      consume(); // >
      break;
    }
    else if(match(EOF)) {
      row = m_row;
      col = m_col;
      break;
    }
    else {
      id();
    }
  }

  m_toks.push_back(Token (type, row, col));
}

void HtmlLexer::comment() {
  m_toks.push_back(Token (HtmlTokenType::COMMENT_OPEN, m_row, m_col));

  consume(4); // <!--

  whitespace();

  int row = m_row;
  int col = m_col;

  m_buf.clear();

  while(true) {
    if(match("-->") || match(EOF)) {
      break;
    }

    m_buf += m_char;
    consume();
  }

  utils::rtrim(m_buf);

  if(m_buf.length() > 0) {
    m_toks.push_back(Token (HtmlTokenType::TEXT, m_buf, row, col));
  }

  m_toks.push_back(Token (HtmlTokenType::COMMENT_CLOSE, m_row, m_col));

  consume(3); // -->
}

void HtmlLexer::id() {
  whitespace();

  int row = m_row;
  int col = m_col;

  m_buf.clear();

  while(true) {
    if(match(' ') || match("/>") || match('>') || match('=') || match(EOF)) {
      break;
    }

    m_buf += m_char;
    consume();
  }

  if(m_buf.length() > 0) {
    m_toks.push_back(Token (HtmlTokenType::ID, m_buf, row, col));
  }
}

void HtmlLexer::value() {
  consume(); // "

  int row = m_row;
  int col = m_col;

  m_buf.clear();

  while(true) {
    if(match('"') || match(EOF)) {
      break;
    }

    m_buf += m_char;
    consume();
  }

  consume(); // "

  if(m_buf.length() > 0) {
    m_toks.push_back(Token (HtmlTokenType::VALUE, m_buf, row, col));
  }
}

void HtmlLexer::text() {
  whitespace();

  int row = m_row;
  int col = m_col;

  m_buf.clear();

  while(true) {
    if(match('<') || match(EOF)) {
      break;
    }

    m_buf += m_char;
    consume();
  }

  utils::rtrim(m_buf);

  if(m_buf.length() > 0) {
    m_toks.push_back(Token (HtmlTokenType::TEXT, m_buf, row, col));
  }
}
