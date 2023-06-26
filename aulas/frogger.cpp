#include<iostream>
#include<utility>
#include<vector>
#include<tuple>
#include<queue>
#define INF 1e9
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;

int n, m;
int state_dist[22][50][50];
char game[22][50];

vector<iii> get_neighbors(iii state){
    vector<iii> neighbors;

    vi drow = {1, 0, -1, 0, 0};
    vi dcol = {0, 1, 0, -1, 0};
    auto [row, col, time] = state;

    for(int i = 0; i < 5; i++)
    {
        int row_ = row + drow[i];
        int col_ = col + dcol[i];

        if(row_ >= n || row_ < 0)
            continue;
        if(col_ >= m || col_ < 0)
            continue;

        int time_ = (time + 1) % m;
        bool moving_to_right = (row_ % 2 == 1);
        int k = 2*moving_to_right - 1;

        int col_to_check = (col_ - k*time_ + m)%m;
        if(game[row_][col_to_check] == 'X')
            continue;

        neighbors.emplace_back(row_, col_, time_);
    }

    return neighbors;
}

int main()
{
    int cases; cin >> cases;
    while(cases--)
    {
        int MAX; cin >> MAX;
        cin >> n >> m;
        n += 2;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                for(int t = 0; t < m; t++)
                    state_dist[i][j][t] = INF;
        
        iii source;
        ii goal;
        queue<iii> q;
        for(int i = n - 1; i >= 0; i--)
            for(int j = 0; j < m; j++){
                cin >> game[i][j];
                if(game[i][j] == 'F')
                {
                    game[i][j] = 'O';
                    source = {i, j, 0};
                    q.emplace(source);
                    state_dist[i][j][0] = 0;
                }
                else if(game[i][j] == 'G')
                    goal = {i,j};
            }

        while(!q.empty())
        {
            iii front = q.front(); q.pop();

            auto [row, col, t] = front;
            if(game[row][col] == 'G')
                break;

            int dist = state_dist[row][col][t];
            if(dist > MAX)
                break;

            for(auto neighbor : get_neighbors(front))
            {
                auto [row_, col_, t_] = neighbor;
                if(state_dist[row_][col_][t_] < INF)
                    continue;
                state_dist[row_][col_][t_] = dist + 1;
                q.push(neighbor);
            }
        }

        int goal_dist = INF;
        for(int t = 0; t < m; t++)
            goal_dist = min(goal_dist, state_dist[goal.first][goal.second][t]);

        if(goal_dist > MAX)
            cout << "The problem has no solution.\n";
        else
            cout << "The minimum number of turns is " << goal_dist << ".\n";
    }

    return 0;
}
