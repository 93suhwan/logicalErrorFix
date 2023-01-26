#include <bits/stdc++.h>
inline int read() {
  char c = getchar();
  int x = 0;
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - 48, c = getchar();
  return x;
}
const int maxn = 3e5 + 5;
struct EE {
  int x, y;
} ee[maxn];
struct E {
  int v, nxt;
} e[maxn << 1];
int fa[maxn], dep[maxn], Fa[maxn], head[maxn], num, pre[maxn], n, m, ans[maxn],
    cnt, f[maxn];
inline void add(int x, int y) {
  e[++num].v = y;
  e[num].nxt = head[x];
  head[x] = num;
}
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
inline int merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return 1;
  fa[x] = y;
  return 0;
}
void dfs(int x) {
  for (signed int i = head[x]; i; i = e[i].nxt) {
    if (dep[e[i].v]) continue;
    dep[e[i].v] = dep[x] + 1;
    dfs(e[i].v);
    Fa[e[i].v] = x;
  }
}
void dfs2(int x) {
  for (signed int i = head[x]; i; i = e[i].nxt) {
    if (dep[e[i].v] < dep[x]) continue;
    dfs2(e[i].v);
    pre[x] ^= pre[e[i].v];
  }
}
inline int LCA(int x, int y) {
  if (dep[x] < dep[y]) std::swap(x, y);
  while (dep[x] != dep[y]) x = Fa[x];
  if (x == y) return x;
  while (Fa[x] != Fa[y]) x = Fa[x], y = Fa[y];
  return Fa[x];
}
void dp(int x) {
  for (signed int i = head[x]; i; i = e[i].nxt)
    if (e[i].v != Fa[x]) {
      dp(e[i].v);
      f[x] += f[e[i].v];
    }
  cnt += f[x] / 2;
  f[x] %= 2;
  if (f[x] == 0 && pre[x])
    f[x] = 1;
  else if (f[x] && pre[x] == 0)
    cnt++, f[x] = 0;
}
int main() {
  n = read(), m = read();
  for (signed int i = 1; i <= m; i++) ee[i].x = read(), ee[i].y = read();
  srand(time(0));
  std::random_shuffle(ee + 1, ee + m + 1);
  for (signed int i = 1; i <= n; i++) fa[i] = i;
  for (signed int i = 1; i <= m; i++) {
    if (merge(ee[i].x, ee[i].y)) continue;
    add(ee[i].x, ee[i].y);
    add(ee[i].y, ee[i].x);
  }
  dep[1] = 1;
  dfs(1);
  int Q = read();
  for (signed int i = 1; i <= Q; ++i) {
    ee[i].x = read(), ee[i].y = read();
    pre[ee[i].x] ^= 1, pre[ee[i].y] ^= 1;
  }
  dfs2(1);
  int fg = 0;
  for (signed int i = 1; i <= n; i++) fg |= pre[i];
  if (fg == 0) {
    puts("YES");
    for (signed int i = 1; i <= Q; ++i) {
      int l = LCA(ee[i].x, ee[i].y);
      int le = dep[ee[i].x] - 1 + dep[ee[i].y] - 1 - 2 * (dep[l] - 1) + 1;
      int nw = 0, x = ee[i].x, y = ee[i].y;
      while (x != l) ans[++nw] = x, x = Fa[x];
      ans[++nw] = l;
      int u = le;
      while (y != l) ans[u--] = y, y = Fa[y];
      printf("%d\n", le);
      for (signed int j = 1; j <= le; ++j) printf("%d ", ans[j]);
      puts("");
    }
    return 0;
  }
  puts("NO");
  dp(1);
  printf("%d\n", cnt);
}
