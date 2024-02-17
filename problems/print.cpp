#include <bits/stdc++.h>
#include <ostream>
using namespace std;

int main(){
    int h, w, n;
    cin>>h>>w>>n;

    char map[h][w];
    char mov[n];

    for(int i=0; i<n;++i)
        cin >> mov[i];


    for(int i =0; i<h;++i)
        for(int j =0; j<w; ++j)
            cin >> map[i][j];

    int count =0;
    for(int i=1; i<h-1;++i){
        for(int j=1; j<w-1; ++j){
            int pos =0;
            int x=i;
            int y=j;
            while(map[x][y]=='.' && pos<n){
                if(mov[pos]=='L') --y;
                if(mov[pos]=='R') ++y;
                if(mov[pos]=='U') --x;
                if(mov[pos]=='D') ++x;
                pos++;  
            }
            if(pos == n && map[x][y] == '.') count++;
        }
    }

    cout << count << endl;
}