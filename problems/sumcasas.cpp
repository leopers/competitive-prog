#include "stdc++.h"
using namespace std;

int main(){
  int n;
  cin >> n;

  set<int> C;
  for(int i=0 ; i<n; ++i){
    int c; cin>>c;
    C.insert(c);
  }

  int sum;
  cin>>sum;

  for(set<int>::iterator it= C.begin(); it!=C.end(); ++it){
    if(C.find(sum-*it)!= C.end()){
      cout << *it << ' ' << sum-*it << '\n';
      return 0;
    } 
  }
}