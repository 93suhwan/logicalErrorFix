#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int res = 0, f = 1;
  char ch;
  while (ch = getchar(), ch < '0' || ch > '9')
    if (ch == '-') f = -1;
  while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
  return res * f;
}
const int N = 2e5 + 5, INF = 0x3f3f3f3f;
const long long inf = 0x3f3f3f3f3f3f3f3f;
long long fpool[N * 20], ppool[N * 20], spool[N * 20], dpool[N * 20],
    gpool[N * 20];
int o;
long long *f[N], *pre[N], *suf[N], *d[N], *g[N];
int sz[N];
struct seg {
  int l, r;
  inline bool operator<(const seg &a) const {
    return l != a.l ? l < a.l : r > a.r;
  }
} w[N], s[N];
bool ck[N];
int t, n, m;
long long a[N];
inline void readdata() {
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  for (int i = 1; i <= m; ++i) w[i].l = read(), w[i].r = read();
}
inline void build() {
  sort(a + 1, a + n + 1), a[n + 1] = INF, sort(w + 1, w + m + 1);
  for (int i = 1, j = 1; i <= m; ++i) {
    while (j <= n && a[j] < w[i].l) ++j;
    if (a[j] >= w[i].l && a[j] <= w[i].r) ck[i] = 1;
  }
  t = 0;
  for (int i = 1; i <= m; ++i)
    if (!ck[i]) {
      while (t && s[t].r >= w[i].r) --t;
      s[++t] = w[i];
    }
  int j = 1;
  while (j <= t && s[j].r < a[1]) ++j;
  int mr = a[1];
  for (int i = 1; i < j; ++i) mr = min(mr, s[i].r);
  --j;
  for (int i = 1, l = j; i <= n; ++i) {
    while (j < t && s[j + 1].r < a[i + 1]) ++j;
    sz[i] = j - l, f[i] = fpool + o, d[i] = dpool + o, g[i] = gpool + o;
    pre[i] = ppool + o, suf[i] = spool + o, o += sz[i] + 1;
    for (int k = 1; k <= sz[i]; ++k) d[i][k] = s[l + k].l - a[i];
    int nr = a[i + 1];
    for (int k = sz[i]; ~k; --k)
      g[i][k] = a[i + 1] - nr, nr = min(nr, s[l + k].r);
    l = j;
  }
  for (int i = 0; i <= sz[1]; ++i)
    f[1][i] = 0ll + 2 * min(a[1] - mr, d[1][i]) + max(a[1] - mr, d[1][i]);
  pre[1][0] = f[1][0] + g[1][0];
  for (int i = 1; i <= sz[1]; ++i)
    pre[1][i] = min(pre[1][i - 1], f[1][i] + g[1][i]);
  suf[1][sz[1]] = f[1][sz[1]] + 2 * g[1][sz[1]];
  for (int i = sz[1] - 1; ~i; --i)
    suf[1][i] = min(suf[1][i + 1], f[1][i] + 2 * g[1][i]);
}
inline void solve() {
  for (int i = 2; i <= n; ++i) {
    int p = sz[i - 1] + 1;
    for (int j = 0; j <= sz[i]; ++j) {
      while (p && g[i - 1][p - 1] <= d[i][j]) --p;
      if (p != sz[i - 1] + 1)
        f[i][j] = suf[i - 1][p] + d[i][j];
      else
        f[i][j] = inf;
      if (p != 0) f[i][j] = min(f[i][j], pre[i - 1][p - 1] + 2 * d[i][j]);
    }
    pre[i][0] = f[i][0] + g[i][0];
    for (int j = 1; j <= sz[i]; ++j)
      pre[i][j] = min(pre[i][j - 1], f[i][j] + g[i][j]);
    suf[i][sz[i]] = f[i][sz[i]] + 2 * g[i][sz[i]];
    for (int j = sz[i] - 1; ~j; --j)
      suf[i][j] = min(suf[i][j + 1], f[i][j] + 2 * g[i][j]);
  }
  printf("%lld\n", f[n][sz[n]]);
}
inline void clear() {
  for (int i = 1; i <= m; ++i) ck[i] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= sz[i]; ++j)
      f[i][j] = d[i][j] = g[i][j] = pre[i][j] = suf[i][j] = 0;
    sz[i] = 0;
  }
}
int main() {
  int T = read();
  while (T--) {
    readdata();
    build();
    solve();
    clear();
  }
  return 0;
}
