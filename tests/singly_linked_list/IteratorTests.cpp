#include <gtest/gtest.h>
#include "../../library.h"

TEST(IteratorTests, ForwardIteration) {
  OneList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  auto it = list.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);

  EXPECT_EQ(it, list.end());
}

TEST(IteratorTests, ReverseIteration) {
  OneList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  auto it = list.end();
  EXPECT_EQ(*it, 3);
  --it;
  EXPECT_EQ(*it, 2);
  --it;
  EXPECT_EQ(*it, 1);
  --it;

  EXPECT_EQ(it, list.begin());
}
