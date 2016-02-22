#include <cstring>
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

