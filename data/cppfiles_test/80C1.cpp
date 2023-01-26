#include <bits/stdc++.h>
const int N = 1e6, M = N * 4;
inline char gc() {
  static char buf[1 << 20], *ss, *tt;
  if (tt == ss) {
    tt = (ss = buf) + fread(buf, 1, 1 << 20, stdin);
    if (tt == ss) return EOF;
  }
  return *ss++;
}
inline int read() {
  int res, sign = 1;
  char c;
  while ((c = gc()) < '0' || c > '9')
    if (c == '-') sign = -1;
  res = c ^ 48;
  while ((c = gc()) >= '0' && c <= '9')
    res = (res << 3) + (res << 1) + (c ^ 48);
  return res * sign;
}
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
int su[M + 5], mn[M + 5];
inline void pu(int w) {
  su[w] = su[w * 2] + su[w * 2 + 1];
  mn[w] = std::min(mn[w * 2], su[w * 2] + mn[w * 2 + 1]);
}
void bld(int w = 1, int l = 0, int r = n) {
  mn[w] = su[w] = 0;
  if (l == r) return;
  int mi = l + r >> 1;
  bld(w * 2, l, mi), bld(w * 2 + 1, mi + 1, r);
}
void pls(int x, int y, int w = 1, int l = 0, int r = n) {
  if (l == r) {
    su[w] += y, mn[w] += y;
    return;
  }
  int mi = l + r >> 1;
  if (x <= mi)
    pls(x, y, w * 2, l, mi);
  else
    pls(x, y, w * 2 + 1, mi + 1, r);
  pu(w);
}
int main() {
  int tc;
  for (tc = read(); tc; --tc) {
    se.clear();
    n = read(), m = read();
    for (int i = 1; i <= n; ++i) {
      int x;
      x = read();
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
    for (int i = 1; i <= m; ++i) va[i] = read();
    bld();
    std::sort(va + 1, va + m + 1);
    for (int i = 1; i <= n; ++i) pls(i, 1);
    int ap = 0;
    auto it = se.begin(), jt = se.begin();
    for (int i = 1; i <= m; ++i) {
      for (; jt != se.end() && jt->first <= va[i]; ++jt) pls(jt->second, -1);
      for (; it != se.end() && it->first < va[i]; ++it) {
        ++ap;
        pls(it->second, -1);
      }
      ans += ap + mn[1];
    }
    printf("%lld\n", ans);
  }
  return 0;
}
