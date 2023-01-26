#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int N = 2e5 + 6;
int f[N << 1];
int fd(int x) { return x == f[x] ? x : f[x] = fd(f[x]); }
void dfs(int u, int p, vector<int>& dp, vector<vector<pair<int, int>>>& e) {
  for (auto [w, v] : e[u]) {
    if (v == p) continue;
    if (w == -1 || dp[u] == -1)
      dp[v] = -1;
    else if (__builtin_popcount(w) % 2 == 0)
      dp[v] = dp[u];
    else
      dp[v] = dp[u] ^ 1;
    dfs(v, u, dp, e);
  }
}
void gao(int n, vector<vector<pair<int, int>>>& e, vector<int>& dp) {
  vector<int> vis(n, 0);
  queue<int> q;
  q.push(0);
  vis[0] = 1;
  vector<pair<int, pair<int, int>>> ans;
  while ((int)q.size()) {
    int u = q.front();
    q.pop();
    if (dp[u] == -1) {
      int fu = fd(u), fun = fd(u + n);
      if (dp[fu] != -1)
        dp[u] = dp[fu];
      else if (dp[fun] != -1)
        dp[u] = 1 ^ dp[fu];
      else
        dp[u] = 0;
    }
    for (auto [w, v] : e[u]) {
      if (vis[v]) continue;
      q.push(v);
      vis[v] = 1;
      if (w != -1)
        ans.push_back({w, {u, v}});
      else
        ans.push_back({dp[u] ^ dp[v], {u, v}});
    }
  }
  cout << "YES" << '\n';
  for (auto tmp : ans)
    cout << tmp.second.first << ' ' << tmp.second.second << ' ' << tmp.first
         << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> e(n);
    vector<int> dp(n, 0), ans(n, 0);
    for (int i = 0; i < 2 * n; ++i) f[i] = i;
    for (int i = 1; i < n; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      u--;
      v--;
      e[u].push_back({w, v});
      e[v].push_back({w, u});
      if (w == -1) continue;
      if (__builtin_popcount(w) & 1) {
        int fun = fd(u + n), fvn = fd(v + n);
        f[fvn] = fun;
      } else {
        int fu = fd(u), fv = fd(u);
        f[fv] = fu;
      }
    }
    bool ok = true;
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      if (w) {
        int fu = fd(u), fv = fd(u);
        if (fu == fv) ok = false;
        int fun = fd(u + n), fvn = fd(v + n);
        f[fvn] = fun;
      } else {
        int fun = fd(u + n), fvn = fd(v + n);
        if (fun == fvn) ok = false;
        int fu = fd(u), fv = fd(u);
        f[fv] = fu;
      }
    }
    if (ok) {
      dfs(1, 1, dp, e);
      gao(n, e, dp);
    } else
      cout << "NO" << '\n';
  }
  return 0;
}
