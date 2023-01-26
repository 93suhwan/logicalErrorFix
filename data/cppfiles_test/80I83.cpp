#include <bits/stdc++.h>
const int N = 1e6, M = N * 4;
int n, m, va[N + 5];
long long ans;
std::set<std::pair<int, int> > se;
int nv[N + 5], bt[N + 5];
inline void pls1(int w) {
  for (; w <= n; w += w & -w) ++bt[w];
}
inline int sum(int w) {
  int x = 0;
  for (; w; w -= w & -w) x += bt[w];
  return x;
}
int mn[M + 5], tg[M + 5];
inline void pt(int w, int z) { mn[w] += z, tg[w] += z; }
inline void pd(int w) {
  pt(w * 2, tg[w]), pt(w * 2 + 1, tg[w]);
  tg[w] = 0;
}
inline void pu(int w) { mn[w] = std::min(mn[w * 2], mn[w * 2 + 1]); }
void bld(int w = 1, int l = 1, int r = n) {
  mn[w] = tg[w] = 0;
  if (l == r) return;
  int mi = l + r >> 1;
  bld(w * 2, l, mi), bld(w * 2 + 1, mi + 1, r);
}
void pls(int x, int y, int z, int w = 1, int l = 0, int r = n) {
  if (x <= l && r <= y) {
    pt(w, z);
    return;
  }
  pd(w);
  int mi = l + r >> 1;
  if (x <= mi) pls(x, y, z, w * 2, l, mi);
  if (y > mi) pls(x, y, z, w * 2 + 1, mi + 1, r);
  pu(w);
}
int main() {
  int tc;
  for (scanf("%d", &tc); tc; --tc) {
    se.clear();
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      int x;
      scanf("%d", &x);
      se.insert(std::make_pair(x, i));
    }
    ans = 0;
    for (int i = 1; i <= n; ++i) bt[i] = 0;
    int nw = 0;
    for (auto it : se) nv[it.second] = ++nw;
    for (int i = 1; i <= n; ++i) {
      pls1(nv[i]);
      ans += nv[i] - sum(nv[i]);
    }
    for (int i = 1; i <= m; ++i) scanf("%d", &va[i]);
    bld();
    std::sort(va + 1, va + m + 1);
    for (int i = 1; i <= n; ++i) pls(i, n, 1);
    auto it = se.begin(), jt = se.begin();
    for (int i = 1; i <= m; ++i) {
      for (; jt != se.end() && jt->first <= va[i]; ++jt) pls(jt->second, n, -1);
      for (; it != se.end() && it->first < va[i]; ++it)
        pls(0, it->second - 1, 1);
      ans += mn[1];
    }
    printf("%lld\n", ans);
  }
  return 0;
}
