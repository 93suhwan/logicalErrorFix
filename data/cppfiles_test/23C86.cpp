#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long s = 0, f = 1;
  char _ch = getchar();
  while (!('0' <= _ch && _ch <= '9')) (_ch == '-') && (f = -1), _ch = getchar();
  while (('0' <= _ch && _ch <= '9')) s = s * 10 + _ch - 48, _ch = getchar();
  return s * f;
}
const long long N = 4010, inf = 1e17;
long long n, m, a[N], stk[N], top, fa[N], ls[N], rs[N], sz[N];
long long f[N][N];
void dfs(long long x) {
  sz[x] = 1;
  if (ls[x]) {
    dfs(ls[x]);
    long long lm1 = min(sz[x], m), lm2;
    for (register long long i = lm1; i >= 0; i--) {
      lm2 = min(sz[ls[x]], m);
      for (register long long j = lm2; j >= 0; j--)
        f[x][i + j] =
            max(f[x][i + j],
                f[x][i] + f[ls[x]][j] + 1ll * j * (m - j) * (a[ls[x]] - a[x]));
    }
    sz[x] += sz[ls[x]];
  }
  if (rs[x]) {
    dfs(rs[x]);
    long long lm1 = min(sz[x], m), lm2;
    for (register long long i = lm1; i >= 0; i--) {
      lm2 = min(sz[rs[x]], m);
      for (register long long j = lm2; j >= 0; j--)
        f[x][i + j] =
            max(f[x][i + j],
                f[x][i] + f[rs[x]][j] + 1ll * j * (m - j) * (a[rs[x]] - a[x]));
    }
    sz[x] += sz[rs[x]];
  }
}
signed main() {
  n = read(), m = read();
  for (register long long i = 1; i <= n; i++) a[i] = read();
  for (register long long i = 1; i <= n; i++) {
    while (top && a[i] < a[stk[top]]) ls[i] = stk[top--];
    rs[stk[top]] = i;
    stk[++top] = i;
  }
  for (register long long i = 1; i <= n; i++) fa[ls[i]] = fa[rs[i]] = i;
  long long p = 1;
  for (register long long i = 1; i <= n; i++)
    if (a[i] < a[p]) p = i;
  dfs(p);
  cout << f[p][m] << '\n';
  return 0;
}
