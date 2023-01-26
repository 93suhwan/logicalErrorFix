#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
  return x * f;
}
const int N = 2e5 + 10;
int h[N], cnt, fa[N], toroot[N], ans[N], n, m;
struct node {
  int u, v, nxt, w;
} e[N << 1];
inline void add(int x, int y, int z) { e[++cnt] = {x, y, h[x], z}, h[x] = cnt; }
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void dfs(int x, int fa) {
  for (int i = h[x], y; i; i = e[i].nxt)
    if ((y = e[i].v) != fa)
      ans[i] = ans[i ^ 1] = (find(x + n) == find(y) || find(x) == find(y + n)),
      dfs(y, x);
}
void solve() {
  n = read(), m = read(), cnt = 1;
  for (int i = 1; i <= n * 2; i++) fa[i] = i, h[i] = 0;
  for (int i = 1; i < n; i++) {
    int x = read(), y = read(), z = read();
    add(x, y, z), add(y, x, z);
    if (~z)
      if (__builtin_popcount(z) & 1)
        fa[find(x + n)] = find(y), fa[find(y + n)] = find(x);
      else
        fa[find(x)] = find(y), fa[find(y + n)] = find(x + n);
  }
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read(), z = read();
    if (z)
      fa[find(x + n)] = find(y), fa[find(y + n)] = find(x);
    else
      fa[find(x)] = find(y), fa[find(y + n)] = find(x + n);
  }
  for (int i = 1; i <= n; i++)
    if (find(i) == find(i + n)) return (void)puts("NO");
  dfs(1, 0), puts("YES");
  for (int i = 2; i < n * 2; i += 2)
    printf("%d %d %d\n", e[i].u, e[i].v, (~e[i].w) ? e[i].w : ans[i]);
}
int main() {
  int T = read();
  while (T--) solve();
}
