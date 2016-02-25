#ifndef H_TOKEN
#define H_TOKEN

#include <string>

class Token {
  private:
    const char* m_type;
    std::string m_val;
    int m_row;
    int m_col;

  public:
    Token(const char* type, std::string val, int row, int col);
    std::string toStr();
};

#endif
