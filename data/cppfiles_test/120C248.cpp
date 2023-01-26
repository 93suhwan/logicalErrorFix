#include <bits/stdc++.h>
using namespace std;
const int n = 1e6;
int t, k, x, a[n][21];
int main() {
  for (int i = 1; i < 200002; i++) {
    for (int j = 1; j < 21; j++) {
      x = (i / (pow(2, k)));
      a[i][j] = (x % 2);
      k++;
    }
    k = 0;
  }
  for (int i = 1; i < 21; i++) {
    for (int j = 2; j < 200002; j++) a[j][i] += a[j - 1][i];
  }
  cin >> t;
  while (t--) {
    int l, r, x = -1;
    cin >> l >> r;
    for (int i = 1; i < 21; i++) {
      x = max(x, (a[r][i] - a[l - 1][i]));
    }
    cout << r - l + 1 - x << endl;
  }
  return 0;
}
