#include <bits/stdc++.h>
const int N = 4005;
int lc[N], rc[N], st[N], top, val[N], n, m, siz[N];
long long f[N][N];
inline int Read() {
  char ch;
  while ((ch = getchar()) < '0' || ch > '9')
    ;
  int x = ch ^ 48;
  while ((ch = getchar()) >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48);
  return x;
}
inline void Work(const int i) {
  while (top && val[st[top]] > val[i]) top--;
  int u = st[top];
  lc[i] = rc[u];
  rc[u] = i;
  st[++top] = i;
  return;
}
inline long long Max(const long long x, const long long y) {
  return x > y ? x : y;
}
inline void Dfs(const int u) {
  if (!u) return;
  Dfs(lc[u]);
  Dfs(rc[u]);
  siz[u] = siz[lc[u]] + siz[rc[u]] + 1;
  for (register int i = 0; i <= siz[lc[u]]; i++) {
    for (register int j = 0; j <= siz[rc[u]]; j++) {
      if (i + j > m) break;
      f[u][i + j] =
          Max(f[u][i + j], f[lc[u]][i] + f[rc[u]][j] - 2ll * i * j * val[u]);
    }
  }
  for (register int i = siz[u]; i; i--)
    f[u][i] = Max(
        f[u][i], f[u][i - 1] + 1ll * (m - 1) * val[u] - 2ll * (i - 1) * val[u]);
  return;
}
inline void Init() {
  n = Read();
  m = Read();
  for (register int i = 1; i <= n; i++) {
    val[i] = Read();
    Work(i);
  }
  return;
}
int main() {
  Init();
  Dfs(rc[0]);
  printf("%lld\n", f[rc[0]][m]);
  return 0;
}
