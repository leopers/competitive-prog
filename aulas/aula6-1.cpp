#include "stdc++.h"
using namespace std;
typedef pair<int, int> ii;

// Adjacency List
vector<list<ii>> AL;

int main()
{
    string data =
    "6\n" // number of vertices
    "0 1 10\n" // u, v, weight (the connections here are undirected)
    "0 2 3\n"
    "2 3 1\n"
    "3 4 7\n"
    "2 5 2\n";

    stringstream input(data);

    // problem starts here
    int n; input >> n;

    AL = vector<list<ii>>(n); // standard constructor for vector. Now we have n empty lists

    // I am closing this snippet inside curly braces so the variables
    // u, v and w can be reused later
    {
        int u, v, w;
        while(input >> u >> v >> w)
        {
            // The curly braces {} with two elements inside return a pair
            AL[u].push_back({w, v});
            AL[v].push_back({w, u});
        }
    }

    for(int u = 0; u < n; u++)
    {
        cout << "Neighbors of " << u << ":" << endl;
        for(auto [w, v] : AL[u])
            cout << "    " << v << ", weight = " << w << endl;
    }

    return 0;
}