#include <bits/stdc++.h>
using namespace std;
const long long N = 1005, M = 1e4 + 5, inf = 1e18;
long long n, m, s, t, a[N];
long long to[M], nxt[M], ff[M], w[M], hd[N], tot = 1;
void add(long long u, long long v, long long f, long long ww) {
  to[++tot] = v, ff[tot] = f, w[tot] = ww, nxt[tot] = hd[u], hd[u] = tot;
  to[++tot] = u, ff[tot] = 0, w[tot] = -ww, nxt[tot] = hd[v], hd[v] = tot;
}
long long l[N], le[N], sw[N];
bool inq[N];
long long maxw;
bool Spfa() {
  memset(l, 0, sizeof(l));
  memset(le, 0, sizeof(le));
  memset(inq, 0, sizeof(inq));
  memset(sw, 0xcf, sizeof(sw));
  queue<long long> q;
  sw[s] = 0, inq[s] = true, q.push(s);
  while (!q.empty()) {
    long long u = q.front();
    inq[u] = false, q.pop();
    for (long long i = hd[u]; i; i = nxt[i]) {
      long long v = to[i];
      if (!ff[i]) continue;
      if (sw[u] + w[i] > sw[v]) {
        sw[v] = sw[u] + w[i];
        l[v] = u, le[v] = i;
        if (!inq[v]) inq[v] = true, q.push(v);
      }
    }
  }
  return sw[t] > 0;
}
void solve() {
  while (Spfa()) {
    long long flow = inf, k = t;
    while (k != s) {
      flow = min(flow, ff[le[k]]);
      ff[le[k]] -= flow;
      ff[le[k] ^ 1] += flow;
      k = l[k];
    }
    maxw += flow * sw[t];
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
    add(u, v, inf, a[u] - a[v]);
  }
  solve();
  for (long long i = 1; i <= n; i++) {
    if (ff[4 * i - 2] == 0 && ff[4 * i] == 0) ff[4 * i - 2] = ff[4 * i] = 1;
  }
  Spfa();
  for (long long i = 1; i <= n; i++) printf("%lld ", a[i] + sw[i]);
  puts("");
  return 0;
}
