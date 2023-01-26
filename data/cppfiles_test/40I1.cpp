#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, i, j, m, ara1[200000], ara2[200000], mn = 100000000000000, sum = 0,
                                                mx = 0, x, y, z;
    cin >> m;
    for (i = 1; i <= m; i++) {
      cin >> ara1[i];
      ara1[i] += ara1[i - 1];
    }
    for (i = 1; i <= m; i++) {
      cin >> ara2[i];
      ara2[i] += ara2[i - 1];
    }
    ara1[0] = ara2[0] = 0;
    for (i = 1; i <= m; i++) {
      x = ara1[m] - ara1[i];
      y = ara2[i - 1];
      z = max(x, y);
      if (mn > z) {
        mn = z;
      }
    }
    cout << mn << endl;
  }
}
