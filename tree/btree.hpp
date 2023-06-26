#ifndef BTREE_HPP
#define BTREE_HPP

#include <memory>

template <typename T> class BinaryTree;

template <typename T>
using BinaryTreePtr = std::shared_ptr<BinaryTree<T>>;

template <typename T>
class BinaryTree
{
public:
  static BinaryTreePtr<T> make() { return nullptr; }

  static BinaryTreePtr<T> make(T value, BinaryTreePtr<T> lchild = nullptr, BinaryTreePtr<T> rchild = nullptr)
  {
    return BinaryTreePtr<T>(new BinaryTree(std::move(value), std::move(lchild), std::move(rchild)));
  }

  T& value() { return value_; }
  const T& value() const { return value_; }

  BinaryTreePtr<T> left_child() const { return lchild_; }
  BinaryTreePtr<T> right_child() const { return rchild_; }

private:
  BinaryTree(T value, BinaryTreePtr<T> lchild, BinaryTreePtr<T> rchild) :
    value_(std::move(value)),
    lchild_(std::move(lchild)),
    rchild_(std::move(rchild))
  {}

  T value_;
  BinaryTreePtr<T> lchild_, rchild_;
};

template <typename T>
bool search(BinaryTreePtr<T> root, const T& key)
{
  if (root == nullptr)
    return false;

  if (root->value() == key)
    return true;

  return search(root->left_child(), key) ||
    search(root->right_child(), key);
}

template <typename T>
std::size_t height(BinaryTreePtr<T> root)
{
  if (root == nullptr)
    return 0;

  return 1 + max(
      height(root->left_child()),
      height(root->right_child()));
}

template <typename T, typename F>
void dfs_pre_order(
    BinaryTreePtr<T> root, const F& visitor)
{
  if (root == nullptr)
    return;

  visitor(root);
  dfs_pre_order(root->left_child(), visitor);
  dfs_pre_order(root->right_child(), visitor);
}

// TODO: implementar o restante das operações como funções livres
//

#endif // BTREE_HPP
