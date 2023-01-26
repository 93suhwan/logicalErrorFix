#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10, mod = 1e9 + 7;
vector<int> g[N], path[N];
int par[N], h[N];
bool mark[N];
void dfs(int v) {
  mark[v] = true;
  for (int u : g[v]) {
    if (!mark[u]) {
      par[u] = v;
      dfs(u);
    }
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0);
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 1; i < n; i++) {
    g[par[i]].push_back(i);
    g[i].push_back(par[i]);
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    h[u]++;
    h[v]++;
    memset(mark, 0, sizeof(mark));
    dfs(u);
    int cur = v;
    while (cur != u) {
      path[i].push_back(cur);
      cur = par[cur];
    }
    path[i].push_back(cur);
    reverse(path[i].begin(), path[i].end());
  }
  int bad = 0;
  for (int i = 0; i < n; i++) {
    if (h[i] & 1) {
      bad++;
    }
  }
  if (bad) {
    cout << "NO\n";
    cout << bad / 2;
    return;
  }
  cout << "YES\n";
  for (int i = 0; i < q; i++) {
    for (int x : path[i]) {
      cout << x + 1 << " ";
    }
    cout << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  int cur = 1;
  while (t--) {
    solve();
  }
  return 0;
}
