#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m;
vector<int> adj[300005];
vector<int> a2[300005];
bool vis[300005];
int p[300005];
int d[300005];
int col[300005];
void dfs(int u) {
  if (vis[u]) return;
  vis[u] = 1;
  for (int v : adj[u]) {
    if (vis[v]) continue;
    p[v] = u;
    d[v] = d[u] + 1;
    a2[u].push_back(v);
    a2[v].push_back(u);
    dfs(v);
  }
}
int res;
void dfs2(int u, int p = -1) {
  int rsum = 0;
  for (int v : a2[u]) {
    if (v == p) continue;
    rsum += col[v];
    dfs2(v, u);
  }
  res += rsum / 2;
  if (rsum % 2 == 1) {
    if (col[u] == 0) res++;
  }
}
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1);
  vector<vector<int>> ans;
  int q;
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    int u, v;
    cin >> u >> v;
    vector<int> l, r;
    l.push_back(u);
    r.push_back(v);
    while (u != v) {
      if (d[u] > d[v]) {
        if (p[u] != v) l.push_back(p[u]);
        col[u] ^= 1;
        u = p[u];
      } else {
        if (p[v] != u) r.push_back(p[v]);
        col[v] ^= 1;
        v = p[v];
      }
    }
    reverse(r.begin(), r.end());
    for (int x : r) l.push_back(x);
    ans.push_back(l);
  }
  bool ok = true;
  for (int i = 1; i <= n; ++i) ok &= col[i] == 0;
  if (ok) {
    cout << "YES" << endl;
    for (auto r : ans) {
      cout << r.size() << '\n';
      for (int x : r) cout << x << ' ';
      cout << '\n';
    }
    return;
  }
  dfs2(1);
  if (col[1]) res++;
  cout << "NO" << endl;
  cout << res << endl;
}
int main() {
  cin.tie(0)->sync_with_stdio(false);
  int t = 1;
  while (t--) solve();
}
