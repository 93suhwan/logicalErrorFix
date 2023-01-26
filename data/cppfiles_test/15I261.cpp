#include <bits/stdc++.h>
using namespace std;
int n;
int d[1000005];
int f[505][505];
vector<int> g[1000005];
void dfs(int u, int r, int pr, int val, int dis = 1) {
  if (u <= n && dis == val) d[r]++;
  for (auto &v : g[u])
    if (v != pr) dfs(v, r, u, val, dis + 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t-- > 0) {
    int k;
    cin >> n >> k;
    for (int i = 1; i <= 2 * n; ++i) g[i].clear();
    int sl = n;
    for (int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      sl++;
      g[u].emplace_back(sl);
      g[sl].emplace_back(u);
      g[v].emplace_back(sl);
      g[sl].emplace_back(v);
    }
    int res = 0;
    for (int i = 1; i <= sl; ++i) {
      if ((g[i]).size() < k) continue;
      for (int j = 1; j < sl; ++j) {
        for (auto &v : g[i]) d[v] = 0;
        for (auto &v : g[i]) dfs(v, v, i, j);
        for (int first = 0; first <= (g[i]).size(); ++first)
          for (int second = 0; second <= k; ++second) f[first][second] = 0;
        f[0][0] = 1;
        for (int first = 1; first <= (g[i]).size(); ++first) {
          for (int second = 0; second <= k; ++second) {
            f[first][second] = f[first - 1][second];
            if (second > 0)
              f[first][second] =
                  (f[first][second] +
                   f[first - 1][second - 1] * d[g[i][first - 1]] % 1000000007) %
                  1000000007;
          }
        }
        res = (res + f[(g[i]).size()][k]) % 1000000007;
      }
    }
    cout << res << endl;
  }
}
