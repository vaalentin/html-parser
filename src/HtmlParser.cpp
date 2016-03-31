#include <iostream>
#include "HtmlParser.h"
#include "HtmlTokenType.h"

void HtmlParser::next() {
  if(match(HtmlTokenType::L_TAG_OPEN)) {
    openTag();
  }
  else if(match(HtmlTokenType::L_TAG_CLOSE)) {
    closeTag();
  }
  else {
    consume();
  }
}

void HtmlParser::openTag() { 
  expect(HtmlTokenType::L_TAG_OPEN);

  expect(HtmlTokenType::ID);

  while(true) {
    if(!match(HtmlTokenType::ID)) {
      break;
    }

    option();
  }

  if(match(HtmlTokenType::R_TAG_OPEN)) {
    expect(HtmlTokenType::R_TAG_OPEN);

    // push to stack
  }
  else if(match(HtmlTokenType::R_TAG_CLOSE)) {
    expect(HtmlTokenType::R_TAG_CLOSE);
  }
  else {
    std::cout << "ERROR: > or /> expected";
    exit(1);
  }
}

void HtmlParser::closeTag() {
  expect(HtmlTokenType::L_TAG_CLOSE);

  expect(HtmlTokenType::ID);

  expect(HtmlTokenType::R_TAG_OPEN);

  // pop from stack
}

void HtmlParser::option() {
  expect(HtmlTokenType::ID);

  if(match(HtmlTokenType::ASSIGN)) {
    expect(HtmlTokenType::ASSIGN);

    expect(HtmlTokenType::VALUE);
  }
}

