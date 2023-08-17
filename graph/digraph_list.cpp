#include "digraph_list.hpp"

#include <algorithm>

Digraph::Digraph(std::size_t n) :
  adj_list_(n) {}

bool Digraph::edge_exists(std::size_t from, std::size_t to) const
{
  // assumindo que a lista está ordenada
  return std::binary_search(
      adj_list_[from].begin(),
      adj_list_[from].end(),
      to);
}

void Digraph::add_edge(std::size_t from, std::size_t to)
{
  auto lb = std::lower_bound(
      adj_list_[from].begin(),
      adj_list_[from].end(),
      to);

  if (*lb == to)
    return;

  adj_list_[from].insert(lb, to);
}

void Digraph::rem_edge(std::size_t from, std::size_t to) {
  auto lb = std::lower_bound(
      adj_list_[from].begin(),
      adj_list_[from].end(),
      to);

  if (*lb != to)
    return;

  adj_list_[from].erase(lb);
}

