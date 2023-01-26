#include <bits/stdc++.h>
using namespace std;
template <typename _T>
inline void read(_T &x) {
  x = 0;
  long long f = 1;
  char s = getchar();
  while (s < '0' || s > '9') {
    f = 1;
    if (s == '-') f = -1;
    s = getchar();
  }
  while ('0' <= s && s <= '9') {
    x = (x << 3) + (x << 1) + s - '0';
    s = getchar();
  }
  x *= f;
}
const long long np = 1e5 + 5;
const long long INF = 1 << 30;
long long val[np];
long long dp[4005][4005];
long long ls[np], rs[np];
long long sta[np], top;
long long siz[np];
long long n, m;
inline void dfs(long long x) {
  dp[x][0] = 0;
  if (!x) return;
  siz[x] = 1;
  if (!ls[x] && !rs[x]) {
    dp[x][1] = val[x] * m - val[x];
    return;
  }
  if (ls[x]) dfs(ls[x]);
  if (rs[x]) dfs(rs[x]);
  siz[x] += siz[ls[x]] + siz[rs[x]];
  long long q = min(siz[x], m);
  for (long long i = 1; i <= q; i++) {
    long long tmp(-1);
    for (long long a = 0; a <= i && a <= siz[ls[x]]; a++) {
      if (dp[ls[x]][a] == -1 || dp[rs[x]][i - a] == -1) continue;
      tmp =
          max(tmp, dp[ls[x]][a] + dp[rs[x]][i - a] - a * (i - a) * val[x] * 2);
    }
    dp[x][i] = tmp;
  }
  for (long long i = 1; i <= q; i++) {
    long long tmp(-1);
    for (long long a = 0; a < i && a <= siz[ls[x]]; a++) {
      if (dp[ls[x]][a] == -1 || dp[rs[x]][i - a - 1] == -1) continue;
      tmp = max(tmp, dp[ls[x]][a] + dp[rs[x]][i - a - 1] -
                         2 * a * (i - a - 1) * val[x] - val[x] * a * 2 -
                         val[x] - val[x] * (i - a - 1) * 2 + val[x] * m);
    }
    dp[x][i] = max(dp[x][i], tmp);
  }
}
signed main() {
  memset(dp, -1, sizeof(dp));
  read(n), read(m);
  for (long long i = 1; i <= n; i++) read(val[i]);
  for (long long i = 1; i <= n; i++) {
    long long top_ = top;
    while (top && val[sta[top]] > val[i]) top--;
    if (top) rs[sta[top]] = i;
    if (top < top_) ls[i] = sta[top + 1];
    sta[++top] = i;
  }
  dfs(sta[1]);
  printf("%lld\n", dp[sta[1]][m]);
}
