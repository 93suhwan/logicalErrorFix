#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int c[101][101];
int C(int n, int r) {
  if (n == r || r == 0) return 1;
  if (~c[n][r]) return c[n][r];
  return c[n][r] = (C(n - 1, r - 1) + C(n - 1, r)) % mod;
}
void solve(int tc) {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> g(n + 1);
  vector<int> deg(n + 1);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
  if (k <= 2) {
    cout << C(n, k) << '\n';
    return;
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (deg[i] >= k) {
      vector<int> sdep(n + 1, 1);
      vector<int> scnt(n + 1, 0);
      for (int v : g[i]) {
        vector<int> dep(n + 1);
        function<void(int, int, int)> dfs = [&](int u, int p, int d) {
          dep[d]++;
          for (int v : g[u])
            if (v != p) dfs(v, u, d + 1);
        };
        dfs(v, i, 1);
        for (int i = 1; dep[i] > 0; ++i) {
          sdep[i] = sdep[i] * dep[i] % mod;
          scnt[i]++;
        }
      }
      for (int i = 1; scnt[i] >= k; ++i) {
        ans = (ans + C(scnt[i], k) * sdep[i] % mod) % mod;
      }
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  memset(c, -1, sizeof c);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; ++i) solve(i);
  return 0;
}
