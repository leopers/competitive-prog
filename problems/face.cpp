#include "stdc++.h"
#include <cstdio>
#include <string>
using namespace std;

int main(){
  int n;
  cin >> n;

  stack<string> face({"FACE"});
  int count = 0;
  cin.ignore();
  for(int i=0; i<n; ++i){
    string temp = face.top();
    reverse(temp.begin(), temp.end());

    string s;
    getline(cin, s);
    face.push(s);
    
    if(face.top() == temp){
      count++;
      face.pop();
      face.pop();
    }

    if(face.size()==0) face.push("FACE");
  }

  cout<<count<<'\n';
}