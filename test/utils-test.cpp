#include "gtest/gtest.h"
#include "../src/utils.h"

#include <string>

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
