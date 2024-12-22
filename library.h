#pragma once

#include <cstddef>
#include <iostream>
#include <stdexcept>

template<typename T>
class OneList {
  struct Node {
    T data;
    Node *next;
    explicit Node(const T &data) : data(data), next(nullptr) {}
  };

  Node *head;
  Node *tail;
  size_t listSize;

public:
  OneList() : head(nullptr), tail(nullptr), listSize(0) {}
  ~OneList() { clear(); }

  void push_front(const T &value) {
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    if (listSize == 0) {
      tail = newNode;
    }
    listSize++;
  }

  void push_back(const T &value) {
    Node *newNode = new Node(value);
    if (tail) {
      tail->next = newNode;
    } else {
      head = newNode;
    }
    tail = newNode;
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
    Node *newNode = new Node(value);
    Node *current = head;
    for (int i = 0; i < index - 1; ++i) {
      current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    if (newNode->next == nullptr) {
      tail = newNode;
    }
    listSize++;
  }

  void pop_front() {
    if (empty()) {
      throw std::out_of_range("List is empty");
    }
    const Node *temp = head;
    head = head->next;
    delete temp;
    listSize--;
    if (listSize == 0) {
      tail = nullptr;
    }
  }

  void pop_back() {
    if (empty()) {
      throw std::out_of_range("List is empty");
    }
    if (head == tail) {
      delete head;
      head = tail = nullptr;
    } else {
      Node *current = head;
      while (current->next != tail) {
        current = current->next;
      }
      delete tail;
      tail = current;
      tail->next = nullptr;
    }
    listSize--;
  }

  void remove(const T &value) {
    if (empty())
      return;
    if (head->data == value) {
      pop_front();
      return;
    }
    Node *current = head;
    while (current->next && current->next->data != value) {
      current = current->next;
    }
    if (current->next) {
      Node *temp = current->next;
      current->next = temp->next;
      if (temp == tail) {
        tail = current;
      }
      delete temp;
      listSize--;
    }
  }

  void clear() {
    while (!empty()) {
      pop_front();
    }
  }

  T &at(const size_t index) {
    if (index >= listSize) {
      throw std::out_of_range("Index out of range");
    }
    Node *current = head;
    for (size_t i = 0; i < index; ++i) {
      current = current->next;
    }
    return current->data;
  }

  Node *find(const T &value) {
    Node *current = head;
    while (current) {
      if (current->data == value) {
        return current;
      }
      current = current->next;
    }
    return nullptr;
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
    OneList *list;

  public:
    explicit Iterator(Node *node, OneList *parent) : current(node), previous(nullptr), list(parent) {
      if (current == nullptr && list->tail) {
        current = list->tail;
      }
    }

    T &operator*() const { return current->data; }

    Iterator &operator++() {
      previous = current;
      current = current->next;
      return *this;
    }

    Iterator operator++(int) {
      Iterator temp = *this;
      ++(*this);
      return temp;
    }

    Iterator &operator--() {
      if (current == nullptr) {
        current = list->tail;
      } else if (current == list->head) {
        current = nullptr;
      } else {
        Node *temp = list->head;
        while (temp != nullptr && temp->next != current) {
          temp = temp->next;
        }

        if (temp == nullptr) {
          std::cerr << "Error: previous node not found" << std::endl;
          current = nullptr;
        } else {
          current = temp;
        }
      }

      std::cout << "After decrement: " << (current ? std::to_string(current->data) : "nullptr") << std::endl;
      return *this;
    }

    bool operator==(const Iterator &other) const { return current == other.current; }

    bool operator!=(const Iterator &other) const { return current != other.current; }
  };

  Iterator begin() { return Iterator(head, this); }
  Iterator end() { return Iterator(nullptr, this); }
};
