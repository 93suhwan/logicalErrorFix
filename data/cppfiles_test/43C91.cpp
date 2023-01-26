#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &r) {
  r = 0;
  bool w = true;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar()) w ^= !(ch ^ 45);
  for (; isdigit(ch); ch = getchar()) r = (r << 1) + (r << 3) + (ch ^ 48);
  r = w ? r : -r;
}
struct node {
  int to, next, weight;
} edge[(500000 + 5) << 1];
int head[300000 + 5], edge_num;
void add(int u, int v, int w) {
  ++edge_num;
  edge[edge_num].to = v;
  edge[edge_num].next = head[u];
  edge[edge_num].weight = w;
  head[u] = edge_num;
}
int n, m;
int fat[300000 + 5];
int find(int x) {
  if (fat[x] == x) return x;
  return fat[x] = find(fat[x]);
}
int x[500000 + 5], y[500000 + 5], z[500000 + 5], ans[500000 + 5];
void init() {
  read(n), read(m);
  for (register int i = 1; i <= n; i++) fat[i] = i;
  for (register int i = 1; i <= m; i++) {
    read(x[i]), read(y[i]), read(z[i]);
    if (find(x[i]) != find(y[i])) {
      fat[find(x[i])] = find(y[i]);
      ans[i] = true;
      add(x[i], y[i], z[i]);
      add(y[i], x[i], z[i]);
    }
  }
}
int fa[300000 + 5], size[300000 + 5], son[300000 + 5], depth[300000 + 5],
    val[300000 + 5];
void dfs1(int u) {
  size[u] = 1;
  for (register int i = head[u]; i; i = edge[i].next) {
    int v = edge[i].to;
    if (fa[u] == v) continue;
    fa[v] = u;
    val[v] = edge[i].weight;
    depth[v] = depth[u] + 1;
    dfs1(v);
    size[u] += size[v];
    if (size[son[u]] < size[v]) son[u] = v;
  }
}
int belong[300000 + 5], pos[300000 + 5], bac[300000 + 5];
void dfs2(int u, int chain) {
  belong[u] = chain;
  pos[u] = ++pos[0];
  bac[pos[0]] = u;
  if (son[u]) dfs2(son[u], chain);
  for (register int i = head[u]; i; i = edge[i].next) {
    int v = edge[i].to;
    if (fa[u] == v || son[u] == v) continue;
    dfs2(v, v);
  }
}
struct node2 {
  int l, r, val;
  bool vis, lazy;
} a[300000 << 2];
void pushup(int p) {
  a[p].val = a[(p << 1)].val ^ a[((p << 1) + 1)].val;
  a[p].vis = a[(p << 1)].vis | a[((p << 1) + 1)].vis;
}
void pushdown(int p) {
  if (a[p].lazy) {
    a[(p << 1)].vis = a[((p << 1) + 1)].vis = a[(p << 1)].lazy =
        a[((p << 1) + 1)].lazy = true;
    a[p].lazy = false;
  }
}
void build(int p, int l, int r) {
  a[p].l = l, a[p].r = r;
  if (l == r) {
    a[p].val = val[bac[l]];
    a[p].vis = false;
    return;
  }
  int mid = (l + r) >> 1;
  build((p << 1), l, mid);
  build(((p << 1) + 1), mid + 1, r);
  pushup(p);
}
void update(int p, int l, int r) {
  if (a[p].l == l && a[p].r == r) {
    a[p].vis = true;
    a[p].lazy = true;
    return;
  }
  pushdown(p);
  int mid = (a[p].l + a[p].r) >> 1;
  if (r <= mid)
    update((p << 1), l, r);
  else if (l > mid)
    update(((p << 1) + 1), l, r);
  else {
    update((p << 1), l, mid);
    update(((p << 1) + 1), mid + 1, r);
  }
  pushup(p);
}
int query(int p, int l, int r) {
  if (a[p].l == l && a[p].r == r) {
    if (a[p].vis) return -1;
    return a[p].val;
  }
  pushdown(p);
  int mid = (a[p].l + a[p].r) >> 1;
  if (r <= mid) return query((p << 1), l, r);
  if (l > mid) return query(((p << 1) + 1), l, r);
  int ls = query((p << 1), l, mid), rs = query(((p << 1) + 1), mid + 1, r);
  if (ls == -1 || rs == -1) return -1;
  return ls ^ rs;
}
void getpath(int i) {
  int u = x[i], v = y[i];
  int ret = 0;
  while (belong[u] != belong[v]) {
    if (depth[belong[u]] < depth[belong[v]]) swap(u, v);
    int g = query(1, pos[belong[u]], pos[u]);
    if (g == -1) {
      ret = -1;
      return;
    } else
      ret ^= g;
    u = fa[belong[u]];
  }
  if (depth[u] < depth[v]) swap(u, v);
  if (u != v) {
    int g = query(1, pos[v] + 1, pos[u]);
    if (g == -1)
      ret = -1;
    else
      ret ^= g;
  }
  if ((ret ^ z[i]) == 1) {
    ans[i] = 1;
    u = x[i], v = y[i];
    while (belong[u] != belong[v]) {
      if (depth[belong[u]] < depth[belong[v]]) swap(u, v);
      update(1, pos[belong[u]], pos[u]);
      u = fa[belong[u]];
    }
    if (depth[u] < depth[v]) swap(u, v);
    if (u != v) {
      update(1, pos[v] + 1, pos[u]);
    }
  }
}
void solve() {
  for (register int i = 1; i <= n; i++) {
    if (!size[i]) {
      depth[i] = 1;
      dfs1(i);
      dfs2(i, i);
    }
  }
  build(1, 1, n);
  for (register int i = 1; i <= m; i++) {
    if (!ans[i]) {
      getpath(i);
    }
  }
  for (register int i = 1; i <= m; i++) puts(ans[i] ? "YES" : "NO");
}
void write() {}
int main() {
  init();
  solve();
  write();
  return 0;
}
