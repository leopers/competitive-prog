#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  vector<int> t;
  int ti;
  for(int i=0; i<n; ++i) cin >> ti, t.push_back(ti);

  int time=0;
  bool on =false;
  for(int i=0; i<n-1; ++i){
    on = true;
    if(t[i+1]>10+t[i]) time+=(10+t[i]), on = false, time-=t[i+1];
  }
  time += (10+t[t.size()-1]);

  time-=t[0];
  cout << time;
}