#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int n, vis[N], f[N], fl[N], c0, c1;
vector<int> e[N];
void dfs(int u) {
  if (vis[u]) return;
  c1 += (u > n);
  vis[u] = 1;
  for (int v : e[u]) dfs(v);
}
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
void add(int u, int v) {
  e[u].push_back(v), e[v].push_back(u);
  u = find(u), v = find(v);
  if (u == v) return;
  f[u] = v;
}
void solve() {
  int m;
  cin >> n >> m;
  for (int i = 1; i <= n + n; ++i)
    f[i] = i, fl[i] = 0, e[i].clear(), vis[i] = 0;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    string c;
    cin >> u >> v >> c;
    if (c == "imposter")
      add(u, v + n), add(v, u + n);
    else
      add(u, v), add(u + n, v + n);
  }
  for (int i = 1; i <= n; ++i)
    if (find(i) == find(i + n)) return (void)(cout << "-1\n");
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) {
      c1 = 0, dfs(i), c0 = c1;
      c1 = 0, dfs(i + n);
      ans += max(c0, c1);
    }
  cout << ans << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) solve();
}
