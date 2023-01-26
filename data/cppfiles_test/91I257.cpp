#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
map<pair<int, int>, int> mp;
struct edge {
  int u, v, w;
} mx[N][3];
map<edge, int> ct;
bool operator<(const edge &x, const edge &y) {
  if (x.w ^ y.w) return x.w < y.w;
  if (x.u ^ y.u) return x.u < y.u;
  return x.v < y.v;
}
bool operator!=(const edge &x, const edge &y) {
  return x.u != y.u || x.v != y.v || x.w != y.w;
}
int n, m, q, pd[N];
multiset<long long> ret;
set<edge> s, to[N];
inline void change(int u) {
  if (pd[u])
    ret.erase(ret.find((long long)mx[u][0].w + mx[u][1].w + mx[u][2].w));
  int i = 0;
  for (auto it = to[u].begin(); i < 3 && it != to[u].end(); i++, it++) {
    edge e = *it;
    if (mx[u][i] != e) {
      if (~mx[u][i].u)
        if (!(--ct[mx[u][i]])) s.erase(mx[u][i]);
      mx[u][i] = e;
      if (!ct[mx[u][i]]) s.insert(mx[u][i]);
      ct[mx[u][i]]++;
    }
  }
  for (int i = to[u].size(); i < 3; ++i) {
    if (~mx[u][i].u) {
      if (!(--ct[mx[u][i]])) s.erase(mx[u][i]);
      mx[u][i] = (edge){-1, -1, -1};
    } else
      break;
  }
  if (to[u].size() >= 3)
    pd[u] = 1, ret.insert((long long)mx[u][0].w + mx[u][1].w + mx[u][2].w);
  else
    pd[u] = 0;
}
inline void insert(int u, int v, int w) {
  edge e = (edge){u, v, w};
  to[u].insert(e);
  to[v].insert(e);
  change(u);
  change(v);
}
inline void erase(int u, int v, int w) {
  edge e = (edge){u, v, w};
  to[u].erase(e);
  to[v].erase(e);
  change(u);
  change(v);
}
inline long long solve() {
  long long ans = ret.size() ? (*ret.begin()) : 1e15;
  int lim = min((int)s.size(), 6), i = 0;
  for (auto it = s.begin(); i < lim; i++, it++) {
    auto it2 = it;
    it2++;
    for (int j = i + 1; j < lim; j++, it2++) {
      edge e1 = *it, e2 = *it2;
      if (e1.w + e2.w > ans) break;
      if (e1.u == e2.u || e1.u == e2.v || e1.v == e2.u || e1.v == e2.v)
        continue;
      ans = e1.w + e2.w;
      break;
    }
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < 3; ++j) mx[i][j] = (edge){-1, -1, -1};
  for (int i = 1, u, v, w; i <= m; ++i) {
    scanf("%d%d%d", &u, &v, &w);
    if (u > v) swap(u, v);
    mp[make_pair(u, v)] = w;
    insert(u, v, w);
  }
  printf("%lld\n", solve());
  scanf("%d", &q);
  while (q--) {
    int op;
    scanf("%d", &op);
    if (!op) {
      int u, v;
      scanf("%d%d", &u, &v);
      if (u > v) swap(u, v);
      erase(u, v, mp[make_pair(u, v)]);
    } else {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      if (u > v) swap(u, v);
      mp[make_pair(u, v)] = w;
      insert(u, v, w);
    }
    printf("%lld\n", solve());
  }
  return 0;
}
