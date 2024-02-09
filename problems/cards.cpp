#include <bits/stdc++.h>
using namespace std;

int main(){
  deque<int> bar;

  int n;
  while(std::cin>>n){
    bar.push_back(n);
  }

  cout<<"discarded cards: ";
  while(bar.size()>1){
    cout<<bar.back()<<", ";
    bar.pop_back();
    int temp = bar.back();
    bar.pop_back();
    bar.push_front(temp);
  }
  cout<<'\n'<<"remaining card: "<<bar.front();
}