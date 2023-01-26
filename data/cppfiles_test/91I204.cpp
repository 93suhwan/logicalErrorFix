#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
class Data {
 public:
  long long minSum;
  pair<int, pair<int, int> > minEdge;
  pair<int, int> ed[3];
  Data() {
    minSum = 0x3f3f3f3f3f3f3f3f;
    minEdge = make_pair(0x3f3f3f3f, make_pair(0x3f3f3f3f, 0x3f3f3f3f));
    for (int i = 0; i < 3; ++i) ed[i] = make_pair(0x3f3f3f3f, 0x3f3f3f3f);
    return;
  }
  inline Data operator+(const Data &oth) const {
    Data ret;
    ret.minSum = min(minSum, oth.minSum);
    ret.minEdge = min(minEdge, oth.minEdge);
    for (int i = 0; i < 3; ++i) ret.ed[i] = ed[i];
    for (int i = 0; i < 3; ++i) {
      bool f = false;
      for (int j = 0; j < 3; ++j)
        if (ret.ed[j].second == oth.ed[i].second)
          ret.ed[j].first = min(ret.ed[j].first, oth.ed[i].first), f = true;
      if (f) {
        sort(ret.ed, ret.ed + 3);
        continue;
      }
      if (oth.ed[i] < ret.ed[0])
        ret.ed[2] = ret.ed[1], ret.ed[1] = ret.ed[0], ret.ed[0] = oth.ed[i];
      else if (oth.ed[i] < ret.ed[1])
        ret.ed[2] = ret.ed[1], ret.ed[1] = oth.ed[i];
      else if (oth.ed[i] < ret.ed[2])
        ret.ed[2] = oth.ed[i];
    }
    return ret;
  }
};
class SegmentTree {
 public:
  static const int siz = 131072;
  Data dat[siz << 1];
  inline void update(int x, Data k) {
    for (dat[x += siz] = k; x >>= 1;) {
      dat[x] = dat[x << 1] + dat[x << 1 | 1];
    }
    return;
  }
  inline Data query(int l, int r) {
    Data ret;
    for (l += siz, r += siz + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ret = ret + dat[l++];
      if (r & 1) ret = ret + dat[--r];
    }
    return ret;
  }
} seg;
int n, m, q;
set<pair<int, int> > S[maxn];
map<int, int> ed[maxn];
inline void recalc(int u) {
  Data res;
  if (S[u].size() >= 3) res.minSum = 0;
  int tot = 0;
  for (set<pair<int, int> >::iterator it = S[u].begin();
       it != S[u].end() && tot < 3; ++it) {
    if (S[u].size() >= 3) res.minSum += it->first;
    res.ed[tot++] = *it;
    res.minEdge =
        min(res.minEdge, make_pair(it->first, make_pair(u, it->second)));
  }
  seg.update(u, res);
  return;
}
inline void insert(int u, int v, int w) {
  S[u].insert(make_pair(w, v));
  S[v].insert(make_pair(w, u));
  recalc(u), recalc(v);
  return;
}
inline void erase(int u, int v) {
  int w = ed[u][v];
  S[u].erase(make_pair(w, v));
  S[v].erase(make_pair(w, u));
  recalc(u), recalc(v);
  return;
}
inline long long query() {
  long long ret = 0x3f3f3f3f3f3f3f3f;
  Data res = seg.query(0, n - 1);
  ret = res.minSum;
  int u = res.minEdge.second.first, v = res.minEdge.second.second;
  if (u > v) swap(u, v);
  if (u - 1 >= 0) {
    Data res2 = seg.query(0, u - 1);
    for (int it = 0; it < 3; ++it)
      if (res2.ed[it].second != u && res2.ed[it].second != v)
        ret = min(ret, (long long)res.minEdge.first + res2.ed[it].first);
  }
  if (u + 1 <= v - 1) {
    Data res2 = seg.query(u + 1, v - 1);
    for (int it = 0; it < 3; ++it)
      if (res2.ed[it].second != u && res2.ed[it].second != v)
        ret = min(ret, (long long)res.minEdge.first + res2.ed[it].first);
  }
  if (v + 1 <= n - 1) {
    Data res2 = seg.query(v + 1, n - 1);
    for (int it = 0; it < 3; ++it)
      if (res2.ed[it].second != u && res2.ed[it].second != v)
        ret = min(ret, (long long)res.minEdge.first + res2.ed[it].first);
  }
  int ptr = 0;
  for (set<pair<int, int> >::iterator it = S[u].begin();
       it != S[u].end() && ptr < 3; ++it, ++ptr) {
    int qtr = 0;
    for (set<pair<int, int> >::iterator jt = S[v].begin();
         jt != S[v].end() && qtr < 3; ++jt, ++qtr)
      if (it->second != jt->second && it->second != v && jt->second != u) {
        ret = min(ret, (long long)it->first + jt->first);
      }
  }
  return ret;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) recalc(i);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    --u, --v;
    insert(u, v, w), ed[u][v] = ed[v][u] = w;
  }
  printf("%lld\n", query());
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int tp, u, v, w;
    scanf("%d%d%d", &tp, &u, &v);
    --u, --v;
    if (tp == 0)
      erase(u, v);
    else
      scanf("%d", &w), insert(u, v, w), ed[u][v] = ed[v][u] = w;
    printf("%lld\n", query());
  }
  return 0;
}
