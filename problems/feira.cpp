#include "stdc++.h"
#include <string>
using namespace std;

int main(){
  int n;
  cin >> n;

  for(int i=0; i<n; ++i){
    int m;
    cin>>m;

    map<string, double> price;
    for(int j=0; j<m; ++j){
      string fruta;
      double preço;
      cin >> fruta >> preço; 
      price[fruta] = preço;
    }

    int p;
    cin>>p;
    double sum=0;
    for(int j=0; j<m; ++j){
      string fruta;
      int q;
      cin >> fruta >> q;
      sum += q*price[fruta];
    }
    cout << "R$ " << sum << '\n';
  }
}