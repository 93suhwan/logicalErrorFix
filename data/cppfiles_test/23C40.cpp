#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 4010;
const long long INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
long long n, m, rt, a[MAXN];
long long p[MAXN], ls[MAXN], rs[MAXN], siz[MAXN];
long long stk[MAXN], top, dp[MAXN][MAXN];
template <typename T>
inline bool read(T &a) {
  a = 0;
  char c = getchar();
  long long f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    a = a * 10 + (c ^ 48);
    c = getchar();
  }
  return a *= f, true;
}
template <typename A, typename... B>
inline bool read(A &x, B &...y) {
  return read(x) && read(y...);
}
void DFS(long long x) {
  siz[x] = 1, dp[x][0] = 0, dp[x][1] = m * a[x] - a[x];
  if (ls[x]) {
    DFS(ls[x]);
    for (long long i = siz[x]; i >= 0; --i) {
      for (long long j = 1; j <= siz[ls[x]]; ++j)
        dp[x][i + j] =
            max(dp[x][i + j], dp[x][i] + dp[ls[x]][j] - 2 * i * j * a[x]);
    }
    siz[x] += siz[ls[x]];
  }
  if (rs[x]) {
    DFS(rs[x]);
    for (long long i = siz[x]; i >= 0; --i) {
      for (long long j = 1; j <= siz[rs[x]]; ++j)
        dp[x][i + j] =
            max(dp[x][i + j], dp[x][i] + dp[rs[x]][j] - 2 * i * j * a[x]);
    }
    siz[x] += siz[rs[x]];
  }
}
signed main() {
  read(n), read(m);
  for (long long i = 1; i <= n; ++i) read(a[i]);
  for (long long i = 1; i <= n; ++i) {
    while (top && a[stk[top]] > a[i]) ls[i] = stk[top--];
    if (top) rs[stk[top]] = i;
    stk[++top] = i;
  }
  rt = stk[1];
  DFS(rt);
  printf("%lld\n", dp[rt][m]);
  return 0;
}
