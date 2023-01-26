#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1005, maxm = 6005;
long long n, m, s, t, e = 1, flg, ans;
long long start[maxn], to[maxm], then[maxm], limit[maxm], dep[maxn], vis[maxn],
    a[maxn], xx[maxn], yy[maxn], id[maxn], b[maxn], g[maxn][maxn], d[maxn];
queue<long long> q;
inline void add(long long x, long long y, long long z) {
  then[++e] = start[x], start[x] = e, to[e] = y, limit[e] = z;
}
inline void addedge(long long x, long long y, long long z) {
  add(x, y, z), add(y, x, 0);
}
inline long long cmp(long long a, long long b) { return d[a] < d[b]; }
long long bfs(long long s, long long t) {
  for (long long i = 1; i <= t; i++) dep[i] = 10000000000000000, vis[i] = 0;
  dep[s] = 0, vis[s] = 1, q.push(s);
  while (!q.empty()) {
    long long x = q.front();
    vis[x] = 0, q.pop();
    for (long long i = start[x]; i; i = then[i]) {
      long long y = to[i];
      if (limit[i] && dep[y] >= dep[x] + 1) {
        dep[y] = dep[x] + 1;
        if (vis[y] == 0) vis[y] = 1, q.push(y);
      }
    }
  }
  return dep[t] != 10000000000000000;
}
long long dfs(long long x, long long flw, long long t) {
  if (x == t) {
    flg = 1, ans += flw;
    return flw;
  }
  long long rest = flw;
  for (long long i = start[x]; i; i = then[i]) {
    long long y = to[i];
    if (limit[i] && dep[y] == dep[x] + 1) {
      long long newflw = dfs(y, min(limit[i], rest), t);
      if (newflw) {
        rest -= newflw, limit[i] -= newflw, limit[i ^ 1] += newflw;
        if (rest == 0) break;
      } else
        dep[y] = 0;
    }
  }
  return flw - rest;
}
long long Dinic(long long s, long long t) {
  ans = 0;
  while (bfs(s, t))
    for (flg = 1; flg;) flg = 0, dfs(s, 10000000000000000, t);
  return ans;
}
void solve(long long l, long long r, long long L, long long R) {
  if (L > R) return;
  if (l == r) {
    for (long long i = L; i <= R; i++) b[id[i]] = l;
    return;
  }
  long long mid = (l + r) >> 1;
  e = 1, memset(start, 0, sizeof(start));
  for (long long i = L; i <= R; i++)
    for (long long j = L; j <= R; j++)
      if (g[id[i]][id[j]]) addedge(i, j, 10000000000000000);
  for (long long i = L; i <= R; i++) {
    long long p = abs(a[id[i]] - mid - 1), q = abs(a[id[i]] - mid);
    if (p >= q)
      addedge(s, i, p - q);
    else
      addedge(i, t, q - p);
  }
  Dinic(s, t);
  for (long long i = L; i <= R; i++) d[id[i]] = dep[i];
  sort(id + L, id + 1 + R, cmp);
  long long pos = R;
  for (long long i = L; i <= R; i++)
    if (d[id[i]] == 10000000000000000) {
      pos = i - 1;
      break;
    }
  solve(l, mid, L, pos), solve(mid + 1, r, pos + 1, R);
}
signed main() {
  scanf("%lld%lld", &n, &m), s = n + 1, t = s + 1;
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]), id[i] = i;
  for (long long i = 1, x, y; i <= m; i++)
    scanf("%lld%lld", &x, &y), g[y][x] = 1;
  solve(-1e15, 1e15, 1, n);
  for (long long i = 1; i <= n; i++)
    printf("%lld%c", b[i], i == n ? '\n' : ' ');
  return 0;
}
