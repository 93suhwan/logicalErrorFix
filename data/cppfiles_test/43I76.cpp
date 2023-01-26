#include <bits/stdc++.h>
using namespace std;
struct edge {
  int to, nxt;
  bool wei;
} e[600010];
struct segt {
  int l, r, sum, tg;
} tree[1200010];
int cnt, h[500010], U[500010], V[500010], fa[300010], dep[300010], siz[300010],
    hson[300010], dfn[300010], tp[300010];
bool d[300010], w[500010], istree[500010];
inline int read() {
  char c = getchar();
  int x = 0;
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar();
  }
  return x;
}
inline void adde(int x, int y, bool z) {
  e[++cnt].to = y;
  e[cnt].wei = z;
  e[cnt].nxt = h[x];
  h[x] = cnt;
}
int getfa(int x) {
  if (x != fa[x]) return fa[x] = getfa(fa[x]);
  return x;
}
void dfs1(int x, int f) {
  fa[x] = f;
  dep[x] = dep[f] + 1;
  siz[x] = 1;
  for (int i = h[x]; i; i = e[i].nxt)
    if (e[i].to != f) {
      d[e[i].to] = e[i].wei ^ d[x];
      dfs1(e[i].to, x);
      siz[x] += siz[e[i].to];
      if (siz[e[i].to] > siz[hson[x]]) hson[x] = e[i].to;
    }
}
void dfs2(int x, int t) {
  dfn[x] = ++cnt;
  tp[x] = t;
  if (hson[x]) dfs2(hson[x], t);
  for (int i = h[x]; i; i = e[i].nxt)
    if (e[i].to != fa[x] && e[i].to != hson[x]) dfs2(e[i].to, e[i].to);
}
inline void push_down(int i) {
  if (tree[i].tg) {
    tree[i << 1].sum += tree[i].tg;
    tree[i << 1].tg += tree[i].tg;
    tree[i << 1 | 1].sum += tree[i].tg;
    tree[i << 1 | 1].tg += tree[i].tg;
    tree[i].tg = 0;
  }
}
void build(int le, int ri, int i) {
  tree[i].l = le;
  tree[i].r = ri;
  tree[i].sum = tree[i].tg = 0;
  if (le == ri) return;
  int mid = (le + ri) >> 1;
  build(le, mid, i << 1);
  build(mid + 1, ri, i << 1 | 1);
}
void change(int le, int ri, int i) {
  if (le <= tree[i].l && tree[i].r <= ri) {
    tree[i].sum++;
    tree[i].tg++;
    return;
  }
  push_down(i);
  if (le <= tree[i << 1].r) change(le, ri, i << 1);
  if (ri > tree[i << 1].r) change(le, ri, i << 1 | 1);
  tree[i].sum = tree[i << 1].sum + tree[i << 1 | 1].sum;
}
int ask(int le, int ri, int i) {
  if (le <= tree[i].l && tree[i].r <= ri) return tree[i].sum;
  push_down(i);
  int val = 0;
  if (le <= tree[i << 1].r) val = ask(le, ri, i << 1);
  if (ri > tree[i << 1].r) val += ask(le, ri, i << 1 | 1);
  return val;
}
inline void changepath(int u, int v) {
  while (tp[u] != tp[v])
    if (dep[tp[u]] > dep[tp[v]]) {
      change(dfn[tp[u]], dfn[u], 1);
      u = fa[tp[u]];
    } else {
      change(dfn[tp[v]], dfn[v], 1);
      v = fa[tp[v]];
    }
  if (dep[u] < dep[v])
    change(dfn[u], dfn[v], 1);
  else
    change(dfn[v], dfn[u], 1);
}
inline int askpath(int u, int v) {
  int val = 0;
  while (tp[u] != tp[v])
    if (dep[tp[u]] > dep[tp[v]]) {
      val += ask(dfn[tp[u]], dfn[u], 1);
      u = fa[tp[u]];
    } else {
      val += ask(dfn[tp[v]], dfn[v], 1);
      v = fa[tp[v]];
    }
  if (dep[u] < dep[v]) return val + ask(dfn[u], dfn[v], 1);
  return val + ask(dfn[v], dfn[u], 1);
}
int main() {
  int n = read(), m = read(), i;
  for (i = 1; i <= n; i++) fa[i] = i;
  for (i = 1; i <= m; i++) {
    U[i] = read();
    V[i] = read();
    w[i] = read();
    int fx = getfa(U[i]), fy = getfa(V[i]);
    if (fx != fy) {
      fa[fx] = fy;
      istree[i] = true;
      adde(U[i], V[i], w[i]);
      adde(V[i], U[i], w[i]);
    }
  }
  cnt = 0;
  for (i = 1; i <= n; i++)
    if (!dep[i]) {
      dfs1(i, 0);
      dfs2(i, i);
    }
  build(1, n, 1);
  for (i = 1; i <= m; i++)
    if (istree[i]) {
      puts("YES");
      changepath(U[i], V[i]);
    } else if ((d[U[i]] ^ d[V[i]]) && askpath(U[i], V[i]) <= 1) {
      puts("YES");
      changepath(U[i], V[i]);
    } else
      puts("NO");
  return 0;
}
