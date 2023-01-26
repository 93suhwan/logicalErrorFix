#include <bits/stdc++.h>
using namespace std;
int sum[200010][32];
int res[32];
int main() {
  for (int i = 1; i <= 200000; i++) {
    for (int j = 31; j >= 0; j--) {
      sum[i][j] = sum[i - 1][j];
      if (i >> j & 1) sum[i][j]++;
    }
  }
  int _;
  cin >> _;
  while (_--) {
    int l, r;
    cin >> l >> r;
    for (int i = 0; i < 32; i++) res[i] = sum[r][i] - sum[l - 1][i];
    int ans = 0;
    for (int i = 0; i < 32; i++) {
      ans = max(ans, res[i]);
    }
    cout << r - l + 1 - ans << endl;
  }
  return 0;
}
