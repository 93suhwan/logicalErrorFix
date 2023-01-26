#include <bits/stdc++.h>
const int N = 4086;
int n, m, rt, tp, st[N], sze[N], ls[N], rs[N];
long long f[N][N], a[N];
long long Max(long long a, long long b) { return a > b ? a : b; }
int Min(int a, int b) { return a < b ? a : b; }
int Abs(int x) { return x < 0 ? -x : x; }
long long read() {
  char ch = getchar();
  long long nn = 0, ssss = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') ssss *= -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    nn = nn * 10 + (ch - '0');
    ch = getchar();
  }
  return nn * ssss;
}
bool dfs(int np) {
  int lw = Abs(a[ls[np]] - a[np]), rw = Abs(a[rs[np]] - a[np]);
  sze[np] = 1;
  if (ls[np]) {
    dfs(ls[np]);
    for (int i = Min(sze[np], m); i + 1; i--)
      for (int j = Min(sze[ls[np]], m); j + 1; j--)
        f[np][i + j] =
            Max(f[np][i + j], f[np][i] + f[ls[np]][j] + 1ll * j * (m - j) * lw);
    sze[np] += sze[ls[np]];
  }
  if (rs[np]) {
    dfs(rs[np]);
    for (int i = Min(sze[np], m); i + 1; i--)
      for (int j = Min(sze[rs[np]], m); j + 1; j--)
        f[np][i + j] =
            Max(f[np][i + j], f[np][i] + f[rs[np]][j] + 1ll * j * (m - j) * rw);
    sze[np] += sze[rs[np]];
  }
  return true;
}
int main() {
  n = (int)read();
  m = (int)read();
  a[rt = n + 1] = 1145141919000;
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    int lt = tp;
    while (tp && a[st[tp]] > a[i]) tp--;
    if (tp) rs[st[tp]] = i;
    if (tp < lt) ls[i] = st[tp + 1];
    st[++tp] = i;
    if (a[i] < a[rt]) rt = i;
  }
  dfs(rt);
  printf("%lld", f[rt][m]);
}
