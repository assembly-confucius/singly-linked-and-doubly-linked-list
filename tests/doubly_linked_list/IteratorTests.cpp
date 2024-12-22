#include <gtest/gtest.h>
#include "../../DoubleList.h"


// Тест для итерации вперёд
TEST(IteratorTests, ForwardIteration) {
  DoubleList<int> list;
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

// Тест для итерации назад
TEST(IteratorTests, ReverseIteration) {
  DoubleList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  auto it = list.end();
  EXPECT_EQ(*it, 3);
  --it;
  EXPECT_EQ(*it, 2);
  --it;
  EXPECT_EQ(*it, 1);

  EXPECT_EQ(it, list.begin());
}
