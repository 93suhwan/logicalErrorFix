#include <bits/stdc++.h>
using namespace std;
const int max_n = 300005;
inline int read() {
  int x = 0;
  bool w = 0;
  char c = getchar();
  while (c < '0' || c > '9') w |= c == '-', c = getchar();
  while (c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return w ? -x : x;
}
inline void write(int x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 ^ 48);
}
struct graph {
  int ct, hd[max_n], nx[max_n * 2], to[max_n * 2];
  graph() { ct = 1; }
  inline void clear(int n) {
    ct = 1;
    for (register int i = 1; i <= n; ++i) hd[i] = 0;
  }
  inline void add(int u, int v) { nx[++ct] = hd[u], hd[u] = ct, to[ct] = v; }
} e;
int n, m, a[max_n], t[max_n];
bool vis[max_n];
inline void dfs(int x) {
  vis[x] = 1;
  for (register int i = e.hd[x]; i; i = e.nx[i]) {
    int v = e.to[i];
    if (vis[v]) continue;
    dfs(v);
  }
}
signed main() {
  int T = read();
  while (T--) {
    n = read(), m = read();
    for (register int i = 1; i <= n; ++i) {
      int x = read();
      a[x] = i;
      ++t[(i - x + n) % n];
    }
    int s = 0, ans[5];
    for (register int i = 0; i < n; ++i) {
      if (t[i] < n - 2 * m) continue;
      for (register int j = 1; j <= n; ++j) vis[j] = 0;
      e.clear(n);
      for (register int j = 1; j <= n; ++j) {
        int p = (i + j - 1) % n + 1;
        if (a[j] != p) e.add(p, a[j]);
      }
      int cnt = 0;
      for (register int j = 1; j <= n; ++j) {
        int p = (i + j - 1) % n + 1;
        if (a[j] != p && !vis[p]) {
          ++cnt;
          dfs(p);
        }
      }
      if (n - t[i] - cnt <= m) ans[++s] = i;
    }
    write(s), putchar(' ');
    for (register int i = 1; i <= s; ++i) write(ans[i]), putchar(' ');
    putchar('\n');
    for (register int i = 0; i <= n; ++i) t[i] = 0;
  }
  return 0;
}
