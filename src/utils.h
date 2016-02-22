#ifndef H_UTILS
#define H_UTILS

#include <string>

namespace utils {
  extern const char* ws;
  bool isWs(char c);
  std::string& ltrim(std::string& s, const char* c = ws);
  std::string& rtrim(std::string& s, const char* c = ws);
  std::string& trim(std::string& s, const char* c = ws);
}

#endif
