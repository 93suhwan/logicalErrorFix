#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char s;
  long long k = 0, base = 1;
  while ((s = getchar()) != '-' && s != EOF && !isdigit(s))
    ;
  if (s == EOF) exit(0);
  if (s == '-') base = -1, s = getchar();
  while (isdigit(s)) {
    k = k * 10 + (s ^ 48);
    s = getchar();
  }
  return k * base;
}
void write(long long x) {
  if (x < 0) {
    putchar('-');
    write(-x);
  } else {
    if (x / 10) write(x / 10);
    putchar(x % 10 + '0');
  }
}
const long long maxn = 1e5 + 100;
long long l[maxn << 2], r[maxn << 2];
long long tree[maxn << 2], lazy[maxn << 2];
long long n, m, root, x, y, z, bj;
long long D[maxn];
long long fa[maxn], deep[maxn], sz[maxn], hson[maxn];
long long to[maxn << 1], ne[maxn << 1], po[maxn << 1], id1;
long long top[maxn], id[maxn], rel[maxn], tot;
inline void add(long long x, long long y) {
  ++id1;
  to[id1] = y;
  ne[id1] = po[x];
  po[x] = id1;
  ++id1;
  to[id1] = x;
  ne[id1] = po[y];
  po[y] = id1;
}
void dfs1(long long x) {
  sz[x] = 1;
  deep[x] = deep[fa[x]] + 1;
  hson[x] = 0;
  for (long long i = po[x]; i; i = ne[i]) {
    if (to[i] != fa[x]) {
      fa[to[i]] = x;
      dfs1(to[i]);
      sz[x] += sz[to[i]];
      if (sz[to[i]] > sz[hson[x]]) hson[x] = to[i];
    }
  }
  return;
}
void dfs2(long long x, long long last) {
  top[x] = last;
  id[x] = ++tot;
  rel[tot] = x;
  if (hson[x] == 0) return;
  dfs2(hson[x], last);
  for (long long i = po[x]; i; i = ne[i]) {
    if (to[i] != fa[x] && to[i] != hson[x]) dfs2(to[i], to[i]);
  }
}
void bt(long long x, long long y, long long d) {
  l[d] = x;
  r[d] = y;
  if (x == y) {
    tree[d] = D[rel[x]];
    return;
  }
  long long mid = (x + y) >> 1;
  bt(x, mid, d << 1);
  bt(mid + 1, y, d << 1 | 1);
  tree[d] = tree[d << 1] + tree[d << 1 | 1];
  return;
}
void push(long long d) {
  if (lazy[d] != 0) {
    lazy[d << 1] += lazy[d];
    lazy[d << 1 | 1] += lazy[d];
    tree[d << 1] += (r[d << 1] - l[d << 1] + 1) * lazy[d];
    tree[d << 1 | 1] += (r[d << 1 | 1] - l[d << 1 | 1] + 1) * lazy[d];
    tree[d] = tree[d << 1] + tree[d << 1 | 1];
    lazy[d] = 0;
  }
  return;
}
void xg(long long x, long long y, long long d, long long z) {
  if (x <= l[d] && r[d] <= y) {
    tree[d] += z * (r[d] - l[d] + 1);
    lazy[d] += z;
    return;
  }
  push(d);
  long long mid = (l[d] + r[d]) >> 1;
  if (y > mid) xg(max(mid + 1, x), y, d << 1 | 1, z);
  if (x <= mid) xg(x, min(y, mid), d << 1, z);
  tree[d] = tree[d << 1] + tree[d << 1 | 1];
  return;
}
long long cx(long long x, long long y, long long d) {
  if (x <= l[d] && r[d] <= y) {
    return tree[d];
  }
  push(d);
  long long mid = (l[d] + r[d]) >> 1;
  long long s = 0;
  if (y > mid) s += cx(max(mid + 1, x), y, d << 1 | 1);
  if (x <= mid) s += cx(x, min(y, mid), d << 1);
  return s;
}
void add1() {
  long long X = read();
  long long Y = X;
  long long Z = abs(read());
  Z = Z - D[X];
  D[X] += Z;
  long long tx = top[X], ty = top[Y];
  while (tx != ty) {
    if (deep[tx] < deep[ty]) swap(tx, ty), swap(X, Y);
    xg(id[tx], id[X], 1, Z);
    X = fa[tx];
    tx = top[X];
  }
  if (deep[X] < deep[Y]) swap(X, Y);
  xg(id[Y], id[X], 1, Z);
}
void ans1() {
  long long X = read(), Y = read();
  long long s = 0;
  long long XX = X, YY = Y;
  long long tx = top[X], ty = top[Y];
  while (tx != ty) {
    if (deep[tx] < deep[ty]) swap(tx, ty), swap(X, Y);
    s += cx(id[tx], id[X], 1);
    X = fa[tx];
    tx = top[X];
  }
  if (deep[X] < deep[Y]) swap(X, Y);
  s += cx(id[Y], id[X], 1);
  s = s * 2 - D[XX] - D[YY];
  write(s);
  putchar('\n');
}
signed main() {
  n = read();
  m = read();
  root = 1;
  for (long long i = 1; i <= n; i++) D[i] = abs(read());
  for (long long i = 1; i < n; i++) add(read(), read());
  fa[root] = 0;
  dfs1(root);
  dfs2(root, root);
  bt(1, n, 1);
  while (m--) {
    bj = read();
    if (bj == 1)
      add1();
    else if (bj == 2)
      ans1();
  }
  return 0;
}
