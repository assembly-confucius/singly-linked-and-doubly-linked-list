#include <gtest/gtest.h>
#include "../../DoubleList.h"

// Тест для добавления элемента в начало
TEST(PushTests, PushFront) {
  DoubleList<int> list;
  list.push_front(1);
  list.push_front(2);
  EXPECT_EQ(list.front(), 2);
  EXPECT_EQ(list.size(), 2);
}

// Тест для добавления элемента в конец
TEST(PushTests, PushBack) {
  DoubleList<int> list;
  list.push_back(1);
  list.push_back(2);
  EXPECT_EQ(list.back(), 2);
  EXPECT_EQ(list.size(), 2);
}
