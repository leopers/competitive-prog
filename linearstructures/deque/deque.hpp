#pragma once

#include <memory>
#include <stdexcept>

// duplamente encadeada
// TODO: para casa, duplamente encadeada, circular, com nó cabeça
template <typename T>
class Deque {
public:
  ~Deque() {
    // aqui seria necessário fazer todos os before = nullptr
  }

  void insert_last(T value) {
    std::shared_ptr<Node> new_node = new Node{value, nullptr, nullptr};

    if (is_empty()) {
      begin_ = last_ = new_node;
    } else {
      last_->next = new_node;
      new_node->before = last_;
      last_ = new_node;
    }
  }

  void insert_first(T value) {

  }

  void remove_last() {
    if (is_empty())
      throw std::runtime_error{"empty deque"};

    if (last_->before == nullptr) {
      begin_ = last_ = nullptr;
    } else {
      last_->before->next = nullptr;
      last_ = last_->before;
    }
  }

  void remove_first() {

  }

  bool is_empty() const { return begin_ == nullptr; }
  // bool is_empty() const { return last_ == nullptr; }

private:
  struct Node {
    T value;
    std::shared_ptr<Node> before = nullptr, next = nullptr;
  };

  std::shared_ptr<Node> begin_ = nullptr;
  std::shared_ptr<Node> last_ = nullptr;
};
