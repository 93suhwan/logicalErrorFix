#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  char c = getchar();
  long long x = 0, w = 1;
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') w = -1, c = getchar();
  while (isdigit(c)) x = x * 10 + c - 48, c = getchar();
  return x * w;
}
inline void cmx(int& a, int b) { a = a > b ? a : b; }
inline void cmn(int& a, int b) { a = a < b ? a : b; }
const int N = 200005, M = N * 4;
int n, K, tt, vis[N], fa[N], dep[N], ps[N], dl[N], dr[N], mx[N * 4], tg[N * 4];
vector<int> g[N];
void dfs(int x, int p) {
  dl[x] = ++tt;
  ps[tt] = x;
  dep[x] = dep[p] + 1;
  fa[x] = p;
  for (auto y : g[x])
    if (y != p) dfs(y, x);
  dr[x] = tt;
}
inline void up(int x) { mx[x] = max(mx[x << 1], mx[x << 1 | 1]); }
inline void cov(int x, int v) {
  tg[x] += v;
  mx[x] -= v;
}
inline void dn(int x) {
  if (!tg[x]) return;
  cov(x << 1, tg[x]);
  cov(x << 1 | 1, tg[x]);
  tg[x] = 0;
}
void build(int x, int l, int r) {
  if (l == r) {
    mx[x] = dep[ps[l]];
    tg[x] = 0;
    return;
  }
  int m = l + r >> 1;
  build(x << 1, l, m);
  build(x << 1 | 1, m + 1, r);
  up(x);
  tg[x] = 0;
}
void upd(int x, int l, int r, int tl, int tr) {
  if (tl <= l && r <= tr) {
    cov(x, 1);
    return;
  }
  int m = l + r >> 1;
  dn(x);
  if (tl <= m) upd(x << 1, l, m, tl, tr);
  if (tr > m) upd(x << 1 | 1, m + 1, r, tl, tr);
  up(x);
}
int qry(int x, int l, int r) {
  if (l == r) return l;
  int m = l + r >> 1;
  dn(x);
  return mx[x << 1] == mx[x] ? qry(x << 1, l, m) : qry(x << 1 | 1, m + 1, r);
}
int main() {
  n = rd();
  K = rd();
  tt = 0;
  long long ans = -1ll * (n / 2) * (n - n / 2);
  for (register int i = (1); i <= (n); ++i) g[i].clear();
  for (register int i = (1); i <= (n - 1); ++i) {
    int u = rd(), v = rd();
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  build(1, 1, n);
  int s = n, t = n / 2;
  for (register int i = (1); i <= (n); ++i) vis[i] = 0;
  for (register int i = (1); i <= (K); ++i) {
    if (mx[1] > 0) {
      s -= mx[1];
      int p = qry(1, 1, n);
      while (p && !vis[p]) {
        upd(1, 1, n, dl[p], dr[p]);
        vis[p] = 1;
        p = fa[p];
      }
    }
    if (s >= n / 2)
      ans = max(ans, 1ll * (n - i - t) * (i - t));
    else
      ans = max(ans, 1ll * (n - i - s) * (i - s));
  }
  printf("%lld\n", ans);
  return 0;
}
