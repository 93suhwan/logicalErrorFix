#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e9;
void solve() {
  int m, n;
  cin >> m >> n;
  vector<vector<int>> vec(m, vector<int>(n));
  vector<int> mx(n - 1, -INF);
  vector<int> h(n);
  for (int i = 0; i < m; i++) {
    bool flag = 0;
    for (int j = 0; j < n; j++) {
      cin >> vec[i][j];
      if (j <= n - 2) {
        if (mx[j] < vec[i][j]) {
          mx[j] = vec[i][j];
          flag = 1;
        }
      }
    }
    if (flag) {
      for (int j = 0; j < n - 1; j++) h[j] = max(h[j], vec[i][j]);
    }
  }
  if (m < n) {
    for (int i = 0; i < m; i++) {
      int mn = INF;
      for (int j = 0; j < n; j++) h[j] = max(h[j], vec[i][j]);
    }
    cout << *min_element((h).begin(), (h).end()) << '\n';
    return;
  }
  int ans = -INF, tmp = INF;
  for (int i = 0; i < n - 1; i++) tmp = min(tmp, h[i]);
  for (int i = 0; i < m; i++) {
    ans = max(ans, min({tmp, vec[i][n - 1], vec[i][n - 2]}));
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
