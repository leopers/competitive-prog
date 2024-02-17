#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n;

    long long curr[n], op1[n-1], op2[n-1];
    
    for(int i=0; i<n;++i) cin>>curr[i];

    for(int i=0; i<n-1;++i) cin>>op1[i]>>op2[i];

    for(int i=0; i<n-1;++i){
        long long num = curr[i]/op1[i];
        curr[i]= curr[i]- num*op1[i];
        curr[i+1]= curr[i+1]+num*op2[i];
    }

    cout <<curr[n-1];
}