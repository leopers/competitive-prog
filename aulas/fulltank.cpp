#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<tuple>
#include<utility>
#define INF 1e9
using namespace std;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

int n, m;
int full;
vector<int> weights;
vector<list<ii>> AL;

vector<iii> connections(ii state)
{
    vector<iii> connects;

    auto [u, fuel] = state;
    for(auto [v, distance] : AL[u])
    {
        for(int added = 0; added <= full - fuel; added++)
        {
            int new_fuel = fuel + added - distance;
            if(new_fuel < 0)
                continue;
            int cost = added * weights[u];
            connects.emplace_back(cost, v, new_fuel);
        }
    }

    return connects;
}

int main(){
    cin >> n >> m;

    weights = vector<int>(n);
    for(int i = 0; i < n; i++)
        cin >> weights[i];

    AL = vector<list<ii>>(n);
    for(int i = 0; i < m; i++)
    {
        int u, v, distance;
        cin >> u >> v >> distance;
        AL[u].push_back({v,distance});
        AL[v].push_back({u,distance});
    }

    int q; cin >> q;
    while(q--)
    {
        int source, destination;
        cin >> full >> source >> destination;
        vector<vector<int>> cost(n, vector<int>(full, INF));
        // min heap
        priority_queue<iii, vector<iii>, greater<iii>> q;
        cost[source][0] = 0;
        q.emplace(0, source, 0);

        int min_cost = INF;
        while(!q.empty())
        {
            auto [curr_cost, u, fuel] = q.top(); q.pop();
            if(curr_cost > cost[u][fuel])
                continue;
            if(u == destination)
            {
                min_cost = curr_cost;
                break;
            }

            for(auto [w, v, new_fuel] : connections({u, fuel}))
            {
                int next_cost = curr_cost + w;
                if(next_cost >= cost[v][new_fuel])
                    continue;
                cost[v][new_fuel] = next_cost;
                q.emplace(next_cost, v, new_fuel);
            }
        }

        if(min_cost >= INF)
            cout << "impossible" << endl;
        else
            cout << min_cost << endl;
    }

    return 0;
}