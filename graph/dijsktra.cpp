#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <climits>

using namespace std;

typedef pair<int, int> pii;  // Pair of (weight, vertex)

class Graph {
    int V;
    vector<vector<pii>> adjList;

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void dijkstra(int source);
};

Graph::Graph(int V) {
    this->V = V;
    adjList.resize(V);
}

void Graph::addEdge(int u, int v, int w) {
    adjList[u].emplace_back(w, v);
    adjList[v].emplace_back(w, u);  // If the graph is undirected
}

void Graph::dijkstra(int source) {
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap
    vector<int> dist(V, INT_MAX);
    set<int> unvisited;

    dist[source] = 0;
    pq.push({0, source});

    for (int i = 0; i < V; ++i) {
        unvisited.insert(i);
    }

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        unvisited.erase(u);

        for (const pii& neighbor : adjList[u]) {
            int v = neighbor.second;
            int weight = neighbor.first;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print shortest distances from source
    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": " << dist[i] << endl;
    }
}

int main() {
    int V, E;  // Number of vertices and edges
    cin >> V >> E;

    Graph graph(V);

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }

    int source;
    cin >> source;

    graph.dijkstra(source);

    return 0;
}