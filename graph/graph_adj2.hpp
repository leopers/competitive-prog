#include <vector>

// Não direcionado e sem pesos nas arestas
// Armazena apenas o triângulo inferior
// Permite laços
class Graph {
public:
  Graph(std::size_t n);

  bool edge_exists(std::size_t from, std::size_t to) const;

  void add_edge(std::size_t from, std::size_t to);
  void rem_edge(std::size_t from, std::size_t to);

  std::vector<std::size_t> predecessors(std::size_t v) const;
  std::vector<std::size_t> successors(std::size_t v) const;
  std::vector<std::size_t> neighbors(std::size_t v) const;

  std::size_t order() const;

private:
  void check_vertex(std::size_t) const;

  std::vector<bool> matrix_;
};


// TODO: finalizar a implementação
// TODO: como ficaria um grafo com arestas múltiplas
// TODO: como ficaria um grafo ponderado?

