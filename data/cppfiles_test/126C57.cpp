#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1005;
const long long INF = 1E14;
namespace MF {
struct Edge {
  long long from, to, cap, flow;
  Edge(long long u, long long v, long long c, long long f)
      : from(u), to(v), cap(c), flow(f) {}
};
long long n, s, t, flow;
vector<Edge> edges;
vector<long long> g[MAXN];
long long h[MAXN], cur[MAXN];
void init(long long v, long long a, long long b) {
  n = v, s = a, t = b, flow = 0;
  edges.clear();
  for (long long i = 1; i <= n; i++) g[i].clear();
}
void addEdge(long long from, long long to, long long cap) {
  edges.push_back(Edge(from, to, cap, 0));
  edges.push_back(Edge(to, from, 0, 0));
  g[from].push_back(edges.size() - 2);
  g[to].push_back(edges.size() - 1);
}
bool bfs() {
  queue<long long> q;
  for (long long i = 1; i <= n; i++) cur[i] = h[i] = 0;
  h[s] = 1, q.push(s);
  while (!q.empty()) {
    long long u = q.front();
    q.pop();
    for (long long i = 0; i < (long long)g[u].size(); i++) {
      Edge e = edges[g[u][i]];
      if (e.cap > e.flow && !h[e.to]) h[e.to] = h[u] + 1, q.push(e.to);
    }
  }
  return h[t];
}
long long dfs(long long u, long long f) {
  if (u == t) return f;
  for (long long &i = cur[u]; i < (long long)g[u].size(); i++) {
    Edge &e = edges[g[u][i]];
    if (e.cap > e.flow && h[e.to] == h[u] + 1) {
      long long d = dfs(e.to, min(f, e.cap - e.flow));
      if (d > 0) {
        e.flow += d;
        edges[g[u][i] ^ 1].flow -= d;
        return d;
      }
    }
  }
  return 0;
}
void Dinic() {
  while (bfs())
    while (long long f = dfs(s, INF)) flow += f;
}
}  // namespace MF
unsigned long long c[MAXN];
long long w[MAXN], a[66], b[66];
long long p[MAXN], q[MAXN], t1[MAXN], t2[MAXN];
long long f[MAXN];
vector<long long> G[MAXN];
void solve(long long l, long long r, long long L, long long R) {
  if (l > r) return;
  if (R - L == 1) {
    MF::init(r - l + 3, r - l + 2, r - l + 3);
    for (long long i = l; i <= r; i++) q[p[i]] = i - l + 1;
    for (long long i = l; i <= r; i++) {
      long long u = p[i], cost = (w[u] < L) ? -1 : (w[u] == L ? 0 : 1);
      if (cost > 0)
        MF::addEdge(MF::s, q[u], cost);
      else
        MF::addEdge(q[u], MF::t, -cost);
      for (long long v : G[u])
        if (q[v]) MF::addEdge(q[u], q[v], INF);
    }
    for (long long i = l; i <= r; i++) q[p[i]] = 0;
    MF::Dinic();
    for (long long i = l; i <= r; i++)
      if (!MF::h[i - l + 1])
        f[p[i]] = L;
      else
        f[p[i]] = R;
    return;
  }
  long long mid = (L + R) / 2;
  MF::init(r - l + 3, r - l + 2, r - l + 3);
  for (long long i = l; i <= r; i++) q[p[i]] = i - l + 1;
  for (long long i = l; i <= r; i++) {
    long long u = p[i];
    if (mid < w[u])
      MF::addEdge(MF::s, q[u], 1);
    else
      MF::addEdge(q[u], MF::t, 1);
    for (long long v : G[u])
      if (q[v]) MF::addEdge(q[u], q[v], INF);
  }
  for (long long i = l; i <= r; i++) q[p[i]] = 0;
  MF::Dinic();
  long long c1 = 0, c2 = 0;
  for (long long i = l; i <= r; i++)
    if (!MF::h[i - l + 1])
      t1[++c1] = p[i];
    else
      t2[++c2] = p[i];
  for (long long i = 1; i <= c1; i++) p[l + i - 1] = t1[i];
  for (long long i = 1; i <= c2; i++) p[l + c1 + i - 1] = t2[i];
  solve(l, l + c1 - 1, L, mid);
  solve(l + c1, r, mid, R);
}
signed main() {
  long long n, m;
  scanf("%lld%lld", &n, &m);
  for (long long i = 1; i <= n; i++) scanf("%lld", &w[i]);
  for (long long i = 1; i <= m; ++i) {
    long long u, v;
    scanf("%lld%lld", &u, &v);
    G[u].push_back(v);
  }
  for (long long i = 1; i <= n; i++) p[i] = i;
  solve(1, n, 0, 2e9);
  long long S = 0;
  for (long long i = 1; i <= n; i++)
    printf("%lld ", f[i]), S += abs(w[i] - f[i]);
  return 0;
}
