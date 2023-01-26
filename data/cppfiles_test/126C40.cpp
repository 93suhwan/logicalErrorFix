#include <bits/stdc++.h>
namespace MF {
long long n, s, t;
long long hd[10005], _hd;
struct edge {
  long long v, f, nxt;
} e[10005];
inline void addedge(long long u, long long v, long long f) {
  e[++_hd] = (edge){v, f, hd[u]};
  hd[u] = _hd;
  e[++_hd] = (edge){u, 0, hd[v]};
  hd[v] = _hd;
}
inline void init(long long n_, long long s_, long long t_) {
  for (long long i = 1; i <= n; i++) hd[i] = 0;
  _hd = 1;
  n = n_, s = s_, t = t_;
}
std::queue<long long> q;
long long cur[10005], dis[10005];
inline bool bfs() {
  for (long long i = 1; i <= n; i++) cur[i] = hd[i];
  for (long long i = 1; i <= n; i++) dis[i] = 0x3f3f3f3f3f3f3f3f;
  dis[s] = 0;
  q.push(s);
  while (q.size()) {
    long long u = q.front();
    q.pop();
    for (long long i = hd[u]; i; i = e[i].nxt) {
      long long v = e[i].v, f = e[i].f;
      if (f && dis[v] > dis[u] + 1) {
        dis[v] = dis[u] + 1;
        q.push(v);
      }
    }
  }
  return dis[t] < 0x3f3f3f3f3f3f3f3f;
}
inline long long dfs(long long u, long long lmt) {
  if (u == t || !lmt) return lmt;
  long long res = 0;
  for (long long i = cur[u]; i; i = e[i].nxt) {
    cur[u] = i;
    long long v = e[i].v, f = e[i].f;
    if (dis[v] != dis[u] + 1) continue;
    f = dfs(v, std::min(lmt, f));
    e[i].f -= f;
    e[i ^ 1].f += f;
    lmt -= f;
    res += f;
    if (!lmt) break;
  }
  return res;
}
inline void sol() {
  while (bfs()) dfs(s, 0x3f3f3f3f3f3f3f3f);
}
}  // namespace MF
long long n, m, y[10005];
std::vector<long long> e[10005];
inline long long cal(long long u, long long k) {
  return k > y[u] ? k - y[u] : y[u] - k;
}
long long tot, Y[10005], f[10005], p[10005], id[10005], q[10005];
inline void sol(long long L, long long R, long long l, long long r) {
  if (l > r) return;
  if (L == R) {
    for (long long i = l; i <= r; i++) f[p[i]] = Y[L];
    return;
  }
  long long mid = (L + R) >> 1;
  MF::init(r - l + 3, r - l + 2, r - l + 3);
  for (long long i = l; i <= r; i++) id[p[i]] = i - l + 1;
  for (long long i = l; i <= r; i++) {
    long long u = p[i], w = cal(u, Y[mid]) - cal(u, Y[mid + 1]);
    if (w > 0)
      MF::addedge(MF::s, id[u], w);
    else
      MF::addedge(id[u], MF::t, -w);
    for (auto v : e[u])
      if (id[v]) MF::addedge(id[u], id[v], 0x3f3f3f3f3f3f3f3f);
  }
  MF::sol();
  long long pm = l - 1;
  for (long long i = l; i <= r; i++)
    if (MF::dis[id[p[i]]] == 0x3f3f3f3f3f3f3f3f) q[++pm] = p[i];
  long long tmp = pm;
  for (long long i = l; i <= r; i++)
    if (MF::dis[id[p[i]]] < 0x3f3f3f3f3f3f3f3f) q[++tmp] = p[i];
  for (long long i = l; i <= r; i++) p[i] = q[i];
  for (long long i = l; i <= r; i++) id[p[i]] = 0;
  sol(L, mid, l, pm);
  sol(mid + 1, R, pm + 1, r);
}
long long ans;
signed main() {
  scanf("%lld%lld", &n, &m);
  for (long long i = 1; i <= n; i++) scanf("%lld", &y[i]), Y[++tot] = y[i];
  for (long long i = 1; i <= m; i++) {
    long long u, v;
    scanf("%lld%lld", &u, &v);
    e[u].push_back(v);
  }
  std::sort(Y + 1, Y + tot + 1);
  tot = std::unique(Y + 1, Y + tot + 1) - Y - 1;
  for (long long i = 1; i <= n; i++) p[i] = i;
  sol(1, tot, 1, n);
  for (long long i = 1; i <= n; i++) printf("%lld ", f[i]);
  puts("");
}
