#pragma once

#include <memory>
#include <stdexcept>

template <typename T>
class Stack {
public:
  void push(T value) {
    if (size_ == capacity_)
      reserve(2 * size_ + 1);

    values_[size_] = value;
    ++size_;
  }

  void pop() {
    if (size_ == 0)
      throw std::runtime_error{"poxa cara... vacilou"};
    --size_;
  }

  T& top() {
    if (size_ == 0)
      throw std::runtime_error{"poxa cara... só mancada."};
    return values_[size_ - 1];
  }

  bool is_empty() const {
    return size_ == 0;
  }

  void reserve(std::size_t capacity) {
    if (capacity <= capacity_)
      throw std::runtime_error{"cannot shrink"};

    auto tmp = std::unique_ptr<T[]>(new T[capacity]);
    for (std::size_t i = 0; i < size_; ++i)
      tmp[i] = values_[i];

    values_ = std::move(tmp);
    capacity_ = capacity;
  }

private:
  std::unique_ptr<T[]> values_ = nullptr;
  std::size_t size_ = 0;
  std::size_t capacity_ = 0;
};
