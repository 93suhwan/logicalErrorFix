#include <bits/stdc++.h>
using namespace std;
void _out() { cerr << '\n'; }
template <typename H, typename... T>
void _out(H h, T... t) {
  cerr << ' ' << h;
  _out(t...);
}
void solve();
void init();
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
int const N = 500;
string a[N];
int pre[N][N];
inline int que(int x0, int y0, int x1, int y1) {
  return pre[x1][y1] + pre[x0 - 1][y0 - 1] - pre[x0 - 1][y1] - pre[x1][y0 - 1];
}
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = '2' + a[i];
  }
  pre[1][0] = pre[0][1] = 0;
  for (int i = 1; i <= n; i++) pre[i][1] = pre[i - 1][1] + (a[i][1] == '1');
  for (int i = 1; i <= n; i++) pre[1][i] = pre[1][i - 1] + (a[1][i] == '1');
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      pre[i][j] =
          (a[i][j] == '1') + pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1];
    }
  }
  int ans = 20;
  for (int d = 1; d <= n; d++) {
    for (int u = d + 4; u <= n; u++) {
      vector<int> cost(m + 2);
      cost[m + 1] = INT_MAX;
      for (int r = m; r; r--) {
        cost[r] = que(d + 1, 1, u - 1, r - 1) + r - 1 - que(d, 1, d, r - 1) +
                  r - 1 - que(u, 1, u, r - 1) + u - d - 1 -
                  que(d + 1, r, u - 1, r);
      }
      int minCost = INT_MAX;
      for (int l = m - 3; l; l--) {
        minCost = min(minCost, cost[l + 3]);
        int tmp = minCost - cost[l] +
                  (-3 * que(d + 1, l, u - 1, l) + 2 * (u - d - 1)) -
                  (a[u][l] == '0') - (a[d][l] == '0');
        ans = min(ans, tmp);
      }
    }
  }
  cout << ans << '\n';
}
