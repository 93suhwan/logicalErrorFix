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
long long n, m, tmp[np];
inline void dfs(long long x) {
  dp[x][0] = 0;
  dp[x][1] = m * val[x] - val[x];
  siz[x] = 1;
  if (!ls[x] && !rs[x]) return;
  if (ls[x]) {
    dfs(ls[x]);
    for (long long i = 0; i <= siz[x] + siz[ls[x]]; i++) tmp[i] = 0;
    for (long long i = 0; i <= siz[x]; i++) {
      for (long long j = 0; j <= siz[ls[x]]; j++) {
        tmp[i + j] =
            max(tmp[i + j], dp[x][i] + dp[ls[x]][j] - val[x] * 2 * i * j);
      }
    }
    siz[x] += siz[ls[x]];
    for (long long i = 0; i <= siz[x]; i++) dp[x][i] = tmp[i];
  }
  if (rs[x]) {
    dfs(rs[x]);
    for (long long i = 0; i <= siz[x] + siz[rs[x]]; i++) tmp[i] = 0;
    for (long long i = 0; i <= siz[x]; i++) {
      for (long long j = 0; j <= siz[rs[x]]; j++) {
        tmp[i + j] =
            max(tmp[i + j], dp[x][i] + dp[rs[x]][j] - val[x] * 2 * i * j);
      }
    }
    siz[x] += siz[rs[x]];
    for (long long i = 0; i <= siz[x]; i++) dp[x][i] = tmp[i];
  }
}
signed main() {
  dp[0][0] = 0;
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
  return 0;
}
