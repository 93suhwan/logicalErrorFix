#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
  return x * f;
}
const long long N(4e3 + 5);
long long rt;
long long top;
long long n, m;
long long a[N];
long long stk[N];
long long siz[N];
long long w[N][2];
long long ch[N][2];
long long dp[N][N];
inline void dfs(long long u) {
  siz[u] = 1;
  for (long long c = (0); c <= (1); c++)
    if (ch[u][c]) {
      long long v = ch[u][c];
      dfs(v);
      for (long long i = (siz[u]); i >= (0); i--)
        for (long long j = (siz[v]); j >= (0); j--)
          ((dp[u][i + j]) = max((dp[u][i + j]),
                                (dp[u][i] + dp[v][j] + j * (m - j) * w[u][c])));
      siz[u] += siz[v];
    }
}
signed main() {
  n = read(), m = read();
  for (long long i = (1); i <= (n); i++) a[i] = read();
  rt = 1;
  for (long long i = (1); i <= (n); i++) {
    long long k = top;
    if (a[i] < a[rt]) rt = i;
    while (k && a[stk[k]] > a[i]) k--;
    if (k) ch[stk[k]][1] = i, w[stk[k]][1] = a[i] - a[stk[k]];
    if (k < top) ch[i][0] = stk[k + 1], w[i][0] = a[stk[k + 1]] - a[i];
    stk[top = (++k)] = i;
  }
  dfs(rt), cout << dp[rt][m];
  return 0;
}
