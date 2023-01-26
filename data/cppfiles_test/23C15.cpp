#include <bits/stdc++.h>
using namespace std;
const long long S = 1 << 22;
char p0[S], *p1, *p2;
inline long long read() {
  long long x = 0, f = 0;
  char c =
      (p2 == p1 && (p2 = (p1 = p0) + fread(p0, 1, S, stdin)) == p1 ? EOF
                                                                   : *p1++);
  while (!isdigit(c)) {
    if (c == '-') f = 1;
    c = (p2 == p1 && (p2 = (p1 = p0) + fread(p0, 1, S, stdin)) == p1 ? EOF
                                                                     : *p1++);
  }
  while (isdigit(c))
    x = (x << 1) + (x << 3) + (c & 15),
    c = (p2 == p1 && (p2 = (p1 = p0) + fread(p0, 1, S, stdin)) == p1 ? EOF
                                                                     : *p1++);
  return f ? -x : x;
}
const long long MAXN = 4000;
long long a[MAXN + 10], st[MAXN + 10], top = 0;
long long lc[MAXN + 10], rc[MAXN + 10];
long long n, m;
long long dp[MAXN + 10][MAXN + 10], siz[MAXN + 10];
void dfs(long long x) {
  if (lc[x]) dfs(lc[x]);
  if (rc[x]) dfs(rc[x]);
  siz[x] = siz[lc[x]] + siz[rc[x]] + 1;
  for (long long i = 0; i <= siz[lc[x]]; ++i) {
    for (long long j = 0; j <= siz[rc[x]]; ++j) {
      dp[x][i + j] =
          max(dp[x][i + j], dp[lc[x]][i] + dp[rc[x]][j] - 2 * a[x] * (i * j));
      dp[x][i + j + 1] = max(
          dp[x][i + j + 1], dp[lc[x]][i] + dp[rc[x]][j] - 2 * a[x] * (i) * (j) +
                                m * a[x] - 2 * a[x] * (i + j) - a[x]);
    }
  }
}
signed main() {
  n = read(), m = read();
  for (long long i = 1; i <= n; ++i) a[i] = read();
  for (long long i = 1; i <= n; ++i) {
    long long k = top;
    while (k && a[st[k]] > a[i]) k--;
    if (k) rc[st[k]] = i;
    if (k < top) lc[i] = st[k + 1];
    st[++k] = i;
    top = k;
  }
  dfs(st[1]);
  long long ans = dp[st[1]][m];
  ;
  cout << ans << endl;
  return 0;
}
