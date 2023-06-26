#include "stdc++.h"
using namespace std;

int main() { 
  int nc;
  cin >> nc;

  for(int i=0; i<nc; i++){
    int n, k;
    cin >> n >> k;

    queue<int> jos;
    for(int j =0; j<n;++j) jos.push(j+1);

    while(jos.size()>1){
      for(int j=0; j<k-1;++j){
       jos.push(jos.front());
        jos.pop();
      }
      jos.pop();
    }
    cout << "Case "<< i+1 << ": " << jos.front() << '\n';
  }
}