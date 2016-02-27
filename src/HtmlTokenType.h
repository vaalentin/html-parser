#ifndef H_HTML_TOKEN_TYPE
#define H_HTML_TOKEN_TYPE

#include <string>
#include "TokenType.h"

namespace HtmlTokenType {
  extern const TokenType L_TAG_OPEN; // <
  extern const TokenType L_TAG_CLOSE; // </
  extern const TokenType L_TAG_DOCTYPE; // <!
  extern const TokenType R_TAG_OPEN; // >
  extern const TokenType R_TAG_CLOSE; // />
  extern const TokenType COMMENT_OPEN; // <!--
  extern const TokenType COMMENT_CLOSE; // -->
  extern const TokenType ASSIGN; // =
  extern const TokenType ID;
  extern const TokenType VALUE;
  extern const TokenType TEXT;
}

#endif
