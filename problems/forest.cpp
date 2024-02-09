#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  int dresp = 0;
  for(int x = 2; x<n; ++x){
    if((n+x-1)%(2*x-1) == 0) ++dresp; 
  }

  cout<< dresp/2;
}