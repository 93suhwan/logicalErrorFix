#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template <class H, class... T>
void DBG(H h, T... t) {
  cerr << to_string(h);
  if (sizeof...(t)) cerr << ", ";
  DBG(t...);
}
const int INF = 1e9 + 7;
const long long oo = 1e18;
signed main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  ;
  int n, m;
  cin >> n >> m;
  vector<set<pair<int, int>>> G(n);
  vector<vector<pair<int, int>>> g(n);
  map<pair<int, int>, int> ww;
  set<array<int, 3>> edges;
  multiset<long long> ans;
  vector<long long> cur(n, oo);
  auto upd = [&](int u) {
    sort((g[u]).begin(), (g[u]).end());
    g[u].resize(unique((g[u]).begin(), (g[u]).end()) - g[u].begin());
    if (cur[u] != oo) ans.erase(ans.find(cur[u]));
    if (int(g[u].size()) < 3)
      cur[u] = oo;
    else {
      int cnt = 0;
      cur[u] = 0;
      for (auto [w, v] : g[u]) {
        if (cnt == 3) break;
        cur[u] += w;
        cnt++;
      }
    }
    if (cur[u] != oo) ans.insert(cur[u]);
  };
  auto add_edge_g = [&](int u, int v, int w) {
    if (u > v) swap(u, v);
    if (edges.count({w, u, v})) return;
    edges.insert({w, u, v});
    g[u].push_back({w, v});
    g[v].push_back({w, u});
    upd(u), upd(v);
  };
  auto del_edge_g = [&](int u, int v, int w) {
    if (u > v) swap(u, v);
    if (edges.count({w, u, v}) == 0) return;
    edges.erase({w, u, v});
    if (auto it = find((g[u]).begin(), (g[u]).end(), make_pair(w, v));
        it != g[u].end())
      g[u].erase(it);
    if (auto it = find((g[v]).begin(), (g[v]).end(), make_pair(w, u));
        it != g[v].end())
      g[v].erase(it);
    upd(u), upd(v);
  };
  auto del = [&](int u) {
    vector<pair<int, int>> tt = g[u];
    for (auto [w, v] : tt) del_edge_g(u, v, w);
  };
  auto add = [&](int u) {
    int cnt = 0;
    for (auto [w, v] : G[u]) {
      if (cnt == 3) break;
      add_edge_g(u, v, w);
      cnt++;
    }
  };
  auto add_edge_G = [&](int u, int v, int w) {
    ww[{u, v}] = ww[{v, u}] = w;
    del(u), del(v);
    G[u].insert({w, v});
    G[v].insert({w, u});
    add(u), add(v);
  };
  auto del_edge_G = [&](int u, int v, int w) {
    del(u), del(v);
    G[u].erase({w, v});
    G[v].erase({w, u});
    add(u), add(v);
    ww.erase({u, v});
    ww.erase({v, u});
  };
  auto another = [&](int u, int v, int w) {
    long long res = w;
    del(u), del(v);
    if (edges.empty())
      res = oo;
    else
      res += (*edges.begin())[0];
    add(u), add(v);
    return res;
  };
  auto qry = [&]() -> long long {
    long long res = *ans.begin();
    auto it = edges.begin();
    auto e1 = *it;
    auto e2 = *next(it);
    if (e1[1] != e2[1] && e1[2] != e2[2] && e1[2] != e2[1] && e1[1] != e2[2])
      return 0LL + e1[0] + e2[0];
    res = min(res, another(e1[1], e1[2], e1[0]));
    res = min(res, another(e2[1], e2[2], e2[0]));
    for (int i = 1; i <= 2; i++)
      for (int j = 1; j <= 2; j++) {
        if (e1[i] == e2[j]) {
          int u = e1[3 ^ i], v = e2[3 ^ j];
          if (ww.count({u, v})) {
            int w = ww[{u, v}];
            res = min(res, another(u, v, w));
          }
        }
      }
    return res;
  };
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    add_edge_G(u, v, w);
  }
  cout << qry() << '\n';
  int q;
  cin >> q;
  while (q--) {
    int op;
    cin >> op;
    if (op == 0) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      del_edge_G(u, v, ww[{u, v}]);
    } else {
      int u, v, w;
      cin >> u >> v >> w;
      u--, v--;
      add_edge_G(u, v, w);
    }
    cout << qry() << '\n';
  }
}
