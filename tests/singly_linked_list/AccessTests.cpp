#include <gtest/gtest.h>
#include "../../library.h"

TEST(AccessTests, Front) {
  OneList<int> list;
  list.push_front(1);
  EXPECT_EQ(list.front(), 1);
}

TEST(AccessTests, Back) {
  OneList<int> list;
  list.push_back(2);
  EXPECT_EQ(list.back(), 2);
}

TEST(AccessTests, Size) {
  OneList<int> list;
  EXPECT_EQ(list.size(), 0);
  list.push_back(1);
  EXPECT_EQ(list.size(), 1);
}

TEST(AccessTests, Empty) {
  OneList<int> list;
  EXPECT_TRUE(list.empty());
  list.push_back(1);
  EXPECT_FALSE(list.empty());
}
