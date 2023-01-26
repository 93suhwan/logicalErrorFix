#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int a[200005][30];
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= 200000; i++) {
    for (int j = 0; j < 20; j++) {
      if ((i >> j) & 1)
        a[i][j] = a[i - 1][j] + 1;
      else
        a[i][j] = a[i - 1][j];
    }
  }
  while (t--) {
    int max1 = 0;
    int l, r;
    cin >> l >> r;
    for (int i = 0; i < 20; i++) {
      max1 = max(max1, a[r][i] - a[l - 1][i]);
    }
    cout << r - l + 1 - max1 << endl;
  }
  return 0;
}
