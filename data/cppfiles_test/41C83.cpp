#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10, mod = 1e9 + 7;
int mx = 1, col[N][N];
void go(int l, int r, int k, int cur) {
  mx = max(mx, cur);
  int sz = (r - l + k - 1) / k;
  for (int i = l; i < r; i += sz) {
    for (int j = i; j < i + sz; j++) {
      for (int k = i + sz; k < r; k++) {
        col[j][k] = cur;
      }
    }
  }
  if (sz > 1) {
    for (int i = l; i < r; i += sz) {
      go(i, min(r, i + sz), k, cur + 1);
    }
  }
}
void solve() {
  int n, k;
  cin >> n >> k;
  go(0, n, k, 1);
  cout << mx << "\n";
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      cout << col[i][j] << " ";
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  int cur = 1;
  while (t--) {
    solve();
  }
  return 0;
}
