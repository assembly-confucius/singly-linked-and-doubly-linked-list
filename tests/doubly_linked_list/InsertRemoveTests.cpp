#include <gtest/gtest.h>
#include "../../DoubleList.h"

// Тест для вставки элемента в заданную позицию
TEST(InsertRemoveTests, InsertAtPosition) {
  DoubleList<int> list;
  list.push_back(1);
  list.push_back(3);
  list.insert(1, 2);
  EXPECT_EQ(list.size(), 3);
  EXPECT_EQ(list.front(), 1);
  EXPECT_EQ(list.back(), 3);
  EXPECT_EQ(list.front(), 1);
  EXPECT_EQ(list.back(), 3);
  EXPECT_EQ(list.size(), 3);
}

// Тест для удаления элемента по значению
TEST(InsertRemoveTests, RemoveByValue) {
  DoubleList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.remove(1);
  EXPECT_EQ(list.size(), 1);
  EXPECT_EQ(list.front(), 2);
  EXPECT_EQ(list.back(), 2);
}

// Тест для удаления первого элемента
TEST(InsertRemoveTests, RemoveFront) {
  DoubleList<int> list;
  list.push_front(1);
  list.push_front(2);
  list.pop_front();
  EXPECT_EQ(list.size(), 1);
  EXPECT_EQ(list.front(), 1);
}

// Тест для удаления последнего элемента
TEST(InsertRemoveTests, RemoveBack) {
  DoubleList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.pop_back();
  EXPECT_EQ(list.size(), 1);
  EXPECT_EQ(list.back(), 1);
}

// Тест для вставки элемента в пустой список
TEST(InsertRemoveTests, InsertIntoEmptyList) {
  DoubleList<int> list;
  list.insert(0, 1);
  EXPECT_EQ(list.size(), 1);
  EXPECT_EQ(list.front(), 1);
  EXPECT_EQ(list.back(), 1);
}

// Тест для вставки элемента на первую позицию
TEST(InsertRemoveTests, InsertAtFront) {
  DoubleList<int> list;
  list.push_back(2);
  list.push_back(3);
  list.insert(0, 1);
  EXPECT_EQ(list.front(), 1);
  EXPECT_EQ(list.size(), 3);
}

// Тест для вставки элемента в конец списка
TEST(InsertRemoveTests, InsertAtBack) {
  DoubleList<int> list;
  list.push_front(1);
  list.push_front(2);
  list.insert(2, 3);
  EXPECT_EQ(list.back(), 3);
  EXPECT_EQ(list.size(), 3);
}

// Тест для вставки элемента по несуществующей позиции
TEST(InsertRemoveTests, InsertAtInvalidPosition) {
  DoubleList<int> list;
  list.push_back(1);
  list.push_back(2);
  EXPECT_THROW(list.insert(5, 3), std::out_of_range);
}

// Тест для удаления по значению
TEST(InsertRemoveTests, RemoveByIndex) {
  DoubleList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.remove(1);
  EXPECT_EQ(list.size(), 2);
  EXPECT_EQ(list.front(), 2);
  EXPECT_EQ(list.back(), 3);
}

// Тест для удаления по индексу на пустом списке
TEST(InsertRemoveTests, RemoveByIndexOnEmptyList) {
  DoubleList<int> list;
  EXPECT_THROW(list.remove(0), std::out_of_range);
}
