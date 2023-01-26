#include <bits/stdc++.h>
using namespace std;
long long val[1200005], tag[1200005], a[300005];
long long dfn[300005], dfc = 0, rid[300005], fa[300005], top[300005],
                       siz[300005], son[300005], dep[300005];
long long sum[300005];
long long n, m, eu[600005], ev[600005], ew[600005], flg[600005];
long long ec = 0, to[600005], nxt[600005], hed[300005], w[600005];
void add_edge(long long f, long long t, long long cst) {
  ++ec;
  to[ec] = t;
  nxt[ec] = hed[f];
  w[ec] = cst;
  hed[f] = ec;
}
void pushup(long long x) { val[x] = val[(x << 1)] + val[((x << 1) | 1)]; }
void pushdown(long long x, long long l, long long r) {
  if (!tag[x]) return;
  long long mid = (l + r) >> 1;
  tag[(x << 1)] += tag[x];
  val[(x << 1)] += tag[x] * (mid - l + 1);
  tag[((x << 1) | 1)] += tag[x];
  val[((x << 1) | 1)] += tag[x] * (r - mid);
  tag[x] = 0;
}
void modify(long long x, long long l, long long r, long long L, long long R,
            long long v) {
  if (L > R) return;
  if (L <= l && r <= R) {
    tag[x] += v;
    val[x] += v * (r - l + 1);
    return;
  }
  long long mid = (l + r) >> 1;
  pushdown(x, l, r);
  if (L <= mid) modify((x << 1), l, mid, L, R, v);
  if (R > mid) modify(((x << 1) | 1), mid + 1, r, L, R, v);
  pushup(x);
}
long long query(long long x, long long l, long long r, long long L,
                long long R) {
  if (L > R) return 0;
  if (L <= l && r <= R) return val[x];
  long long mid = (l + r) >> 1, ret = 0;
  pushdown(x, l, r);
  if (L <= mid) ret += query((x << 1), l, mid, L, R);
  if (R > mid) ret += query(((x << 1) | 1), mid + 1, r, L, R);
  pushup(x);
  return ret;
}
void dfs1(long long u, long long f) {
  siz[u] = 1;
  dep[u] = dep[f] + 1;
  fa[u] = f;
  for (long long i = hed[u]; i; i = nxt[i]) {
    long long v = to[i];
    if (v == f) continue;
    sum[v] = sum[u] ^ w[i];
    dfs1(v, u);
    siz[u] += siz[v];
    if (siz[v] > siz[son[u]]) son[u] = v;
  }
}
void dfs2(long long u, long long t) {
  top[u] = t;
  dfn[u] = ++dfc;
  rid[dfc] = u;
  if (son[u]) dfs2(son[u], t);
  for (long long i = hed[u]; i; i = nxt[i]) {
    long long v = to[i];
    if (v == fa[u] || v == son[u]) continue;
    dfs2(v, v);
  }
}
void modify_chain(long long x, long long y, long long v) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    modify(1, 1, n, dfn[top[x]], dfn[x], v);
    x = fa[top[x]];
  }
  if (dep[x] < dep[y]) swap(x, y);
  modify(1, 1, n, dfn[y] + 1, dfn[x], v);
}
void modify_son(long long x, long long v) {
  modify(1, 1, n, dfn[x], dfn[x] + siz[x] - 1, v);
}
long long query_chain(long long x, long long y) {
  long long ret = 0;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    ret += query(1, 1, n, dfn[top[x]], dfn[x]);
    x = fa[top[x]];
  }
  if (dep[x] < dep[y]) swap(x, y);
  ret += query(1, 1, n, dfn[y] + 1, dfn[x]);
  return ret;
}
long long ff[300005];
long long getf(long long x) {
  if (x == ff[x]) return x;
  return ff[x] = getf(ff[x]);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) ff[i] = i;
  for (long long i = 1; i <= m; i++) {
    cin >> eu[i] >> ev[i] >> ew[i];
    if (getf(eu[i]) != getf(ev[i])) {
      ff[getf(eu[i])] = getf(ev[i]);
      add_edge(eu[i], ev[i], ew[i]);
      add_edge(ev[i], eu[i], ew[i]);
      flg[i] = 1;
    }
  }
  for (long long i = 1; i <= n; i++) {
    if (!dfn[i]) {
      sum[i] = 0;
      dfs1(i, 0);
      dfs2(i, 1);
    }
  }
  for (long long i = 1; i <= m; i++) {
    if (flg[i]) {
      cout << "YES\n";
      continue;
    }
    if (query_chain(eu[i], ev[i]) > 0 ||
        (sum[eu[i]] ^ sum[ev[i]] ^ ew[i]) != 1) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    modify_chain(eu[i], ev[i], 1);
  }
  return 0;
}
