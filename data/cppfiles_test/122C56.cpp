#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int N = 2e5 + 20;
vector<pair<int, int>> g[N], ng[N];
bool px[N];
int top[N];
int col[N];
void dfs1(int v, int p, int tp, bool xr) {
  top[v] = tp, px[v] = xr;
  for (auto [u, w] : g[v]) {
    if (u != p) {
      dfs1(u, v, w == -1 ? u : tp, w == -1 ? xr : xr ^ w);
    }
  }
}
vector<int> used;
map<pair<int, int>, int> value;
bool dfs2(int v, int clr) {
  if (col[v] != -1) return col[v] == clr;
  col[v] = clr;
  used.push_back(v);
  bool ok = 1;
  for (auto [u, val] : ng[v]) {
    if (!dfs2(u, val ^ clr)) ok = 0;
  }
  return ok;
}
void dfs3(int v, int p, int xr) {
  for (auto [u, w] : g[v]) {
    if (u != p) {
      if (w == -1) {
        value[{u, v}] = value[{v, u}] = xr ^ col[u];
        dfs3(u, v, col[u]);
      } else
        dfs3(u, v, xr ^ w);
    }
  }
}
void solve() {
  int n, q;
  cin >> n >> q;
  used.clear(), value.clear();
  for (int i = 1; i <= n; i++) {
    g[i].clear(), ng[i].clear();
    px[i] = top[i] = 0;
    col[i] = -1;
  }
  vector<pair<pair<int, int>, int>> edges(n - 1), queries(q);
  for (auto &[p, c] : edges) {
    auto &[a, b] = p;
    cin >> a >> b >> c;
    g[a].push_back({b, c == -1 ? -1 : __builtin_popcount(c) % 2});
    g[b].push_back({a, c == -1 ? -1 : __builtin_popcount(c) % 2});
  }
  dfs1(1, 0, 0, 0);
  vector<pair<int, int>> det;
  for (auto &[p, val] : queries) {
    cin >> p.first >> p.second >> val;
  }
  for (auto &[p, val] : queries) {
    auto &[a, b] = p;
    if (top[a] == 0) {
      if (top[b] == 0) {
        if (px[a] ^ px[b] != val) {
          cout << "NO" << '\n';
          return;
        }
      } else
        det.push_back({top[b], val ^ px[a] ^ px[b] ^ px[top[b]]});
      continue;
    }
    if (top[b] == 0) {
      det.push_back({top[a], val ^ px[b] ^ px[a] ^ px[top[a]]});
      continue;
    }
    ng[top[a]].push_back(
        {top[b], val ^ px[b] ^ px[top[b]] ^ px[a] ^ px[top[a]]});
    ng[top[b]].push_back(
        {top[a], val ^ px[b] ^ px[top[b]] ^ px[a] ^ px[top[a]]});
  }
  for (auto [x, val] : det) {
    bool ok = dfs2(x, val);
    if (!ok) {
      cout << "NO" << '\n';
      return;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (top[i] == i) {
      used.clear();
      bool ok = dfs2(i, 0);
      if (!ok) {
        for (auto j : used) col[j] = -1;
        used.clear();
        ok = dfs2(i, 1);
        if (!ok) {
          cout << "NO" << '\n';
          return;
        }
      }
    }
  }
  dfs3(1, 0, 0);
  cout << "YES" << '\n';
  for (auto [p, w] : edges) {
    cout << p.first << " " << p.second << " "
         << (w == -1 ? value[{p.first, p.second}] : w) << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
