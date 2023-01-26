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
      queue<int> q;
      vector<int> d(n + 1), c(101);
      q.push(i);
      d[i] = 1;
      while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
          if (!d[v]) {
            d[v] = d[u] + 1;
            c[d[v]]++;
            q.push(v);
          }
        }
      }
      for (int i = 2; c[i] > 0; ++i) {
        if (c[i] >= k) ans = (ans + C(c[i], k)) % mod;
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
