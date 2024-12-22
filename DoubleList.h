#pragma once

#include <cstddef>
#include <iostream>
#include <stdexcept>

template<typename T>
class DoubleList {
  struct Node {
    T data;
    Node *prev;
    Node *next;
    explicit Node(const T &data) : data(data), prev(nullptr), next(nullptr) {}
  };

  Node *head;
  Node *tail;
  size_t listSize;

public:
  DoubleList() : head(nullptr), tail(nullptr), listSize(0) {}
  ~DoubleList() { clear(); }

  void push_front(const T &value) {
    Node *newNode = new Node(value);
    newNode->next = head;
    if (head) {
      head->prev = newNode;
    }
    head = newNode;
    if (!tail) {
      tail = newNode;
    }
    listSize++;
  }

  void push_back(const T &value) {
    Node *newNode = new Node(value);
    newNode->prev = tail;
    if (tail) {
      tail->next = newNode;
    }
    tail = newNode;
    if (!head) {
      head = newNode;
    }
    listSize++;
  }

  void insert(const int index, const T &value) {
    if (index < 0 || index > listSize) {
      throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
      push_front(value);
      return;
    }
    if (index == listSize) {
      push_back(value);
      return;
    }

    Node *newNode = new Node(value);
    Node *current = head;
    for (int i = 0; i < index; ++i) {
      current = current->next;
    }
    newNode->prev = current->prev;
    newNode->next = current;
    if (current->prev) {
      current->prev->next = newNode;
    }
    current->prev = newNode;
    listSize++;
  }

  void pop_front() {
    if (empty()) {
      throw std::out_of_range("List is empty");
    }
    const Node *temp = head;
    head = head->next;
    if (head) {
      head->prev = nullptr;
    } else {
      tail = nullptr;
    }
    delete temp;
    listSize--;
  }

  void pop_back() {
    if (empty()) {
      throw std::out_of_range("List is empty");
    }
    const Node *temp = tail;
    tail = tail->prev;
    if (tail) {
      tail->next = nullptr;
    } else {
      head = nullptr;
    }
    delete temp;
    listSize--;
  }

  void remove(const T &value) {
    if (empty()) {
      throw std::out_of_range("Attempt to remove from empty list");
    }
    Node *current = head;
    while (current) {
      if (current->data == value) {
        if (current == head) {
          head = current->next;
          if (head) {
            head->prev = nullptr;
          }
        } else if (current == tail) {
          tail = current->prev;
          if (tail) {
            tail->next = nullptr;
          }
        } else {
          current->prev->next = current->next;
          current->next->prev = current->prev;
        }

        delete current;
        --listSize;
        return;
      }
      current = current->next;
    }
  }

  void clear() {
    while (!empty()) {
      pop_front();
    }
  }

  [[nodiscard]] size_t size() const { return listSize; }
  [[nodiscard]] bool empty() const { return listSize == 0; }

  T &front() {
    if (empty()) {
      throw std::out_of_range("List is empty");
    }
    return head->data;
  }

  T &back() {
    if (empty()) {
      throw std::out_of_range("List is empty");
    }
    return tail->data;
  }

  class Iterator {
    Node *current;
    Node *previous;
    DoubleList *list;

  public:
    explicit Iterator(Node *node, DoubleList *parent) : current(node), previous(nullptr), list(parent) {}

    T &operator*() const { return current->data; }

    Iterator &operator++() {
      current = current->next;
      return *this;
    }

    Iterator operator++(int) {
      Iterator temp = *this;
      ++(*this);
      return temp;
    }

    Iterator &operator--() {
      std::cout << "Before decrement: " << (current ? std::to_string(current->data) : "nullptr") << std::endl;

      if (current == nullptr) {
        // Позиция после последнего элемента - сдвигаем на последний элемент списка.
        current = list->tail;
      } else if (current->prev == nullptr) {
        // Если итератор на первом элементе - сдвигаем его в "перед началом", т.е. на nullptr.
        current = nullptr;
      } else {
        // В остальных случаях сдвигаем на предыдущий элемент.
        current = current->prev;
      }

      std::cout << "After decrement: " << (current ? std::to_string(current->data) : "nullptr") << std::endl;
      return *this;
    }

    bool operator==(const Iterator &other) const { return current == other.current; }
    bool operator!=(const Iterator &other) const { return current != other.current; }
  };

  Iterator begin() { return Iterator(head, this); }
  Iterator end() { return Iterator(tail, this); }
};
