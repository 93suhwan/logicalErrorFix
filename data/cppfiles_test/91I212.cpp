#include <bits/stdc++.h>
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
  vector<set<pair<int, int>>> G(n), g(n);
  map<pair<int, int>, int> ww;
  set<array<int, 3>> edges;
  multiset<long long> ans;
  vector<long long> cur(n, oo);
  for (int i = 0; i < n; i++) ans.insert(cur[i]);
  auto upd = [&](int u) {
    if (!(0 <= u && u < n)) {
      cout << 49 << " assertion fail!" << endl;
      exit(0);
    };
    if (!(ans.find(cur[u]) != ans.end())) {
      cout << 50 << " assertion fail!" << endl;
      exit(0);
    };
    ans.erase(ans.find(cur[u]));
    if (int(g[u].size()) < 3)
      cur[u] = oo;
    else {
      int cnt = 0;
      cur[u] = 0;
      for (auto& [w, v] : g[u]) {
        if (cnt == 3) break;
        cur[u] += w;
        cnt++;
      }
    }
    ans.insert(cur[u]);
  };
  auto add_edge_g = [&](int u, int v, int w) {
    if (!(0 <= u && u < n)) {
      cout << 66 << " assertion fail!" << endl;
      exit(0);
    };
    if (!(0 <= v && v < n)) {
      cout << 67 << " assertion fail!" << endl;
      exit(0);
    };
    if (u > v) swap(u, v);
    edges.insert({w, u, v});
    g[u].insert({w, v});
    g[v].insert({w, u});
    upd(u), upd(v);
  };
  auto del_edge_g = [&](int u, int v, int w) {
    if (!(0 <= u && u < n)) {
      cout << 75 << " assertion fail!" << endl;
      exit(0);
    };
    if (!(0 <= v && v < n)) {
      cout << 76 << " assertion fail!" << endl;
      exit(0);
    };
    if (u > v) swap(u, v);
    edges.erase({w, u, v});
    g[u].erase({w, v});
    g[v].erase({w, u});
    upd(u), upd(v);
  };
  auto del = [&](int u) {
    if (!(0 <= u && u < n)) {
      cout << 84 << " assertion fail!" << endl;
      exit(0);
    };
    for (auto& [w, v] : g[u]) {
      del_edge_g(u, v, w);
    }
  };
  auto add = [&](int u) {
    if (!(0 <= u && u < n)) {
      cout << 90 << " assertion fail!" << endl;
      exit(0);
    };
    int cnt = 0;
    for (auto& [w, v] : G[u]) {
      if (cnt == 3) break;
      add_edge_g(u, v, w);
      cnt++;
    }
  };
  auto add_edge_G = [&](int u, int v, int w) {
    if (!(0 <= u && u < n)) {
      cout << 99 << " assertion fail!" << endl;
      exit(0);
    };
    if (!(0 <= v && v < n)) {
      cout << 100 << " assertion fail!" << endl;
      exit(0);
    };
    ww[{u, v}] = ww[{v, u}] = w;
    del(u), del(v);
    G[u].insert({w, v});
    G[v].insert({w, u});
    add(u), add(v);
  };
  auto del_edge_G = [&](int u, int v, int w) {
    if (!(0 <= u && u < n)) {
      cout << 108 << " assertion fail!" << endl;
      exit(0);
    };
    if (!(0 <= v && v < n)) {
      cout << 109 << " assertion fail!" << endl;
      exit(0);
    };
    del(u), del(v);
    G[u].erase({w, v});
    G[v].erase({w, u});
    add(u), add(v);
    ww.erase({u, v});
    ww.erase({v, u});
  };
  auto another = [&](int u, int v, int w) {
    if (!(0 <= u && u < n)) {
      cout << 118 << " assertion fail!" << endl;
      exit(0);
    };
    if (!(0 <= v && v < n)) {
      cout << 119 << " assertion fail!" << endl;
      exit(0);
    };
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
    if (!(int(ans.size()) == n)) {
      cout << 130 << " assertion fail!" << endl;
      exit(0);
    };
    if (!(edges.size() >= 3)) {
      cout << 131 << " assertion fail!" << endl;
      exit(0);
    };
    long long res = *ans.begin();
    auto it = edges.begin();
    auto e1 = *it;
    auto e2 = *next(it);
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
