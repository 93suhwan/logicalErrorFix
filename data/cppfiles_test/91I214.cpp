#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m;
long long s3[N];
map<pair<int, int>, int> mpw, mpc;
set<pair<int, int> > G[N];
set<pair<int, pair<int, int> > > st;
set<pair<long long, int> > st3;
inline void mdf_edge(int u, int v, int w, int d) {
  if (u > v) swap(u, v);
  int lst = mpc[make_pair(u, v)];
  mpc[make_pair(u, v)] += d;
  int cur = mpc[make_pair(u, v)];
  if (lst == 2 && cur < 2) st.erase(make_pair(w, make_pair(u, v)));
  if (lst < 2 && cur == 2) st.insert(make_pair(w, make_pair(u, v)));
}
inline void gao_ver(int u, int d) {
  if (G[u].size() < 3) {
    for (auto &p : G[u]) {
      mdf_edge(u, p.second, p.first, d);
    }
  } else {
    auto it0 = G[u].begin();
    auto it1 = next(it0);
    auto it2 = next(it1);
    mdf_edge(u, it0->second, it0->first, d);
    mdf_edge(u, it1->second, it1->first, d);
    mdf_edge(u, it2->second, it2->first, d);
    s3[u] = it0->first + it1->first + it2->first;
    if (d == 1) {
      st3.insert(make_pair(s3[u], u));
    } else {
      st3.erase(make_pair(s3[u], u));
    }
  }
}
inline void add_ver(int u, int v, int w) {
  gao_ver(u, -1);
  G[u].insert(make_pair(w, v));
  gao_ver(u, 1);
}
inline void del_ver(int u, int v, int w) {
  gao_ver(u, -1);
  G[u].erase(make_pair(w, v));
  gao_ver(u, 1);
}
inline void add_edge(int u, int v, int w) {
  mpw[make_pair(u, v)] = w;
  mpc[make_pair(u, v)] = 0;
  add_ver(u, v, w);
  add_ver(v, u, w);
}
inline void del_edge(int u, int v, int w) {
  del_ver(u, v, w);
  del_ver(v, u, w);
}
inline long long calc() {
  long long ret = 1e18;
  if (st3.size()) ret = min(ret, st3.begin()->first);
  auto it = st.begin();
  vector<pair<int, pair<int, int> > > vec;
  for (int i = 0; i < min((int)st.size(), 10); i++, ++it) {
    vec.push_back(*it);
  }
  for (int i = 0; i < (int)vec.size(); i++)
    for (int j = i + 1; j < (int)vec.size(); j++) {
      if (vec[i].second.first != vec[j].second.first &&
          vec[i].second.first != vec[j].second.second &&
          vec[i].second.second != vec[j].second.first &&
          vec[i].second.second != vec[j].second.second)
        ret = min(ret, 1ll * vec[i].first + vec[j].first);
    }
  return ret;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    if (u > v) swap(u, v);
    add_edge(u, v, w);
  }
  printf("%lld\n", calc());
  int q;
  scanf("%d", &q);
  while (q--) {
    int ty, u, v, w;
    scanf("%d%d%d", &ty, &u, &v);
    if (u > v) swap(u, v);
    if (ty)
      scanf("%d", &w), add_edge(u, v, w);
    else
      w = mpw[make_pair(u, v)], del_edge(u, v, w);
    printf("%lld\n", calc());
  }
  return 0;
}
