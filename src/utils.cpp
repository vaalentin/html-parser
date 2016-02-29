#include <cstring>
#include <string>
#include "utils.h"

const char* utils::ws = " \t\n\r";

bool utils::isWs(char c) {
  int len = strlen(ws);

  for(int i = 0; i < len; ++i) {
    if(c == *(ws + i)) {
      return true;
    }
  }

  return false;
}

std::string& utils::ltrim(std::string& s, const char* c) {
  s.erase(0, s.find_first_not_of(c));
  return s;
}

std::string& utils::rtrim(std::string& s, const char* c) {
  s.erase(s.find_last_not_of(c) + 1);
  return s;
}

std::string& utils::trim(std::string& s, const char* c) {
  return ltrim(rtrim(s, c), c);
}

std::string& utils::replace(std::string& s, const std::string& f, const std::string& t) {
  size_t fpos = s.find(f);

  if(fpos == std::string::npos) {
    return s;
  }

  s.replace(fpos, f.length(), t);

  return s;
}
