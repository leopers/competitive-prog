#pragma once

#include <memory>
#include <stdexcept>

// vetor circular
template <typename T>
class Queue {
public:
  void enqueue(T value) {
    values_[end_] = value;
    end_ = (end_ + 1) % capacity_;

    // TODO: dobrar a capacidade antes de cair no caso cheio
  }

  void dequeue() {
    if (is_empty())
      throw std::runtime_error{"empty queue"};

    begin_ = (begin_ + 1) % capacity_;
  }

  T front() const {
    return values_[begin_];
  }

  bool is_empty() const { return begin_ == end_; }

  // como implementar usando apenas begin e end
  std::size_t size() const {
    //TODO
  }

private:
  std::unique_ptr<T[]> values_ = std::unique_ptr<T[]>(new T[10]);
  std::size_t capacity_ = 10;
  std::size_t begin_ = 0, end_ = 0;
};
