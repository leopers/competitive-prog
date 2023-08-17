#include "graph_adj2.hpp"

Graph::Graph(std::size_t n) :
  matrix_(n * (n+1) / 2, false) {}

bool Graph::edge_exists(std::size_t from, std::size_t to) const
{
  check_vertex(from);
  check_vertex(to);

  if (from < to)
    std::swap(from, to);

  return matrix_[from * (from + 1) / 2 + to];
}


