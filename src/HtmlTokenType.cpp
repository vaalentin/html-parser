#include <string>
#include "TokenType.h"
#include "HtmlTokenType.h"

const TokenType HtmlTokenType::L_TAG_OPEN = "<";
const TokenType HtmlTokenType::L_TAG_CLOSE = "</";
const TokenType HtmlTokenType::L_TAG_DOCTYPE = "<!";
const TokenType HtmlTokenType::R_TAG_OPEN = ">";
const TokenType HtmlTokenType::R_TAG_CLOSE = "/>";
const TokenType HtmlTokenType::COMMENT_OPEN = "<!--";
const TokenType HtmlTokenType::COMMENT_CLOSE = "-->";
const TokenType HtmlTokenType::ASSIGN = "=";
const TokenType HtmlTokenType::ID = "ID";
const TokenType HtmlTokenType::VALUE = "VALUE";
const TokenType HtmlTokenType::TEXT = "TEXT";
