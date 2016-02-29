#include "gtest/gtest.h"
#include "../src/utils.h"

#include <string>

/*
 * utils::isWs(char c)
 */

TEST(isWhitespace, whitespace) {
  EXPECT_EQ(true, utils::isWs(' '));
}

TEST(isWhitespace, tab) {
  EXPECT_EQ(true, utils::isWs('\t'));
}

TEST(isWhitespace, newLine) {
  EXPECT_EQ(true, utils::isWs('\n'));
}

TEST(isWhitespace, carriageReturn) {
  EXPECT_EQ(true, utils::isWs('\r'));
}

/**
 * utils::ltrim(std::string& s, const char* c = ws)
 */

TEST(leftTrim, whitespaces) {
  std::string s = "   test";
  EXPECT_EQ("test", utils::ltrim(s));
}

TEST(leftTrim, mixedSpaces) {
  std::string s = "\n \t \r  test";
  EXPECT_EQ("test", utils::ltrim(s));
}

TEST(leftTrim, emptyString) {
  std::string s = "";
  EXPECT_EQ("", utils::ltrim(s));
}

/**
 * utils::rtrim(std::string& s, const char* c = ws)
 */

TEST(rightTrim, right_trim) {
  std::string s = "test   ";
  EXPECT_EQ(s, utils::rtrim(s));
}

TEST(rightTrim, mixedSpaces) {
  std::string a = "test \n \t \r";
  EXPECT_EQ("test", utils::rtrim(a));
}

TEST(rightTrim, emptyString) {
  std::string s = "";
  EXPECT_EQ("", utils::rtrim(s));
}

/**
 * utils::trim(std::string& s, const char* c = ws)
 */

TEST(trim, trim) {
  std::string s = "   test   ";
  EXPECT_EQ("test", utils::trim(s));
}

TEST(trim, mixedSpaces) {
  std::string s = "\n \t \r test \n \t \r";
  EXPECT_EQ("test", utils::trim(s));
}

TEST(trim, emptyString) {
  std::string s = "";
  EXPECT_EQ("", utils::trim(s));
}

/**
 * utils::replace(std::string& s, const std::string& f, const std::string& t);
 */

TEST(replace, simple) {
  std::string s = "Hello, {{placeholder}}!";
  utils::replace(s, "{{placeholder}}", "World");
  EXPECT_EQ("Hello, World!", s);
}

TEST(replace, successive) {
  std::string s = "%m-%d-%y";
  const char* d = "23";
  const char* m = "Oct";
  const char* y = "1962";

  utils::replace(s, "%d", d);
  EXPECT_EQ("%m-23-%y", s);
  utils::replace(s, "%m", m);
  EXPECT_EQ("Oct-23-%y", s);
  utils::replace(s, "%y", y);
  EXPECT_EQ("Oct-23-1962", s);
}
