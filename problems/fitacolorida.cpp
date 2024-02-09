#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    int vec[N];
    for(int i=0; i<N; i++){
        cin>>vec[i];
    }

    int count[N];
    for(int i=0; i<N; i++){
        count[i] = N+1;
    }

    for(int i = 0; i<N; ++i){
        if(vec[i]==0){
            count[i] = 0;
            continue;
        }
        
        for(int j=0; j<N; ++j){
            if(abs(j-i)<count[i] && vec[j]==0 && i!=j) count[i] = abs(j-i);
        }
    }

	cout << min(9,count[0]);
    for(int i=1; i<N; i++){
        cout << ' ' << min(count[i],9);
    }
}