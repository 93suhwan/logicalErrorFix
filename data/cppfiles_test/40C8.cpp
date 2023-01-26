#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int MX = 3e5 + 5;
vector<int> g[MX], gt[MX], p(MX);
vector<bool> vis(MX);
void dfs(int u, int par) {
  vis[u] = true;
  if (par != -1) {
    gt[u].push_back(par);
    gt[par].push_back(u);
  }
  for (auto v : g[u]) {
    if (vis[v]) continue;
    dfs(v, u);
  }
}
void dfst(int u, int par) {
  p[u] = par;
  for (auto v : gt[u]) {
    if (v == par) continue;
    dfst(v, u);
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int q;
  cin >> q;
  vector<pair<int, int>> queris;
  vector<int> cnt(n + 1);
  for (int i = 0; i < q; ++i) {
    int a, b;
    cin >> a >> b;
    queris.push_back({a, b});
    ++cnt[a];
    ++cnt[b];
  }
  int bad = 0;
  for (int i = 1; i <= n; ++i) {
    if (cnt[i] % 2) ++bad;
  }
  if (bad > 0) {
    cout << "NO" << '\n';
    cout << bad / 2 + (bad % 2) << '\n';
  } else {
    cout << "YES" << '\n';
    dfs(1, -1);
    for (auto [a, b] : queris) {
      p = vector<int>(n + 1, -1);
      dfst(a, -1);
      vector<int> sol;
      int k = b;
      while (k != -1) {
        sol.push_back(k);
        k = p[k];
      }
      reverse(sol.begin(), sol.end());
      cout << sol.size() << '\n';
      for (auto x : sol) cout << x << ' ';
      cout << '\n';
    }
  }
}
