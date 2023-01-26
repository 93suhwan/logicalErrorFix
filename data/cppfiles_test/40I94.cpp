#include <bits/stdc++.h>
using namespace std;
int n, m, Q, f[300030], dep[300030], c[300030];
vector<int> G[300030];
vector<vector<int> > ans;
void dfs1(int u, int fa) {
  dep[u] = dep[fa] + 1;
  f[u] = fa;
  for (auto v : G[u]) {
    if (dep[v]) continue;
    dfs1(v, u);
  }
}
void Plus(int u, int v) {
  vector<int> A(1, u), B(1, v);
  c[u] ^= 1, c[v] ^= 1;
  while (dep[u] > dep[v]) A.push_back(u = f[u]), c[u] ^= 1;
  while (dep[v] > dep[u]) B.push_back(v = f[v]), c[v] ^= 1;
  if (u == v) {
    A.pop_back();
  } else {
    while (f[u] ^ f[v])
      A.push_back(u = f[u]), B.push_back(v = f[v]), c[u] ^= 1, c[v] ^= 1;
    A.push_back(f[u]);
  }
  reverse(B.begin(), B.end());
  A.insert(A.end(), B.begin(), B.end());
  ans.push_back(A);
}
int dp[300030];
void dfs2(int u) {
  int cnt = 0;
  for (auto v : G[u]) {
    if (f[v] == u) {
      dfs2(v);
      dp[u] += dp[v];
      cnt += c[v];
    }
  }
  dp[u] += c[u];
  if (cnt >= 2 || cnt == 1 && c[u]) --dp[u];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs1(1, 0);
  cin >> Q;
  for (int i = 1; i <= Q; ++i) {
    int u, v;
    cin >> u >> v;
    Plus(u, v);
  }
  if (accumulate(c + 1, c + n + 1, 0) == 0) {
    cout << "YES\n";
    for (auto v : ans) {
      cout << v.size() << '\n';
      for (auto x : v) cout << x << ' ';
      cout << '\n';
    }
    return 0;
  }
  cout << "NO\n";
  dfs2(1);
  cout << dp[1] << '\n';
  return 0;
}
