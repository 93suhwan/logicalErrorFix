#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int sz[MAXN], dep[MAXN], top[MAXN], son[MAXN], rk[MAXN], dfn[MAXN], dfs_clock,
    f[MAXN], n, q;
long long c[MAXN], sum[MAXN << 2];
void build(int rt, int l, int r) {
  if (l == r) {
    sum[rt] = abs(c[rk[l]]);
    return;
  }
  int mid = (l + r) >> 1;
  build(rt << 1, l, mid);
  build(rt << 1 | 1, mid + 1, r);
  sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void upd(int rt, int l, int r, int pos, long long x) {
  if (l == r) {
    c[rk[l]] = x;
    sum[rt] = abs(x);
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid) {
    upd(rt << 1, l, mid, pos, x);
  } else {
    upd(rt << 1 | 1, mid + 1, r, pos, x);
  }
  sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
long long qry(int rt, int l, int r, int L, int R) {
  if (L <= l && R >= r) {
    return sum[rt];
  }
  int mid = (l + r) >> 1;
  if (R <= mid) {
    return qry(rt << 1, l, mid, L, R);
  } else if (L > mid) {
    return qry(rt << 1 | 1, mid + 1, r, L, R);
  } else {
    return qry(rt << 1, l, mid, L, mid) +
           qry(rt << 1 | 1, mid + 1, r, mid + 1, R);
  }
}
void dfs1(int u, int fa) {
  sz[u] = 1;
  son[u] = -1;
  for (int v : adj[u])
    if (fa != v) {
      dep[v] = dep[u] + 1;
      f[v] = u;
      dfs1(v, u);
      sz[u] += sz[v];
      if (son[u] == -1 || sz[v] > sz[son[u]]) son[u] = v;
    }
}
void dfs2(int u, int fa, int t) {
  top[u] = t;
  dfn[u] = ++dfs_clock;
  rk[dfs_clock] = u;
  if (~son[u])
    dfs2(son[u], u, t);
  else
    return;
  for (int v : adj[u])
    if (son[u] != v && fa != v) {
      dfs2(v, u, v);
    }
}
void change(int u, long long x) { upd(1, 1, n, dfn[u], x); }
long long query(int u, int v) {
  long long res = 0;
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) {
      swap(u, v);
    }
    res += qry(1, 1, n, dfn[top[u]], dfn[u]);
    u = f[top[u]];
  }
  if (dfn[u] > dfn[v]) swap(u, v);
  res += qry(1, 1, n, dfn[u], dfn[v]);
  return res * 2ll - abs(c[u]) - abs(c[v]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> c[i];
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dep[1] = 1;
  dfs1(1, 0);
  dfs2(1, 0, 1);
  build(1, 1, n);
  for (int i = 1; i <= q; i++) {
    int op, u, x;
    cin >> op >> u >> x;
    if (op == 1) {
      change(u, 1ll * x);
    } else {
      cout << query(u, x) << '\n';
    }
  }
  return 0;
}
