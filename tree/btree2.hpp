#ifndef BTREE_HPP
#define BTREE_HPP

#include <memory>
#include <ostream>
#include <queue>

template <typename T> class btree;
template <typename T>
using btree_ptr = std::shared_ptr<btree<T>>;

enum class node_ordering {
  in_order,
  pre_order,
  post_order,
};

template <typename T>
class btree : public std::enable_shared_from_this<btree<T>>
{
public:
  static btree_ptr<T> make() { return nullptr; }

  static btree_ptr<T> make(T value, btree_ptr<T> lchild = nullptr, btree_ptr<T> rchild = nullptr)
  {
    return btree_ptr<T>(new btree(std::move(value), std::move(lchild), std::move(rchild)));
  }

  bool search(const T& key) const {
    if (value_ == key)
      return true;

    if (lchild_ && lchild_->search(key))
      return true;

    if (rchild_ && rchild_->search(key))
      return true;

    return false;
  }

  T& value() { return value_; }
  const T& value() const { return value_; }

  btree_ptr<T> left_child() const { return lchild_; }
  btree_ptr<T> right_child() const { return rchild_; }

  std::size_t height() const
  {
    return max(
      (lchild_ ? lchild_->height() + 1 : 0),
      (rchild_ ? rchild_->height() + 1 : 0)
    );
  }

  void bfs(std::ostream os){
    std::queue<T> q;
    if(lchild_) q.push(lchild_);
    if(rchild_) q.push(rchild_);
    os << value_;

    while (!q.empty()) {
      auto node = q.front();
      q.pop();
      if(node->lchild_) q.push(node->lchild_);
      if(node->rchild_) q.push(node->rchild_);

      os << node->value_;
    } 
  }

  template <typename F> void dfs(node_ordering order, const F& f)
  {
    switch (order)
    {
    case node_ordering::in_order:
      if (lchild_) lchild_->dfs(order, f);
      f(this->shared_from_this());
      if (rchild_) rchild_->dfs(order, f);
      return;
    case node_ordering::pre_order:
      f(this->shared_from_this());
      if (lchild_) lchild_->dfs(order, f);
      if (rchild_) rchild_->dfs(order, f);
      return;
    case node_ordering::post_order:
      if (lchild_) lchild_->dfs(order, f);
      if (rchild_) rchild_->dfs(order, f);
      f(this->shared_from_this());
      return;
    }
  }

protected:
  btree() = default;

  btree(T value, btree_ptr<T> lchild, btree_ptr<T> rchild) :
    value_(std::move(value)),
    lchild_(std::move(lchild)),
    rchild_(std::move(rchild))
  {}

private:
  T value_;
  btree_ptr<T> lchild_, rchild_;
};

#endif // BTREE_HPP
