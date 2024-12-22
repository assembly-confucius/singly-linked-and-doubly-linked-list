#include <gtest/gtest.h>
#include "../../DoubleList.h"

// Проверка доступа к первому элементу
TEST(AccessTests, Front) {
  DoubleList<int> list;
  list.push_front(1);
  EXPECT_EQ(list.front(), 1);
  list.push_front(2);
  EXPECT_EQ(list.front(), 2);
}

// Проверка доступа к последнему элементу
TEST(AccessTests, Back) {
  DoubleList<int> list;
  list.push_back(1);
  EXPECT_EQ(list.back(), 1);
  list.push_back(3);
  EXPECT_EQ(list.back(), 3);
}

// Проверка размера списка
TEST(AccessTests, Size) {
  DoubleList<int> list;
  EXPECT_EQ(list.size(), 0);
  list.push_back(1);
  EXPECT_EQ(list.size(), 1);
  list.push_front(2);
  EXPECT_EQ(list.size(), 2);
}

// Проверка, является ли список пустым
TEST(AccessTests, Empty) {
  DoubleList<int> list;
  EXPECT_TRUE(list.empty());
  list.push_back(1);
  EXPECT_FALSE(list.empty());
  list.pop_back();
  EXPECT_TRUE(list.empty());
}

// Проверка удаления первого элемента
TEST(ModificationTests, PopFront) {
  DoubleList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.pop_front();
  EXPECT_EQ(list.front(), 2);
  EXPECT_EQ(list.size(), 1);
}

// Проверка удаления последнего элемента
TEST(ModificationTests, PopBack) {
  DoubleList<int> list;
  list.push_front(1);
  list.push_front(2);
  list.pop_back();
  EXPECT_EQ(list.back(), 2);
  EXPECT_EQ(list.size(), 1);
}

// Проверка добавления элементов в начало и конец
TEST(ModificationTests, PushFrontAndBack) {
  DoubleList<int> list;
  list.push_front(1);
  list.push_back(2);
  list.push_front(0);
  EXPECT_EQ(list.front(), 0);
  EXPECT_EQ(list.back(), 2);
  EXPECT_EQ(list.size(), 3);
}

// Проверка метода clear()
TEST(ModificationTests, Clear) {
  DoubleList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_front(0);
  list.clear();
  EXPECT_EQ(list.size(), 0);
  EXPECT_TRUE(list.empty());
}

// Проверка исключений при доступе к элементам пустого списка
TEST(ExceptionTests, FrontOnEmptyList) {
  DoubleList<int> list;
  EXPECT_THROW(list.front(), std::out_of_range);
}

TEST(ExceptionTests, BackOnEmptyList) {
  DoubleList<int> list;
  EXPECT_THROW(list.back(), std::out_of_range);
}

TEST(ExceptionTests, PopFrontOnEmptyList) {
  DoubleList<int> list;
  EXPECT_THROW(list.pop_front(), std::out_of_range);
}

TEST(ExceptionTests, PopBackOnEmptyList) {
  DoubleList<int> list;
  EXPECT_THROW(list.pop_back(), std::out_of_range);
}
