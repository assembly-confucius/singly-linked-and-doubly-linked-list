#include <gtest/gtest.h>
#include "../../library.h"

TEST(PushTests, PushFront) {
  OneList<int> list;
  list.push_front(1);
  list.push_front(2);
  EXPECT_EQ(list.front(), 2);
  EXPECT_EQ(list.size(), 2);
}

TEST(PushTests, PushBack) {
  OneList<int> list;
  list.push_back(1);
  list.push_back(2);
  EXPECT_EQ(list.back(), 2);
  EXPECT_EQ(list.size(), 2);
}
