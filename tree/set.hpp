#pragma once

#include <cstddef>
#include <vector>
#include <optional>
#include <stdexcept>
#include <iostream>

// Copia toda a sub-árvore a partir de j no ramo a partir de i.
// Assume que input é menor que output.
template <typename T>
void preorder_copy(
    std::vector<std::optional<T>>& tree, std::size_t i, std::size_t j)
{
  if (i >= tree.size())
    return;

  tree[i] = tree[j];
  preorder_copy(tree, 2 * i + 1, 2 * j + 1);
  preorder_copy(tree, 2 * i + 2, 2 * j + 2);
}

template <typename T>
class Set
{
public:
  void insert(const T& value) {
    insert_recursive(0, value);
  }

  void remove(const T& value) {
    remove_recursive(0, value);
  }

  bool search(const T& value) const {
    return search_recursive(0, value);
  }

  Set set_union(const Set&) const;
  Set set_intersection(const Set&) const;
  Set set_diff(const Set&) const;
  void print() const;

  void print_tree() const {
    print_tree_recursive(0);
    std::cout << '\n';
  }

private:
  void print_tree_recursive(std::size_t i) const {
    if (!values_[i].has_value()) {
      std::cout << "()";
      return;
    }
    std::cout << "(" << values_[i].value();
    print_tree_recursive(2 * i + 1);
    print_tree_recursive(2 * i + 2);
    std::cout << ")";
  }

  bool search_recursive(
      std::size_t pos, const T& value) const {

    if (pos >= values_.size() ||
        !values_[pos].has_value())
      return false;

    if (values_[pos].value() == value)
      return true;

    return search_recursive(
        value < values_[pos].value() ?
          2 * pos + 1 : 2 * pos + 2,
        value);
  }

  void insert_recursive(
      std::size_t pos, const T& value) {

    // caso que não há mais espaço no vetor
    if (pos >= values_.size()) {
      // TODO: pensar em política baseada na altura
      // da árvore
      values_.resize(
          std::max(2 * values_.size() + 1, pos + 1));

      values_[pos] = value;
      return;
    }

    if (!values_[pos].has_value()) {
      values_[pos] = value;
      return;
    }

    if (values_[pos].value() == value)
      return;

    return insert_recursive(
        value < values_[pos].value() ?
          2 * pos + 1 : 2 * pos + 2,
        value);
  }

  void remove_recursive(
      std::size_t pos, const T& value) {

    if (pos >= values_.size() ||
        !values_[pos].has_value())
      return;

    if (values_[pos].value() == value) {
      // caso 1: pos é folha
      if (is_leaf(pos)) {
        values_[pos] = std::nullopt;
        return;
      }

      // caso 2: pos tem um único filho
      if (number_of_children(pos) == 1) {
        std::size_t c = child(pos);
        // copia toda a sub-árvore
        preorder_copy(values_, pos, c);
        return;
      }

      // caso 3: pos tem dois filhos
      std::size_t c = left_most(2 * pos + 2); // filho mais a esquerda da sub-árvore à
                                              // direita
      values_[pos] = values_[c];
      remove_recursive(c, values_[c].value());
    }

    remove_recursive(
        value < values_[pos].value() ?
          2 * pos + 1 : 2 * pos + 2,
        value);
  }

  std::size_t number_of_children(
      std::size_t pos) const {
    std::size_t n = 0;
    if (node_exists(2 * pos + 1))
      ++n;
    if (node_exists(2 * pos + 2))
      ++n;
    return n;
  }

  bool node_exists(std::size_t pos) const {
    return pos < values_.size() &&
      values_[pos].has_value();
  }

  bool is_leaf(std::size_t pos) const {
    return number_of_children(pos) == 0;
  }

  std::size_t child(std::size_t pos) const {
    if (node_exists(2 * pos + 1))
      return 2 * pos + 1;
    if (node_exists(2 * pos + 2))
      return 2 * pos + 2;
    throw std::runtime_error{"no child found"};
  }

  std::size_t left_most(std::size_t pos) const {
    if (!node_exists(2 * pos + 1))
      return pos;
    return left_most(2 * pos + 1);
  }

  std::vector<std::optional<T>> values_;
};
