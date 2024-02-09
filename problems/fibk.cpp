#include <bits/stdc++.h>
using namespace std;

int main() {
  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int k, n;
    cin >> k >> n;

    queue<long int> fibk;
    long int sum = 0;
    for (int j = 0; j < k && j < n; ++j) {
      fibk.push(j);
      sum += j;
    }

    for (int j = k; j < n; ++j) {
      fibk.push(sum);
      sum += sum;
      sum -= fibk.front();
      fibk.pop();
    }
    cout << fibk.back() % 1000007 << '\n';
  }
}