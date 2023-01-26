#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long N = 1005, M = 70;
long long n, m, w[N], val[N], S, T, a[N], b[N];
long long id[N], tmp[N], ans[N];
list<long long> G[N];
list<long long>::iterator it, itt;
namespace Flow {
const long long N = ::N + 5, M = ::N * ::M * 2;
long long fir[N], to[M], nxt[M], cnt = 1, d[N], cur[N];
long long fl[M];
inline void addedge(long long u, long long v, long long f) {
  to[++cnt] = v;
  fl[cnt] = f;
  nxt[cnt] = fir[u];
  fir[u] = cnt;
}
inline void addflow(long long u, long long v, long long f) {
  addedge(u, v, f);
  addedge(v, u, 0);
}
inline void clear(long long l, long long r) {
  cnt = 1;
  for (long long i = (l); i <= (r); ++i) fir[id[i]] = 0;
  fir[S] = fir[T] = 0;
}
inline long long bfs(long long l, long long r) {
  queue<long long> q;
  d[S] = 0;
  q.push(S);
  for (long long i = (l); i <= (r); ++i) d[id[i]] = -1, cur[id[i]] = fir[id[i]];
  d[T] = -1;
  cur[S] = fir[S], cur[T] = fir[T];
  while (!q.empty()) {
    long long u = q.front();
    q.pop();
    for (long long i = fir[u], v; v = to[i], i; i = nxt[i])
      if (fl[i] && d[v] == -1) q.push(v), d[v] = d[u] + 1;
  }
  return d[T] != -1;
}
long long Dinic(long long u, long long flow) {
  if (u == T) return flow;
  long long rest = flow;
  for (long long i = cur[u], v; v = to[i], (i && rest); i = nxt[i]) {
    cur[u] = i;
    if (fl[i] && d[v] == d[u] + 1) {
      long long res = Dinic(v, min(rest, fl[i]));
      fl[i] -= res, fl[i ^ 1] += res, rest -= res;
    }
  }
  return flow - rest;
}
bool vis[N];
inline long long solve(long long l, long long r) {
  for (long long i = (l); i <= (r); ++i) vis[id[i]] = 1;
  for (long long i = (l); i <= (r); ++i)
    for (it = G[id[i]].begin(); it != G[id[i]].end();)
      if (vis[*it])
        addflow(id[i], *it, INF), ++it;
      else
        itt = it, ++it, G[id[i]].erase(itt);
  for (long long i = (l); i <= (r); ++i)
    if (val[id[i]] >= 0)
      addflow(S, id[i], val[id[i]]);
    else
      addflow(id[i], T, -val[id[i]]);
  while (bfs(l, r))
    while (Dinic(S, INF))
      ;
  ;
  clear(l, r);
  long long pl = l - 1, pr = r + 1;
  for (long long i = (l); i <= (r); ++i)
    if (d[id[i]] == -1)
      tmp[++pl] = id[i];
    else
      tmp[--pr] = id[i];
  for (long long i = (l); i <= (r); ++i) vis[id[i] = tmp[i]] = 0;
  return pl;
}
}  // namespace Flow
void solve(long long l, long long r, long long L, long long R) {
  if (l > r) return;
  long long mid = L + R >> 1;
  for (long long i = (l); i <= (r); ++i)
    val[id[i]] = -(abs(w[id[i]] - (mid + 1)) - abs(w[id[i]] - mid));
  long long md = Flow::solve(l, r);
  if (L == R - 1) {
    for (long long i = (l); i <= (md); ++i) ans[id[i]] = L;
    for (long long i = (md + 1); i <= (r); ++i) ans[id[i]] = R;
    return;
  }
  solve(l, md, L, mid), solve(md + 1, r, mid, R);
}
inline void build();
signed main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  S = n + 1, T = S + 1;
  for (long long i = (1); i <= (n); ++i) cin >> w[i];
  build();
  for (long long i = (1); i <= (n); ++i) id[i] = i;
  solve(1, n, 0, (long long)(1e9));
  for (long long i = (1); i <= (n); ++i) cout << ans[i] << ' ';
  return 0;
}
bool mk[N];
inline void build() {
  for (long long i = 1, u, v; i <= m; ++i) cin >> u >> v, G[u].push_back(v);
}
