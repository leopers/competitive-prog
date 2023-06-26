#pragma once

#include <memory>

template <typename T>
class LinkedList {
private:
  struct Node {
    T value;
    std::shared_ptr<Node> next;
  };

public:
  class Iterator {
    friend class LinkedList;
  public:
    const T& value() const { return node_->next->value; }
    const T& operator*() const { return node_->next->value; }
    void operator++() { node_ = node_->next; }

  private:
    std::shared_ptr<Node> node_;
  };

  std::size_t size() const { return size_; }

  // void insert(std::size_t pos, T value); // pos é um índice numérico

  void insert(Iterator pos, const T& value) {
    std::shared_ptr<Node> before = pos.node_;

    before->next = std::shared_ptr<Node>(new Node);
    before->next->value = value;
    before->next->next = pos.node_->next;

    ++size_;
  }

  Iterator begin() const {
    Iterator b;
    b.node_ = head_;
    return b;
  }

private:
  std::shared_ptr<Node> head_ = std::shared_ptr<Node>(new Node);
  std::size_t size_ = 0u;
};
