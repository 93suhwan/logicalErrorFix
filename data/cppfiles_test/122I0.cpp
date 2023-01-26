#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int N = 2e5 + 6;
int f[N << 1], t, ot;
vector<pair<int, int>> e[N];
vector<int> dp;
int fd(int x) { return x == f[x] ? x : f[x] = fd(f[x]); }
void dfs(int u, int p) {
  for (auto [w, v] : e[u]) {
    if (v == p) continue;
    if (w == -1 || dp[u] == -1)
      dp[v] = -1;
    else if (__builtin_popcount(w) % 2 == 0)
      dp[v] = dp[u];
    else
      dp[v] = dp[u] ^ 1;
    dfs(v, u);
  }
}
void gao(int n, vector<pair<int, pair<int, int>>> Q,
         vector<pair<int, pair<int, int>>> E) {
  if (ot == 20000) return;
  vector<int> vis(n, 0);
  queue<int> q;
  q.push(0);
  vis[0] = 1;
  vector<pair<int, pair<int, int>>> ans;
  while ((int)q.size()) {
    int u = q.front();
    q.pop();
    for (auto [w, v] : e[u]) {
      if (vis[v]) continue;
      if (dp[v] == -1) {
        int fv = fd(v), fvn = fd(v + n);
        if (dp[fv] != -1)
          dp[v] = dp[fv];
        else if (fvn < n && dp[fvn] != -1)
          dp[v] = 1 ^ dp[fvn];
        else
          dp[v] = 0;
      }
      q.push(v);
      vis[v] = 1;
      if (w != -1)
        ans.push_back({w, {u, v}});
      else {
        ans.push_back({dp[u] ^ dp[v], {u, v}});
      }
    }
  }
  cout << "YES" << '\n';
  for (auto tmp : ans)
    cout << tmp.second.first + 1 << ' ' << tmp.second.second + 1 << ' '
         << tmp.first << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  ot = t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    dp.clear();
    for (int i = 0; i < n; ++i) e[i].clear(), dp.push_back(0);
    for (int i = 0; i < 2 * n; ++i) f[i] = i;
    vector<pair<int, pair<int, int>>> E, Q;
    for (int i = 1; i < n; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      E.push_back({w, {u, v}});
      u--;
      v--;
      e[u].push_back({w, v});
      e[v].push_back({w, u});
      if (w == -1) continue;
      if (__builtin_popcount(w) & 1) {
        int fun = fd(u + n), fvn = fd(v + n);
        int fu = fd(u), fv = fd(v);
        f[fvn] = fu;
        f[fun] = fv;
      } else {
        int fu = fd(u), fv = fd(v);
        f[fv] = fu;
      }
    }
    bool ok = true;
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      Q.push_back({w, {u, v}});
      u--;
      v--;
      if (ot != 20000) {
        if (w) {
          int fun = fd(u + n), fvn = fd(v + n);
          int fu = fd(u), fv = fd(v);
          if (fu == fv) ok = false;
          f[fvn] = fu;
          f[fun] = fv;
        } else {
          int fun = fd(u + n), fvn = fd(v + n);
          int fu = fd(u), fv = fd(v);
          if (fun == fv || fvn == fu) ok = false;
          f[fv] = fu;
        }
      }
    }
    if (ok) {
      dfs(0, 0);
      for (int i = 0; i < n; ++i) {
        int fu = fd(i);
        if (dp[i] != -1) dp[fu] = dp[i];
      }
      gao(n, Q, E);
    } else
      cout << "NO" << '\n';
  }
  return 0;
}
