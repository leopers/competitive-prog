#include<iostream>
#include<vector>
#include <chrono>
#define INF (int)1e8
using namespace std;
using namespace std::chrono;

const int MAX_WEIGHT = 20000;
const int N_ITEMS = 10;

int memo[N_ITEMS][MAX_WEIGHT + 1];
vector<int> weights;
vector<int> values;

void initializeMemo(){
    for(int i = 0; i < N_ITEMS; i++)
        for(int j = 0; j < MAX_WEIGHT + 1; j++)
            memo[i][j] = -1;
}

// return max possible remaining value
int dpUnboundedKnapsack(int currentItem, int currentWeight){
    if(currentItem == N_ITEMS)
        return 0;

    int& ans = memo[currentItem][currentWeight];
    if(ans != -1)
        return ans;

    int dontTake = dpUnboundedKnapsack(currentItem + 1, currentWeight);

    int newWeight = currentWeight + weights[currentItem];
    if(newWeight > MAX_WEIGHT)
        return ans = dontTake;

    int take = dpUnboundedKnapsack(currentItem, newWeight) + values[currentItem];

    return ans = max(take, dontTake);
}

int main(){
    initializeMemo();

    // weights equal 1, 1, 1 ... 1
    weights = vector<int>(N_ITEMS, 1);

    // values equal 1, 2, 3, ... N_ITEMS
    values = vector<int>(N_ITEMS);
    for(int i = 0; i < N_ITEMS; i++)
        values[i] = i+1;

    auto start = high_resolution_clock::now();
    cout << dpUnboundedKnapsack(0, 0) << endl;    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;

    return 0;
}