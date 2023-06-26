#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include <chrono>
#define INF (int)1e8
using namespace std;
using namespace std::chrono;

typedef pair<int, int> ii;

const int MAX_WEIGHT = 20000;
const int N_ITEMS = 10;

vector<int> weights;
vector<int> values;


int main(){

    // weights equal 1, 1, 1 ... 1
    weights = vector<int>(N_ITEMS, 1);

    // values equal 1, 2, 3, ... N_ITEMS
    values = vector<int>(N_ITEMS);
    for(int i = 0; i < N_ITEMS; i++)
        values[i] = i+1;

    auto start = high_resolution_clock::now();

    unordered_map<int, int> distance;
    int source = 0;
    distance[source] = 0;

    priority_queue<ii> q; q.push({distance[source], source});
    int greatestValue = -1;

    while(!q.empty()){
        auto [dist, u] = q.top(); q.pop();
        if(dist > MAX_WEIGHT) break;
        if(dist > distance[u]) continue;
        greatestValue = max(greatestValue, u);
        for(int i = 0; i < N_ITEMS; i++){
            int v = u + values[i];
            int newDist = dist + weights[i];
            if(distance.find(v) != distance.end())
                if(distance[v] <= newDist)
                    continue;
            distance[v] = newDist;
            q.push({newDist, v});
        }
    }

    cout << greatestValue << endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;

    return 0;
}