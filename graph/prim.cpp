#include <cstddef>
#include <algorithm>
#include <type_traits>
#include <vector>
#include <limits>
#include <set>

class Graph {
public:
  std::size_t order() const;
  std::vector<std::size_t> neighbors(std::size_t) const;
  double edge_weight(std::size_t, std::size_t) const;
};

// retorna o vetor de antecessores
std::vector<std::ptrdiff_t> prim(const Graph& graph) {
  // vetor de antecessores
  std::vector<std::ptrdiff_t> predecessors(graph.order(), -1);

  // vetor de chaves
  std::vector<double> key(graph.order(), std::numeric_limits<double>::infinity());
  key[0] = 0.0;


  // Conjunto U e conjunto V\U
  std::set<std::size_t> VmU;
  for (std::size_t v = 0; v < graph.order(); ++v)
    VmU.insert(v);

  while (!VmU.empty())
  {
    std::size_t u = std::numeric_limits<std::size_t>::max();
    double min_key = std::numeric_limits<double>::infinity();
    for (const auto i : VmU) {
      if (key[i] < min_key) {
        min_key = key[i];
        u = i;
      }
    }

    // removo o argmin key de V\U
    VmU.erase(u);

    for (const auto v : graph.neighbors(u))
    {
      if (VmU.find(v) != VmU.end()) // v não está em U
      {
        if (graph.edge_weight(u, v) < key[v]) {
          key[v] = graph.edge_weight(u, v);
          predecessors[v] = u;
        }
      }
    }
  }

  return predecessors;
}
