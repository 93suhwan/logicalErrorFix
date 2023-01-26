#include <bits/stdc++.h>
using namespace std;
const int M = 300005;
int read() {
  int x = 0, f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9') {
    if (c == '-') f = -1;
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
int n, m, k, tot, tim, a[M], f[M], use[M], hav[M], id[M];
int d[M], pre[M], mat[M], fa[M], bz[M], bp[M];
struct edge {
  int v, next;
} e[M << 2];
void add(int u, int v) {
  e[++tot] = edge{v, f[u]}, f[u] = tot;
  e[++tot] = edge{u, f[v]}, f[v] = tot;
}
int find(int x) {
  if (x != fa[x]) fa[x] = find(fa[x]);
  return fa[x];
}
int lca(int x, int y) {
  tim++;
  x = find(x);
  y = find(y);
  while (bp[x] != tim) {
    bp[x] = tim;
    x = find(pre[mat[x]]);
    if (y) swap(x, y);
  }
  return x;
}
void make(int x, int y, int w) {
  while (find(x) != w) {
    pre[x] = y;
    y = mat[x];
    if (bz[y] == 2) bz[y] = 1, d[++d[0]] = y;
    if (find(x) == x) fa[x] = w;
    if (find(y) == y) fa[y] = w;
    x = pre[y];
  }
}
int bfs(int rt) {
  for (int i = 1; i <= n; i++) fa[i] = i, pre[i] = bz[i] = 0;
  d[d[0] = 1] = rt;
  bz[rt] = 1;
  int l = 0;
  while (l < d[0]) {
    int u = d[++l];
    for (int i = f[u]; i; i = e[i].next) {
      int v = e[i].v;
      if (find(u) == find(v) || bz[v] == 2) continue;
      if (!bz[v]) {
        bz[v] = 2;
        pre[v] = u;
        if (!mat[v]) {
          for (int x = v, y; x; x = y)
            y = mat[pre[x]], mat[x] = pre[x], mat[pre[x]] = x;
          return 1;
        }
        bz[mat[v]] = 1;
        d[++d[0]] = mat[v];
      } else {
        int w = lca(u, v);
        make(u, v, w);
        make(v, u, w);
      }
    }
  }
  return 0;
}
void rep(int l, int r) {
  for (int i = l; i <= r; i += 2) {
    while (hav[k]) k++;
    a[i] = a[i + 1] = k++;
  }
}
signed main() {
  n = read();
  k = 1;
  m = 600;
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    hav[a[i]] = 1;
    if (a[i] == a[i - 1]) use[a[i]] = 1;
  }
  for (int i = 1, j; i <= n; i = j) {
    if (a[i]) {
      j = i + 1;
      continue;
    }
    j = i;
    while (j <= n && a[j] == 0) j++;
    if ((j - i) % 2 == 0) {
      m++;
      if (i > 1 && !use[a[i - 1]]) add(m, a[i - 1]);
      m++;
      if (j <= n && !use[a[j]]) add(m, a[j]);
      add(m - 1, m);
    } else {
      m++;
      if (i > 1 && !use[a[i - 1]]) add(m, a[i - 1]);
      if (j <= n && !use[a[j]]) add(m, a[j]);
    }
    id[i] = m;
  }
  for (int i = 1; i <= n; i++)
    if (!mat[i]) bfs(i);
  for (int i = 1, j; i <= n; i = j + 1) {
    if (a[i]) continue;
    j = i;
    while (j <= n && a[j] == 0) j++;
    j--;
    int o = id[i];
    if ((j - i + 1) % 2 == 0) {
      if (mat[o - 1] == o)
        rep(i, j);
      else {
        a[i] = a[i - 1];
        a[j] = a[j + 1];
        rep(i + 1, j - 1);
      }
    } else {
      if (i > 1 && mat[o] == a[i - 1])
        a[i] = a[i - 1], rep(i + 1, j);
      else
        a[j] = a[j + 1], rep(i, j - 1);
    }
  }
  for (int i = 1; i <= n; i++) printf("%d ", a[i] ? a[i] : 1);
  puts("");
}
