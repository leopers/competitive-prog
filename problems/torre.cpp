#include <bits/stdc++.h>
using namespace std; 

int main(){
    int n;
    cin >> n; 
    int tab[n][n];
    int col[n], lin[n]; 


    for(int i=0; i<n; ++i){
        col[i]=0;
        lin[i] = 0;
    }

    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            cin >> tab[i][j];

    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j){
            lin[i] += tab[i][j];
            col[i] += tab[j][i];
        }

    int greater = 0;
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            greater = max(greater, lin[i]+col[j]- 2*tab[i][j]);

    cout << greater;
}