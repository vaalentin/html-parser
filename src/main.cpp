#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "HtmlLexer.h"
#include "Token.h"

int main(int argc, char** argv) {
  if(argc < 2) {
    std::cout << "input file missing" << std::endl;
    exit(1);
  }

  const char* uri = *(argv + 1);

  std::ifstream file;
  file.open(uri);

  std::stringstream stream;
  stream << file.rdbuf();
  std::string src = stream.str();

  HtmlLexer lex(&src);
  std::vector<Token> toks = lex.getToks();

  for(auto t : toks) {
    std::cout << t.toStr() << std::endl;
  }

  return 0;
}
