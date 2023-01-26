#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")
using namespace std;
long long my_pop_cnt(long long first) {
  if (first == -1) return 0;
  long long s = 0;
  while (first > 0) {
    s += first & 1;
    first >>= 1;
  }
  return s % 2;
}
struct edge {
  long long a, b, val, p;
};
vector<edge> edges;
vector<vector<edge>> G;
vector<long long> node_to_edge;
vector<vector<edge>> G2;
vector<long long> color;
void dfs1(long long v, long long first, long long p = -1) {
  color[v] = first;
  for (edge e : G[v]) {
    long long to = e.b;
    if (to == p) continue;
    if (e.val == -1) continue;
    dfs1(to, first ^ e.p, v);
  }
}
void dfs2(long long v, long long c, long long p = -1) {
  color[v] = c;
  for (edge e : G2[v]) {
    long long to = v ^ e.a ^ e.b;
    if (color[to] != -1) continue;
    dfs2(to, c ^ e.p, v);
  }
}
void dfs3(long long v, long long p = -1) {
  for (edge e : G[v]) {
    long long to = e.b;
    if (to == p) continue;
    if (e.val == -1)
      cout << v + 1 << ' ' << to + 1 << ' ' << (color[v] ^ color[to]) << '\n';
    else
      cout << v + 1 << ' ' << to + 1 << ' ' << e.val << '\n';
    dfs3(to, v);
  }
}
void solve() {
  long long n, m;
  cin >> n >> m;
  G = vector<vector<edge>>(n);
  G2 = vector<vector<edge>>(n);
  color = vector<long long>(n, -1);
  for (long long i = 0; i < n - 1; ++i) {
    long long u, v, first;
    cin >> u >> v >> first;
    u--;
    v--;
    long long p = my_pop_cnt(first);
    G[u].push_back({u, v, first, p});
    G[v].push_back({v, u, first, p});
    if (first != -1) {
      G2[u].push_back({u, v, first, p});
      G2[v].push_back({v, u, first, p});
    }
  }
  for (long long i = 0; i < m; ++i) {
    long long u, v, first;
    cin >> u >> v >> first;
    u--;
    v--;
    long long p = my_pop_cnt(first);
    G2[u].push_back({u, v, first, p});
    G2[v].push_back({v, u, first, p});
  }
  dfs1(0, 0);
  for (long long i = 0; i < n; ++i) {
    if (color[i] != -1) dfs2(i, color[i]);
  }
  for (long long i = 0; i < n; ++i) {
    if (color[i] == -1) dfs2(i, 0);
  }
  bool flag = false;
  for (long long v = 0; v < n; ++v) {
    for (edge e : G2[v]) {
      long long to = v ^ e.a ^ e.b;
      if (color[v] ^ color[to] != e.p) {
        flag = true;
        break;
      }
    }
    if (flag) break;
  }
  if (flag) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  dfs3(0);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
