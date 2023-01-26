#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
const int M = N + 7;
const double EPS = 1e-10;
const int MOD = 1e9 + 7;
const long long INF = 2e18;
set<pair<int, int>> g[M];
set<pair<int, pair<int, int>>> edges;
map<long long, int> p;
multiset<long long> threes;
void add(int v) {
  auto it = g[v].begin();
  long long cur = 0;
  for (int i = 0; i < min(3, (int)g[v].size()); i++, it++) {
    edges.insert({it->first, {v, it->second}});
    cur += it->first;
  }
  if ((int)g[v].size() >= 3) threes.insert(cur);
}
void del(int v) {
  auto it = g[v].begin();
  long long cur = 0;
  for (int i = 0; i < min(3, (int)g[v].size()); i++, it++) {
    edges.erase(edges.find({it->first, {v, it->second}}));
    cur += it->first;
  }
  if ((int)g[v].size() >= 3) threes.erase(threes.find(cur));
}
void add(int v, int u, int w) {
  del(v);
  g[v].insert({w, u});
  p[1e6 * v + u] = w;
  add(v);
}
void del(int v, int u) {
  del(v);
  g[v].erase(g[v].find({p[1e6 * v + u], u}));
  add(v);
}
long long calcAns() {
  int w = edges.begin()->first;
  int v = edges.begin()->second.first;
  int u = edges.begin()->second.second;
  long long ans = threes.empty() ? INF : *threes.begin();
  auto tov = g[v].begin();
  for (int i = 0; i < min(3, (int)g[v].size()); i++, tov++) {
    auto tou = g[u].begin();
    for (int j = 0; j < min(3, (int)g[u].size()); j++, tou++)
      if (tov->second != u && tou->second != v && tov->second != tou->second)
        ans = min(ans, 1LL * tov->first + tou->first);
  }
  auto it = edges.begin();
  while (true) {
    if (it->second.first != v && it->second.second != v &&
        it->second.first != u && it->second.second != u) {
      ans = min(ans, 1LL * w + it->first);
      break;
    }
    it++;
  }
  return ans;
}
void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int v, u, w;
    scanf("%d %d %d", &v, &u, &w);
    add(v, u, w);
    add(u, v, w);
  }
  printf("%lld\n", calcAns());
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int t, v, u;
    scanf("%d %d %d", &t, &v, &u);
    if (t == 1) {
      int w;
      scanf("%d", &w);
      add(v, u, w);
      add(u, v, w);
    } else {
      del(v, u);
      del(u, v);
    }
    printf("%lld\n", calcAns());
  }
}
int main() {
  int tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}
