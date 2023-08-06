#include <bits/stdc++.h>
using namespace std;


bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
  if(a.second.first == b.second.first){
    if(a.second.second/a.second.first == b.second.second/b.second.first) return a.second.second > b.second.second;
    return a.second.first/a.second.second > b.second.first/b.second.second;
  }

  return a.second.first>b.second.first;
}

int main(){
  int num, h=1;
  while(cin >> num){
    if(num == 0) return 0;

    vector<pair<int, pair<int, int>>> team;
    for(int i=0; i<num;++i){
      team.push_back(make_pair(i+1, make_pair(0, 0)));
    }

    int i, pi, j, pj;
    for(int a = 0; a<num*(num-1)/2; ++a){
      cin >> i >> pi>>j>>pj;
      if(pi>pj){
        team[i-1].second.first +=2;
        team[j-1].second.first++;
      }
      else{
        team[j-1].second.first +=2;
        team[i-1].second.first++;
      }
      team[i-1].second.second += pi;
      team[j-1].second.second += pi;
    }


    sort(team.begin(), team.end(), comp);


    cout << "Instancia " << h << '\n';
    for(int a=0; a<team.size(); ++a){
      cout << team[a].first << ' ';
    }
    cout<<'\n';
    h++;
  }
}

