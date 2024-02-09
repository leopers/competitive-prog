#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  vector<int> fila;
  for(int i = 0; i < n; ++i){
    int j;
    cin >> j;
    fila.push_back(j);
  }

  int m;
  cin>>m;

  set<int> out;
  for(int i = 0; i < m; ++i){
    int j;
    cin >> j;
    out.insert(j);
  }

  vector<int> newline;
  for(auto x : fila){
    if(out.find(x) == out.end()) newline.push_back(x);
  }

  for(auto x : newline) cout << x << ' ';
}