#include <bits/stdc++.h>
using namespace std;
const long long N = 1005, M = 1e4 + 5, inf = 1e18;
long long n, m, s, t, a[N];
long long to[M], nxt[M], fl[M], w[M], hd[N], tot = 1;
void add(long long u, long long v, long long f, long long ww) {
  to[++tot] = v, fl[tot] = f, w[tot] = ww, nxt[tot] = hd[u], hd[u] = tot;
  to[++tot] = u, fl[tot] = 0, w[tot] = -ww, nxt[tot] = hd[v], hd[v] = tot;
}
long long l[N], le[N], h[N], dis[N];
bool vis[N];
long long maxw;
bool dij() {
  priority_queue<pair<long long, long long>> q;
  memset(vis, 0, sizeof(vis));
  memset(dis, 0x3f, sizeof(dis));
  dis[s] = 0;
  q.push({0, s});
  while (!q.empty()) {
    long long u = q.top().second;
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (long long i = hd[u]; i; i = nxt[i]) {
      long long v = to[i], nw = w[i] + h[u] - h[v];
      if (fl[i] && dis[u] + nw < dis[v]) {
        dis[v] = dis[u] + nw;
        l[v] = u, le[v] = i;
        if (!vis[v]) q.push({-dis[v], v});
      }
    }
  }
  return h[t] + dis[t] < 0;
}
void spfa() {
  queue<long long> q;
  memset(h, 0x3f, sizeof(h));
  memset(vis, 0, sizeof(vis));
  h[s] = 0;
  q.push(s);
  while (!q.empty()) {
    long long u = q.front();
    q.pop();
    vis[u] = false;
    for (long long i = hd[u]; i; i = nxt[i]) {
      long long v = to[i];
      if (fl[i] && h[u] + w[i] < h[v]) {
        h[v] = h[u] + w[i];
        if (!vis[v]) vis[v] = true, q.push(v);
      }
    }
  }
}
signed main() {
  scanf("%lld%lld", &n, &m);
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
  s = n + 1, t = n + 2;
  for (long long i = 1; i <= n; i++) add(s, i, 1, 0), add(i, t, 1, 0);
  for (long long i = 1; i <= m; i++) {
    long long u, v;
    scanf("%lld%lld", &u, &v);
    add(u, v, inf, a[v] - a[u]);
  }
  spfa();
  while (dij()) {
    long long minf = inf;
    for (long long i = 1; i <= t; i++) h[i] += dis[i];
    for (long long i = t; i != s; i = l[i]) minf = min(minf, fl[le[i]]);
    for (long long i = t; i != s; i = l[i]) {
      fl[le[i]] -= minf;
      fl[le[i] ^ 1] += minf;
    }
    maxw -= h[t] * minf;
  }
  for (long long i = 1; i <= n; i++) {
    if (fl[4 * i - 2] == 0 && fl[4 * i] == 0) fl[4 * i - 2] = fl[4 * i] = 1;
  }
  spfa();
  for (long long i = 1; i <= n; i++) printf("%lld ", a[i] - h[i]);
  puts("");
  return 0;
}
