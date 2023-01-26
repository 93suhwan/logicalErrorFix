#include <bits/stdc++.h>
using namespace std;
const long long N = 2e3 + 7, M = 2e3 + 7, T = 20;
bool fl[N];
long long n, m, k, s, t, p, vq, z[N], a[N], b[N], f[N], sp[N], gap[N], cur[N],
    f1[T][N], f2[T][N], f3[T][N];
unsigned long long c[N], e[M];
vector<long long> v[N];
struct ed {
  long long u, v, t;
  long long w;
} ed[N << 4];
inline void addedge(long long u, long long t, long long w) {
  k++, ed[k].u = u, ed[k].v = t, ed[k].w = w, ed[k].t = z[u], z[u] = k;
}
inline long long addflow(long long u, long long c) {
  long long sum = 0;
  if (u == t) return c;
  for (long long i = z[u]; i > 0; i = ed[i].t) {
    if (ed[i].w && cur[u] == cur[ed[i].v] + 1) {
      long long x = min(c, ed[i].w), v = addflow(ed[i].v, x);
      c -= v, ed[i].w -= v, ed[i ^ 1].w += v, sum += v;
      if (c == 0) return sum;
    }
  }
  gap[cur[u]]--;
  if (!gap[cur[u]]) gap[0] = 0;
  cur[u]++, gap[cur[u]]++;
  return sum;
}
inline void bfs(long long u, long long q) {
  if (u <= n) fl[u] = 0;
  for (long long i = z[u]; i > 0; i = ed[i].t) {
    if (ed[i].w && ed[i].v <= n && fl[ed[i].v]) bfs(ed[i].v, q);
  }
}
inline void solve(long long l, long long r, long long d) {
  k = 1;
  if (f1[d][0] == 0) return;
  s = n + 1, t = n + 2;
  p = d;
  if (l == r) {
    for (long long i = 1; i <= f1[d][0]; i++) sp[f1[d][i]] = l;
    return;
  }
  for (long long i = 1; i <= f1[d][0]; i++)
    fl[f1[d][i]] = 1, z[f1[d][i]] = 0, cur[f1[d][i]] = 0;
  z[s] = z[t] = cur[s] = cur[t] = 0;
  long long w = (l + r) >> 1;
  vq = w;
  for (long long i = 1; i <= f1[d][0]; i++) {
    long long u = f1[d][i];
    for (long long j = 0; j < v[u].size(); j++)
      if (f1[v[u][j]]) addedge(v[u][j], u, 1e18), addedge(u, v[u][j], 0);
    long long c = (w - f[u] + 1) * (w - f[u] + 1) - (w - f[u]) * (w - f[u]);
    if (c <= 0)
      addedge(s, u, -c), addedge(u, s, 0);
    else
      addedge(u, t, c), addedge(t, u, 0);
  }
  gap[0] = f1[d][0] + 2;
  for (long long i = 1; i <= gap[0] + 10; i++) gap[i] = 0;
  long long vas = 0;
  while (gap[0]) vas += addflow(s, 1e18);
  f2[d][0] = 0, f3[d][0] = 0;
  bfs(s, d);
  for (long long i = 1; i <= f1[d][0]; i++) {
    if (!fl[f1[d][i]])
      f3[d][++f3[d][0]] = f1[d][i];
    else
      f2[d][++f2[d][0]] = f1[d][i];
    fl[f1[d][i]] = 0;
  }
  f1[d + 1][0] = 0;
  for (long long i = 1; i <= f2[d][0]; i++)
    f1[d + 1][++f1[d + 1][0]] = f2[d][i];
  solve(l, w, d + 1);
  f1[d + 1][0] = 0;
  for (long long i = 1; i <= f3[d][0]; i++)
    f1[d + 1][++f1[d + 1][0]] = f3[d][i];
  solve(w + 1, r, d + 1);
}
signed main() {
  cin >> n >> m;
  long long g = 0;
  for (long long i = 1; i <= n; i++) scanf("%lld", &f[i]), g = max(g, f[i]);
  for (long long i = 1; i <= m; i++) {
    long long u, v;
    scanf("%lld %lld", &u, &v);
    ::v[v].push_back(u);
  }
  for (long long i = 1; i <= n; i++) f1[0][++f1[0][0]] = i;
  solve(0, g, 0);
  long long sum = 0;
  for (long long i = 1; i <= n; i++) {
    printf("%lld ", sp[i]);
  }
}
