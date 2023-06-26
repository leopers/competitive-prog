#pragma once

#include <memory>
#include <stdexcept>

template <typename T>
class Stack {
public:
  void push(T value) {
    auto new_node = std::unique_ptr<Node>(new Node);
    new_node->value = value;
    new_node->next = std::move(top_);
    top_ = std::move(new_node);

    // top_ = std::unique_ptr<Node>(new node{std::move(value), std::move(top_)});
  }

  void pop() {
    top_ = std::move(top_->next);
  }

  T& top() {
    return top_->value;
  }

  bool is_empty() const { return top_ == nullptr; }

private:
  struct Node {
    T value;
    std::unique_ptr<Node> next;
  };
  std::unique_ptr<Node> top_ = nullptr;
};
