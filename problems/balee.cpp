#include "stdc++.h"
using namespace std;

int main(){
  int n;
  cin >> n;

  vector<int> b = {};
  for (int i = 0; i<n; ++i){
    int hab;
    cin >> hab;
    b.push_back(hab); 
  } 

  int resp =0;
  for(int i=0; i<b.size(); ++i){
    for (int j=i+1; j<b.size(); ++j){
      if(b[i]>b[j]) resp++;
    }
  }

  cout<<resp;
}