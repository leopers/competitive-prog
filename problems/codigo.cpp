#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;

    cin >> n;
    int arr[10000];

    int count = 0; 
    for(int i=0; i<n; ++i){
        cin >> arr[i];
        if(i>1 && arr[i]==0 && arr[i-1]==0 && arr[i-2]==1)
            count++;

    }

    cout << count;
}