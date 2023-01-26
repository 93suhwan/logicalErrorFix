#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e9;
void solve() {
  int m, n;
  cin >> m >> n;
  vector<vector<int>> vec(m, vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) cin >> vec[i][j];
  }
  if (m < n) {
    vector<int> h(n, -INF);
    for (int i = 0; i < m; i++) {
      int mn = INF;
      for (int j = 0; j < n; j++) h[j] = max(h[j], vec[i][j]);
    }
    cout << *min_element((h).begin(), (h).end()) << '\n';
    return;
  }
  int ans = -INF;
  for (int k = 0; k < n; k++) {
    for (int kk = 0; kk < n; kk++)
      if (k != kk) {
        vector<int> h(n, INF);
        for (int i = 0; i < n; i++)
          if (i != k && i != kk) h[i] = 0;
        for (int i = 0; i < m; i++) {
          for (int j = 0; j < n; j++) {
            if (j != k && j != kk && h[j] < vec[i][j]) {
              h[j] = max(h[j], vec[i][j]);
            }
          }
        }
        int tans = -INF, tmp = INF;
        for (int i = 0; i < n; i++) tmp = min(tmp, h[i]);
        for (int i = 0; i < m; i++) {
          tans = max(tans, min({tmp, vec[i][k], vec[i][kk]}));
        }
        ans = max(ans, tans);
      }
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
