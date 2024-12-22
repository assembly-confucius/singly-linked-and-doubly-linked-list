#include <gtest/gtest.h>
#include "../../DoubleList.h"

// Тест для удаления с переда
TEST(PopTests, PopFront) {
  DoubleList<int> list;
  list.push_front(1);
  list.push_front(2);
  list.pop_front();
  EXPECT_EQ(list.front(), 1);
  EXPECT_EQ(list.size(), 1);
}

// Тест для удаления с конца
TEST(PopTests, PopBack) {
  DoubleList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.pop_back();
  EXPECT_EQ(list.back(), 1);
  EXPECT_EQ(list.size(), 1);
}
