#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, q, tot;
int a[maxn], id[maxn], getid[maxn];
int sz[maxn], fa[maxn], son[maxn], top[maxn], dep[maxn];
long long sum[maxn << 2];
vector<int> v[maxn];
void dfs1(int u, int f, int d) {
  dep[u] = d;
  fa[u] = f;
  sz[u] = 1;
  for (int i = 0; i < v[u].size(); i++) {
    if (v[u][i] == fa[u]) continue;
    dfs1(v[u][i], u, d + 1);
    sz[u] += sz[v[u][i]];
    if (sz[son[u]] < sz[v[u][i]]) son[u] = v[u][i];
  }
}
void dfs2(int u, int t) {
  top[u] = t;
  id[u] = ++tot;
  getid[tot] = u;
  if (son[u]) dfs2(son[u], t);
  for (int i = 0; i < v[u].size(); i++) {
    if (v[u][i] == fa[u] || v[u][i] == son[u]) continue;
    dfs2(v[u][i], v[u][i]);
  }
}
void pushup(int rt) { sum[rt] = sum[rt << 1] + sum[rt << 1 | 1]; }
void build(int l, int r, int rt) {
  if (l == r) {
    sum[rt] = a[getid[l]];
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, rt << 1), build(mid + 1, r, rt << 1 | 1);
  pushup(rt);
}
void mod(int l, int r, int rt, int pos, int v) {
  if (l == r) {
    sum[rt] = v;
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid) mod(l, mid, rt << 1, pos, v);
  if (mid < pos) mod(mid + 1, r, rt << 1 | 1, pos, v);
  pushup(rt);
}
long long que(int l, int r, int rt, int ql, int qr) {
  if (ql <= l && r <= qr) return sum[rt];
  int mid = (l + r) >> 1;
  long long ret = 0;
  if (ql <= mid) ret += que(l, mid, rt << 1, ql, qr);
  if (mid < qr) ret += que(mid + 1, r, rt << 1 | 1, ql, qr);
  return ret;
}
long long chainque(int x, int y) {
  long long ret = 0;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    ret += que(1, n, 1, id[top[x]], id[x]);
    x = fa[top[x]];
  }
  if (dep[x] < dep[y]) swap(x, y);
  return ret + que(1, n, 1, id[y], id[x]);
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i] = abs(a[i]);
  for (int i = 1, x, y; i < n; i++) {
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs1(1, 0, 0);
  dfs2(1, 1);
  build(1, n, 1);
  for (int i = 1, x, y, z; i <= q; i++) {
    scanf("%d%d%d", &x, &y, &z);
    if (x == 1) {
      z = abs(z);
      mod(1, n, 1, y, z);
      a[y] = z;
    } else if (x == 2) {
      printf("%lld\n", 2 * chainque(y, z) - a[y] - a[z]);
    }
  }
}
