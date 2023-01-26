#include <bits/stdc++.h>
using namespace std;
char _c;
bool _f;
template <class T>
inline void IN(T& x) {
  x = 0, _f = 0;
  while (_c = getchar(), !isdigit(_c))
    if (_c == '-') _f = 1;
  while (isdigit(_c)) x = x * 10 + _c - '0', _c = getchar();
  if (_f) x = -x;
}
template <class T>
inline void chkmin(T& x, T y) {
  if (x > y) x = y;
}
template <class T>
inline void chkmax(T& x, T y) {
  if (x < y) x = y;
}
const int N = 4e3 + 5;
long long g[N], f[N][N];
int n, m, top, a[N], lc[N], rc[N], sta[N], siz[N];
void dfs(int u) {
  f[u][0] = 0, f[u][1] = 1ll * (m - 1) * a[u], siz[u] = 1;
  if (lc[u]) {
    dfs(lc[u]);
    memset(g, -63, sizeof g);
    for (int i = 0; i <= siz[lc[u]]; ++i)
      for (int j = 0; j <= siz[u]; ++j)
        chkmax(g[i + j], f[lc[u]][i] + f[u][j] - 2ll * i * j * a[u]);
    siz[u] += siz[lc[u]];
    for (int i = 0; i <= siz[u]; ++i) f[u][i] = g[i];
  }
  if (rc[u]) {
    dfs(rc[u]);
    memset(g, -63, sizeof g);
    for (int i = 0; i <= siz[rc[u]]; ++i)
      for (int j = 0; j <= siz[u]; ++j)
        chkmax(g[i + j], f[rc[u]][i] + f[u][j] - 2ll * i * j * a[u]);
    siz[u] += siz[rc[u]];
    for (int i = 0; i <= siz[u]; ++i) f[u][i] = g[i];
  }
}
int main() {
  IN(n), IN(m);
  for (int i = 1; i <= n; ++i) IN(a[i]);
  for (int i = 1; i <= n; ++i) {
    bool flag = false;
    while (top && a[sta[top]] > a[i]) --top, flag = true;
    rc[sta[top]] = i;
    if (flag) lc[i] = sta[top + 1];
    sta[++top] = i;
  }
  memset(f, -63, sizeof f), dfs(sta[1]);
  printf("%lld\n", f[sta[1]][m]);
  return 0;
}
