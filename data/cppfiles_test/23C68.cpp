#include <bits/stdc++.h>
using namespace std;
const long long N = 4e3 + 1e2 + 7;
long long n, m, st[N], top, a[N];
long long f[N][N], tot, g[N];
long long dfs(long long l, long long r, long long pw) {
  long long p = min_element(a + l, a + r + 1) - a;
  long long x = ++tot;
  for (long long j = 0; j <= r - l + 1; j++) f[x][j] = -1e18;
  f[x][0] = 0;
  f[x][1] = 0;
  long long ls = -1, rs = -1;
  if (l <= p - 1) ls = dfs(l, p - 1, a[l]);
  if (p + 1 <= r) rs = dfs(p + 1, r, a[l]);
  long long sz = 1;
  if (ls != -1) {
    long long szl = p - l;
    long long mnl = *min_element(a + l, a + p);
    for (long long j = 0; j <= szl + sz; j++) g[j] = -1e18;
    for (long long j = 0; j <= szl; j++)
      for (long long k = 0; k <= sz; k++)
        g[j + k] =
            max(g[j + k], f[ls][j] + f[x][k] + (m - j) * j * (mnl - a[p]));
    sz += szl;
    for (long long j = 0; j <= sz; j++) f[x][j] = max(f[x][j], g[j]);
  }
  if (rs != -1) {
    long long szr = r - p;
    long long mnr = *min_element(a + p + 1, a + r + 1);
    for (long long j = 0; j <= szr + sz; j++) g[j] = -1e18;
    for (long long j = 0; j <= szr; j++)
      for (long long k = 0; k <= sz; k++)
        g[j + k] =
            max(g[j + k], f[rs][j] + f[x][k] + (m - j) * j * (mnr - a[p]));
    sz += szr;
    for (long long j = 0; j <= sz; j++) f[x][j] = max(f[x][j], g[j]);
  }
  return x;
}
signed main() {
  scanf("%lld%lld", &n, &m);
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
  dfs(1, n, 0);
  printf("%lld\n", f[1][m]);
}
