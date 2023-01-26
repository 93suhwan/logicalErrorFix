#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e9;
void solve() {
  int m, n;
  cin >> m >> n;
  vector<vector<int>> vec(m, vector<int>(n));
  vector<int> mx(n - 2, -INF);
  vector<int> h(n);
  for (int i = 0; i < m; i++) {
    bool flag = 0;
    for (int j = 0; j < n; j++) {
      cin >> vec[i][j];
      if (j < n - 2 || m < n) {
        if (mx[j] < vec[i][j]) {
          mx[j] = vec[i][j];
          flag = 1;
        }
      }
    }
    if (flag) {
      for (int j = 0; j < n; j++) h[j] = max(h[j], vec[i][j]);
    }
  }
  int ans = INF;
  for (int i = 0; i < n; i++) ans = min(ans, h[i]);
  for (int i = 0; i < m; i++) {
    int mn = INF;
    for (int j = n - 2; j < n; j++) {
      mn = min(mn, vec[i][j]);
    }
    ans = max(ans, mn);
  }
  cout << ans << '\n';
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
