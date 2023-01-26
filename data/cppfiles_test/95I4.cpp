#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 7;
const long long M = 1e9 + 7;
const long long MAXN = 4e18 + 7;
const long long Mod = 1e9 + 7;
int _, i, j, k, n, m, p, s, T, t, l, r, o, u, v, w, x, y, z, ans, nex, sum, num,
    len, en, sx, sy, tx, ty, th, ma, mi, mod, cnt, la, op, res, flag, cas, bk,
    ret, mid, now, tmp, rt;
int a[N], b[N], c[N], d[N];
char ch;
vector<int> g[N];
string s1, s2, s3, s4;
vector<pair<int, int> > e, f;
int sol(int p) {
  int i, j;
  e.clear();
  f.clear();
  for (i = 1; i <= n; ++i) {
    b[i] = 0;
    for (j = 1; j <= p; ++j) e.emplace_back(pair<int, int>(g[i][j], i));
    for (; j <= m; ++j) f.emplace_back(pair<int, int>(g[i][j], i));
  }
  sort((e).begin(), (e).end());
  sort((f).begin(), (f).end());
  reverse((f).begin(), (f).end());
  int s = 0;
  for (i = 1; i < n; ++i) {
    for (j = (i - 1) * p; j < i * p; ++j) {
      b[e[j].second]++;
      if (b[e[j].second] == m) ++s;
    }
    for (j = (i - 1) * (m - p); j < i * (m - p); ++j) {
      b[f[j].second]++;
      if (b[f[j].second] == m) ++s;
    }
    if (i == s && e[i * p - 1].first != e[i * p].first &&
        f[j - 1].first != f[j].first)
      return 1;
  }
  return 0;
}
signed main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; ++i) {
      g[i].resize(m + 1);
      for (j = 1; j <= m; ++j) {
        scanf("%d", &g[i][j]);
      }
    }
    p = -1;
    mi = M;
    ma = -1;
    for (i = 2; i <= n; ++i) {
      v = g[i][1];
      for (j = 1; j <= m; ++j) {
        if (g[i][j] <= g[1][j])
          break;
        else
          v = max(v, g[i][j]);
      }
      if (j == 1 || j > m) continue;
      u = g[i][j];
      for (k = j; k <= m; ++k) {
        if (g[i][k] >= g[1][k])
          break;
        else
          u = min(u, g[i][j]);
      }
      if (k > m && (v > ma || u < mi)) {
        mi = u;
        ma = v;
        p = j;
      }
    }
    if (p != -1 && sol(p - 1)) {
      printf("YES\n");
      for (i = 1; i <= n; ++i)
        if (b[i] == m)
          printf("B");
        else
          printf("R");
      printf(" %d\n", p - 1);
      continue;
    }
    p = -1;
    mi = M;
    ma = -1;
    for (i = 2; i <= n; ++i) {
      v = g[i][1];
      for (j = 1; j <= m; ++j) {
        if (g[i][j] >= g[1][j])
          break;
        else
          u = min(u, g[i][j]);
      }
      if (j == 1 || j > m) continue;
      v = g[i][j];
      for (k = j; k <= m; ++k) {
        if (g[i][k] <= g[1][k])
          break;
        else
          v = max(v, g[i][j]);
      }
      if (k > m && (v > ma || u < mi)) {
        mi = u;
        ma = v;
        p = j;
      }
    }
    if (p != -1 && sol(p - 1)) {
      printf("YES\n");
      for (i = 1; i <= n; ++i)
        if (b[i] == m)
          printf("B");
        else
          printf("R");
      printf(" %d\n", p - 1);
    } else
      printf("NO\n");
  }
  return 0;
}
