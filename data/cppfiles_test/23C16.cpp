#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 10000000000000;
long long n, a[4003], m, dp[4003][4003], lson[4003], rson[4003], siz[4003],
    lval[4003], rval[4003];
void solve(long long l, long long r, long long pos) {
  if (l == r) return;
  long long mn, now;
  mn = now = MAXN;
  for (long long i = l; i < pos; ++i)
    if (a[i] < mn) mn = a[i], now = i;
  if (mn < MAXN) {
    lson[pos] = now;
    lval[pos] = mn - a[pos];
    solve(l, pos - 1, now);
  }
  mn = now = MAXN;
  for (long long i = pos + 1; i <= r; ++i)
    if (a[i] < mn) mn = a[i], now = i;
  if (mn < MAXN) {
    rson[pos] = now;
    rval[pos] = mn - a[pos];
    solve(pos + 1, r, now);
  }
}
void dfs(long long pos) {
  siz[pos] = 1;
  if (lson[pos]) {
    dfs(lson[pos]);
    for (long long i = siz[pos]; i >= 0; --i)
      for (long long j = siz[lson[pos]]; j >= 0; --j)
        dp[pos][i + j] = max(dp[pos][i + j], dp[lson[pos]][j] + dp[pos][i] +
                                                 j * (m - j) * lval[pos]);
    siz[pos] += siz[lson[pos]];
  }
  if (rson[pos]) {
    dfs(rson[pos]);
    for (long long i = siz[pos]; i >= 0; --i)
      for (long long j = siz[rson[pos]]; j >= 0; --j)
        dp[pos][i + j] = max(dp[pos][i + j], dp[rson[pos]][j] + dp[pos][i] +
                                                 j * (m - j) * rval[pos]);
    siz[pos] += siz[rson[pos]];
  }
}
signed main() {
  cin >> n >> m;
  for (long long i = 1; i <= n; ++i) cin >> a[i];
  long long to, mn = MAXN;
  for (long long i = 1; i <= n; ++i)
    if (a[i] < mn) mn = a[i], to = i;
  solve(1, n, to);
  dfs(to);
  printf("%lld\n", dp[to][m]);
  return 0;
}
