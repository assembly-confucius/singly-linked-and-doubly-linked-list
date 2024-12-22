#include <gtest/gtest.h>
#include "../../library.h"

TEST(InsertRemoveTests, InsertAtPosition) {
  OneList<int> list;
  list.push_back(1);
  list.push_back(3);
  list.insert(1, 2);
  EXPECT_EQ(list.size(), 3);
  EXPECT_EQ(list.front(), 1);
}

TEST(InsertRemoveTests, RemoveByValue) {
  OneList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.remove(1);
  EXPECT_EQ(list.size(), 1);
  EXPECT_EQ(list.front(), 2);
}
