#include <bits/stdc++.h>
using namespace std;
int n, m;
int val[1000010], llim[1000010], rlim[1000010], f[1000010], maxval[1000010],
    dfn[1000010], in[1000010], nxt[1000010];
struct Edge {
  int u, v, c, w;
  bool operator<(const Edge& res) const { return c > res.c; }
} e[1000010];
struct Tour {
  int id, u, v;
  bool operator<(const Tour& res) const { return v > res.v; }
} q[1000010];
struct Inf {
  int e, w;
  bool operator<(const Inf& res) const {
    return res.e > e || (res.e == e && res.w > w);
  }
} cover[1000010], maxx[1000010], ans[1000010];
void pushdown(int now) {
  if (cover[now].e) {
    cover[now << 1] = maxx[now << 1] = cover[now << 1 | 1] =
        maxx[now << 1 | 1] = maxx[now] = cover[now];
    cover[now].e = cover[now].w = 0;
  } else {
    maxx[now << 1] = max(maxx[now << 1], maxx[now]);
    maxx[now << 1 | 1] = max(maxx[now << 1 | 1], maxx[now]);
  }
}
void change(int now, int l, int r, int p, int q, Inf x) {
  if (p <= l && q >= r) {
    cover[now] = maxx[now] = x;
    return;
  }
  pushdown(now);
  int mid = (l + r) >> 1;
  if (p <= mid) change(now << 1, l, mid, p, q, x);
  if (q > mid) change(now << 1 | 1, mid + 1, r, p, q, x);
}
void modify(int now, int l, int r, int p, int q, Inf x) {
  if (p <= l && q >= r) {
    maxx[now] = max(maxx[now], x);
    return;
  }
  pushdown(now);
  int mid = (l + r) >> 1;
  if (p <= mid) modify(now << 1, l, mid, p, q, x);
  if (q > mid) modify(now << 1 | 1, mid + 1, r, p, q, x);
}
Inf query(int now, int l, int r, int pos) {
  if (l == r) return maxx[now];
  pushdown(now);
  int mid = (l + r) >> 1;
  if (pos <= mid)
    return query(now << 1, l, mid, pos);
  else
    return query(now << 1 | 1, mid + 1, r, pos);
}
void prt(int now, int l, int r) {
  cout << "l=" << l << " r=" << r << " cov=" << cover[now].e << ","
       << cover[now].w << " max=" << maxx[now].e << "," << maxx[now].w << endl;
  pushdown(now);
  if (l == r) return;
  int mid = (l + r) >> 1;
  prt(now << 1, l, mid);
  prt(now << 1 | 1, mid + 1, r);
}
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
void getdfn() {
  sort(e + 1, e + n);
  for (register int i = 1; i <= n; i++) f[i] = in[i] = nxt[i] = i;
  for (register int i = 1; i < n; i++) {
    int u = find(e[i].u), v = find(e[i].v);
    nxt[u] = in[v];
    f[u] = v;
    in[v] = in[u];
  }
  for (register int i = in [find(1)], j = 1; !dfn[i]; i = nxt[i], j++) {
    dfn[i] = j;
    change(1, 1, n, j, j, (Inf){val[i], 0});
  }
}
void solve() {
  sort(q + 1, q + m + 1);
  for (register int i = 1; i <= n; i++) {
    f[i] = i;
    maxval[i] = val[i];
    llim[i] = rlim[i] = dfn[i];
  }
  for (register int i = 1, j = 1; i < n || j <= m;) {
    for (; j <= m && q[j].v > e[i].c; j++) {
      ans[q[j].id] = query(1, 1, n, dfn[q[j].u]);
    }
    int nowc = e[i].c;
    for (; i < n && e[i].c == nowc; i++) {
      int u = find(e[i].u), v = find(e[i].v);
      Inf uans = query(1, 1, n, dfn[e[i].u]),
          vans = query(1, 1, n, dfn[e[i].v]);
      if (maxval[u] < maxval[v])
        change(1, 1, n, llim[u], rlim[u], max((Inf){maxval[v], e[i].w}, vans));
      else if (maxval[u] > maxval[v])
        change(1, 1, n, llim[v], rlim[v], max((Inf){maxval[u], e[i].w}, uans));
      else {
        modify(1, 1, n, llim[u], rlim[u], max((Inf){maxval[v], e[i].w}, vans));
        modify(1, 1, n, llim[v], rlim[v], max((Inf){maxval[u], e[i].w}, uans));
      }
      f[u] = v;
      llim[v] = min(llim[u], llim[v]);
      rlim[v] = max(rlim[u], rlim[v]);
      maxval[v] = max(maxval[u], maxval[v]);
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (register int i = 1; i <= n; i++) scanf("%d", &val[i]);
  for (register int i = 1; i < n; i++)
    scanf("%d%d%d%d", &e[i].u, &e[i].v, &e[i].c, &e[i].w);
  for (register int i = 1; i <= m; i++) {
    scanf("%d%d", &q[i].v, &q[i].u);
    q[i].id = i;
  }
  getdfn();
  solve();
  for (register int i = 1; i <= m; i++) printf("%d %d\n", ans[i].e, ans[i].w);
  return 0;
}
