#include "digraph_adj.hpp"

#include <stdexcept>

Digraph::Digraph(std::size_t n) :
  matrix_(n, std::vector<bool>(n, false))
{}

bool Digraph::edge_exists(std::size_t from, std::size_t to) const
{
  check_vertex(from);
  check_vertex(to);
  return matrix_[from][to];
}


void Digraph::add_edge(std::size_t from, std::size_t to)
{
  check_vertex(from);
  check_vertex(to);
  matrix_[from][to] = true;
}

void Digraph::check_vertex(std::size_t v) const {
  if (v >= order())
    throw std::out_of_range{"vertex does not exist"};
}

std::vector<std::size_t> Digraph::successors(std::size_t v) const{
  std::vector<std::size_t> s;
  for (std::size_t to = 0; to < order(); ++to)
    if (edge_exists(v, to))
      s.push_back(to);
  return s;
}

std::size_t Digraph::order() const {
  return matrix_.size();
}
