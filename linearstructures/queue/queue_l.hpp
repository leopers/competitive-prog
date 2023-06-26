#pragma once

#include <memory>
#include <stdexcept>

// encadeada
template <typename T>
class Queue {
public:
  void enqueue(T value) {
    std::shared_ptr<Node> new_node = new Node{value, nullptr};
    last_->next = new_node;
    last_ = new_node;
  }

  void dequeue() {
    if (is_empty())
      throw std::runtime_error{"queue is empty"};

    head_->next = head_->next->next;

    if (head_->next == nullptr)
      last_ = head_;
  }

  void front() {

  }

  bool is_empty() const { return head_->next == nullptr; }
  // bool is_empty() const { return head_ == last_; }

private:
  struct Node {
    T value;
    std::shared_ptr<Node> next = nullptr;
  };

  // TODO: e se eu não tiver um nó cabeça
  std::shared_ptr<Node> head_ = std::unique_ptr<Node>(new Node);
  std::shared_ptr<Node> last_ = head_;
};
