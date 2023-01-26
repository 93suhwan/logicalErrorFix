#include <bits/stdc++.h>
using namespace std;
int n, m, v[400005], mx, vis[400005], a[400005], mi;
unsigned long long c[400005];
long long f[400005], ans;
vector<int> g[400005];
struct Basis {
  unsigned long long p[65], b[65];
  Basis() { memset(p, 0, sizeof p), memset(b, 0, sizeof b); }
  inline void Ins(unsigned long long v, unsigned long long id) {
    int i;
    for (i = 63; ~i; --i)
      if ((v >> i) & 1) {
        if (p[i])
          v ^= p[i], id ^= b[i];
        else {
          p[i] = v, b[i] = id;
          break;
        }
      }
  }
  inline void Build(int opt) {
    int i, j;
    unsigned long long v, fr;
    for (i = 0; i < m; ++i)
      scanf("%d", a + i), vis[a[i]] = 1, Ins(c[a[i]], 1ull << i);
    for (i = 1; i <= n; ++i)
      if (!vis[i]) {
        for (v = c[i], fr = 0, j = 63; ~j; --j)
          if ((v >> j) & 1) fr ^= b[j], v ^= p[j];
        for (j = 0; j < 64; ++j)
          if ((fr >> j) & 1) {
            (!opt) ? g[a[j]].push_back(i) : g[i].push_back(a[j]);
          }
      }
    for (i = 0; i < m; ++i) vis[a[i]] = 0;
  }
} P1, P2;
namespace WLL {
int S, T, cnt = 1, h[400005], Q[400005 << 1], dis[400005], cur[400005];
struct Edge {
  int to, next;
  long long f;
} e[400005];
inline void A(int x, int y, long long z) {
  e[++cnt] = {y, h[x], z}, h[x] = cnt, e[++cnt] = {x, h[y], 0}, h[y] = cnt;
}
inline int bfs(vector<int> q) {
  int i, x, l, r, y;
  cur[S] = h[S], cur[T] = h[T], dis[S] = 1, dis[T] = 0;
  for (int x : q) dis[x] = 0, cur[x] = h[x];
  Q[l = r = 1] = S;
  while (l <= r)
    for (i = h[x = Q[l++]]; i; i = e[i].next)
      if (e[i].f && !dis[y = e[i].to]) {
        dis[Q[++r] = y] = dis[x] + 1;
      }
  return dis[T];
}
inline long long dfs(int x, long long mxf) {
  int y;
  long long res = 0, dlt;
  if (x == T) return mxf;
  if (!mxf) return 0;
  for (int& i = cur[x]; i; i = e[i].next)
    if (e[i].f && dis[y = e[i].to] == dis[x] + 1) {
      dlt = dfs(y, min(mxf, e[i].f));
      res += dlt, e[i].f -= dlt, e[i ^ 1].f += dlt;
      if (!(mxf -= dlt)) return res;
    }
  return res;
}
inline long long Dinic(vector<int> q) {
  long long ans = 0;
  while (bfs(q)) ans += dfs(S, 0x3f3f3f3f3f3f3f3fll);
  return ans;
}
inline void Calc(vector<int> q, int mid) {
  long long V;
  cnt = 1;
  h[S] = h[T] = 0;
  for (int x : q) h[x] = 0, vis[x] = 1;
  for (int x : q) {
    for (int y : g[x])
      if (vis[y]) A(x, y, 0x3f3f3f3f3f3f3f3fll);
    V = 1ll * abs(v[x] - mid - 1) - 1ll * abs(v[x] - mid);
    V < 0 ? A(S, x, -V) : A(x, T, V);
  }
  Dinic(q);
  for (int x : q) vis[x] = 0;
}
}  // namespace WLL
using namespace WLL;
inline void Solve(vector<int> q, long long l, long long r) {
  int i;
  long long mid = (l + r) >> 1;
  vector<int> ql, qr;
  if (l == r || !q.size()) {
    for (int x : q) f[x] = l;
    return;
  }
  Calc(q, mid);
  for (int x : q)
    if (dis[x])
      qr.push_back(x);
    else
      ql.push_back(x);
  Solve(ql, l, mid), Solve(qr, mid + 1, r);
}
signed main(void) {
  int i, x, y;
  vector<int> q;
  scanf("%d%d", &n, &m), mi = 1e6, T = n + 1;
  for (i = 1; i <= n; ++i)
    scanf("%d", v + i), mx = max(mx, v[i]), mi = min(mi, v[i]), q.push_back(i);
  for (i = 1; i <= m; ++i) scanf("%d%d", &x, &y), g[x].push_back(y);
  Solve(q, mi, mx);
  long long SS = 0;
  for (i = 1; i <= n; ++i) printf("%d ", f[i]), SS += abs(f[i] - v[i]);
  return 0;
}
