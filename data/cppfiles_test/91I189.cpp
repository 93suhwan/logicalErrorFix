#include <bits/stdc++.h>
using namespace std;
const int maxn = 112345;
const long long inf = 0x3f3f3f3f3f3f3f3f;
int n, m;
set<pair<int, int> > ga[maxn], gb[maxn];
multiset<long long> dp;
multiset<pair<long long, pair<int, int> > > dp2;
map<pair<int, int>, int> edge;
inline void update(int u) {
  while (ga[u].size() && gb[u].size()) {
    auto it1 = *ga[u].rbegin();
    auto it2 = *gb[u].begin();
    if (it1.first > it2.first) {
      gb[u].insert(it1);
      ga[u].erase(it1);
    } else
      break;
  }
  while ((int)ga[u].size() < 3 && gb[u].size()) {
    auto kv = *gb[u].begin();
    ga[u].insert(kv);
    gb[u].erase(kv);
  }
}
inline void del(int u) {
  if ((int)ga[u].size() >= 3) {
    long long res = 0;
    for (auto kv : ga[u]) {
      int w = kv.first;
      res += w;
    }
    dp.erase(dp.find(res));
  }
  for (auto kv : ga[u]) {
    int w = kv.first;
    int v = kv.second;
    dp2.erase(pair<long long, pair<int, int> >(
        w, pair<int, int>(min(v, u), max(v, u))));
  }
}
inline void add(int u) {
  if ((int)ga[u].size() >= 3) {
    long long res = 0;
    for (auto kv : ga[u]) {
      int w = kv.first;
      res += w;
    }
    dp.insert(res);
  }
  for (auto kv : ga[u]) {
    int w = kv.first;
    int v = kv.second;
    if (ga[v].find(pair<int, int>(w, u)) != ga[v].end())
      dp2.insert(pair<long long, pair<int, int> >(
          w, pair<int, int>(min(v, u), max(v, u))));
  }
}
inline void addedge(int u, int v, int w) {
  if (u > v) swap(u, v);
  edge[pair<int, int>(u, v)] = w;
  del(u);
  del(v);
  gb[u].insert(pair<int, int>(w, v));
  gb[v].insert(pair<int, int>(w, u));
  update(u);
  update(v);
  add(u);
  add(v);
}
inline void removeedge(int u, int v, int w) {
  del(u);
  del(v);
  if (ga[u].find(pair<int, int>(w, v)) != ga[u].end())
    ga[u].erase(pair<int, int>(w, v));
  else
    gb[u].erase(pair<int, int>(w, v));
  if (ga[v].find(pair<int, int>(w, u)) != ga[v].end())
    ga[v].erase(pair<int, int>(w, u));
  else
    gb[v].erase(pair<int, int>(w, u));
  update(u);
  update(v);
  add(u);
  add(v);
}
inline void solve() {
  long long ret = inf;
  if (dp.size()) ret = min(ret, *dp.begin());
  int minu = dp2.begin()->second.first;
  int minv = dp2.begin()->second.second;
  int minw = dp2.begin()->first;
  auto it = dp2.begin();
  for (int i = 0; i < 6 && it != dp2.end(); ++i, ++it) {
    if (i == 0) continue;
    int u = it->second.first;
    int v = it->second.second;
    int w = it->first;
    if (minu == u || minu == v || minv == v || minv == u) continue;
    ret = min(ret, 0ll + minw + w);
  }
  for (auto kv1 : ga[minu])
    for (auto kv2 : ga[minv]) {
      int u1 = minu, v1 = kv1.second, w1 = kv1.first;
      int u2 = minv, v2 = kv2.second, w2 = kv2.first;
      if (u1 == u2 || u1 == v2) continue;
      if (v1 == u2 || v1 == v2) continue;
      ret = min(ret, 0ll + w1 + w2);
    }
  printf("%lld\n", ret);
}
int main() {
  scanf("%d%d", &n, &m);
  while (m--) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    addedge(u, v, w);
  }
  solve();
  int q;
  scanf("%d", &q);
  while (q--) {
    int op;
    scanf("%d", &op);
    if (op == 0) {
      int u, v;
      scanf("%d%d", &u, &v);
      int w = edge[pair<int, int>(u, v)];
      removeedge(u, v, w);
    } else {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      addedge(u, v, w);
    }
    solve();
  }
  return 0;
}
