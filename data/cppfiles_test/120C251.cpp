#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  vector<vector<int>> v(200001, vector<int>(32));
  for (int i = 0; i < 2e5 + 1; i++) {
    for (int j = 0; j < 32; j++) {
      if (i & (1 << j)) v[i][j] = 1;
    }
  }
  for (int i = 1; i < 2e5 + 1; i++) {
    for (int j = 0; j < 32; j++) {
      v[i][j] += v[i - 1][j];
    }
  }
  while (t--) {
    int l, r;
    cin >> l >> r;
    int ans = 1e9;
    for (int i = 0; i < 32; i++) {
      if ((1 << i) <= r) {
        ans = min(ans, r - v[r][i] - l + 1 + v[l - 1][i]);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
