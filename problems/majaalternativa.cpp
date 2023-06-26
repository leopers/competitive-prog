#include "stdc++.h"
using namespace std;

int main()
{
  int N;
	while (cin >> N){
    pair<int, int> bee = {0,0};
    int step = 1;
    int i =1;
    while(i<=N){
      for (int j = 0; j < step && i < N; j++) //baixo
			  bee.second++, ++i;
		  for (int j = 0; j < step - 1 && i < N; j++){ //baixo esquerda
			  bee.first--, bee.second++, ++i;
		  for (int j = 0; j < step && i < N; j++){ //esquerda
			  bee.first--;
        ++i;
      }
		  for (int j = 0; j < step && i < N; j++) //cima
			  bee.second--, ++i;
		  for (int j = 0; j < step-1 && i < N; j++) //cima direita
			  bee.first++, bee.second--, ++i;
		  for (int j = 0; j < step && i < N; j++) //direita
			  bee.first++, ++i;
		  step++;
    }
    cout << bee.first << ' ' << bee.second << '\n';
  }
}