#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<pair<int, int>> g[N];
map<pair<int, int>, int> cost;
set<pair<int, int>> a[N], b[N];
multiset<long long> dp;
set<pair<int, pair<int, int>>> dp2;
void solve() {
  auto minr = *dp2.begin();
  long long ans = 1e18;
  if ((int)(dp).size()) {
    ans = min(ans, *dp.begin());
  }
  int v = minr.second.first, u = minr.second.second;
  auto it = dp2.begin();
  for (int i = 0; i < 6 && it != dp2.end(); i++, it = next(it)) {
    auto res = *it;
    int v2 = res.second.first, u2 = res.second.second;
    if (v2 != v && v2 != u && u2 != v && u2 != u) {
      ans = min(ans, (long long)res.first + minr.first);
    }
  }
  for (auto [w, v2] : a[v]) {
    for (auto [w2, u2] : a[u]) {
      if (v2 != u2 && v2 != u && u2 != v) {
        ans = min(ans, (long long)w + w2);
      }
    }
  }
  cout << ans << '\n';
}
void del(int v) {
  if ((int)(a[v]).size() >= 3) {
    long long res = 0;
    for (auto [w, to] : a[v]) {
      res += w;
    }
    dp.erase(dp.find(res));
  }
  for (auto [w, to] : a[v]) {
    if (dp2.find({w, {min(v, to), max(v, to)}}) != dp2.end()) {
      dp2.erase({w, {min(v, to), max(v, to)}});
    }
  }
}
void upd(int v) {
  if ((int)(a[v]).size() >= 3) {
    long long res = 0;
    for (auto [w, to] : a[v]) {
      res += w;
    }
    dp.insert(res);
  }
  for (auto [w, to] : a[v]) {
    if (a[to].find({w, v}) != a[to].end()) {
      dp2.insert({w, {min(v, to), max(v, to)}});
    }
  }
}
void relax(int v) {
  while ((int)(a[v]).size() && (int)(b[v]).size()) {
    auto A = *a[v].rbegin(), B = *b[v].begin();
    if (A.first <= B.first) break;
    a[v].erase(A);
    b[v].insert(A);
  }
  while ((int)(a[v]).size() < 3 && (int)(b[v]).size()) {
    auto B = *b[v].begin();
    b[v].erase(B);
    a[v].insert(B);
  }
}
void erase(int v, int u, int w) {
  del(v);
  del(u);
  if (a[v].find({w, u}) != a[v].end()) {
    a[v].erase({w, u});
  } else {
    b[v].erase({w, u});
  }
  if (a[u].find({w, v}) != a[u].end()) {
    a[u].erase({w, v});
  } else {
    b[u].erase({w, v});
  }
  relax(v);
  relax(u);
  upd(v);
  upd(u);
}
void add(int v, int u, int w) {
  del(v);
  del(u);
  b[v].insert({w, u});
  b[u].insert({w, v});
  relax(v);
  relax(u);
  upd(v);
  upd(u);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    x--, y--;
    if (x > y) swap(x, y);
    cost[{x, y}] = w;
    add(x, y, w);
  }
  int q;
  cin >> q;
  solve();
  while (q--) {
    int t, v, u;
    cin >> t >> v >> u;
    v--, u--;
    if (v > u) swap(v, u);
    if (t == 0) {
      int w = cost[{v, u}];
      erase(v, u, w);
    } else {
      int w;
      cin >> w;
      cost[{v, u}] = w;
      add(v, u, w);
    }
    solve();
  }
}
