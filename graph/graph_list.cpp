#include "graph_list.hpp"

// Graph(std::size_t n);

// bool edge_exists(std::size_t from, std::size_t to) const;

void Graph::add_edge(std::size_t from, std::size_t to)
{
  add_edge_directed(from, to);
  add_edge_directed(to, from);
}

// void rem_edge(std::size_t from, std::size_t to);
