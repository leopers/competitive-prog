#include "digraph_adj2.hpp"

Digraph::Digraph(std::size_t n) :
  matrix_(n * n, false)
{}


bool Digraph::edge_exists(std::size_t from, std::size_t to) const
{
  return matrix_[order() * from + to];
}
