#pragma once

#include <stdexcept>

template <typename T>
class LinkedList {
public:
  ~LinkedList() {
    clear(first);
  }

  // calcular a complexidade de tempo
  void insert(T element, int pos) {
    if (pos == 0) {
      first = new Node(element, first);
    } else {
      Node* where = access(pos - 1);
      where->next = new Node(element, where->next);
    }
  }

  void remove(int pos); // implementar e calcular a complexidade de tempo
  bool search(const T& key) const; // implementar e calcular a complexidade de tempo

private:
  struct Node {
    T value;
    Node* next;
  };

  Node* access(int pos) const {
    Node* result = first;
    if (result == nullptr)
      throw std::out_of_range{""};

    while (pos > 0) {
      result = result->next;
      if (result == nullptr)
        throw std::out_of_range{""};
      --pos;
    }

    return result;
  }

  // usar shared_ptr ao invés de naked pointer
  void clear(Node* ptr) {
    if (ptr == nullptr)
      return;

    clear(ptr->next);
    delete ptr;
  }

  Node* first = nullptr;
};
