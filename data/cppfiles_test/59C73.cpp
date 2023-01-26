#include <bits/stdc++.h>
using namespace std;
const long long N = 1e3 + 1e2 + 7;
long long T, n, m;
vector<long long> g[N];
long long a[N], b[N];
long long ok[N], vis[N];
long long tag[N];
bool dfs(long long x, long long f, long long en, long long nd) {
  vis[x] = 1;
  for (auto v : g[x]) {
    if (v == f) continue;
    if (vis[v]) {
      if (nd) {
        tag[x] = 1;
        return 1;
      }
    } else if (en > a[v]) {
      long long ret = dfs(v, x, en + b[v] * (!ok[v]), nd | (!ok[v]));
      if (ret) {
        tag[x] = 1;
        return ret;
      }
    }
  }
  return 0;
}
bool chk(long long beg) {
  fill(ok + 1, ok + n + 1, 0);
  long long vs = 1;
  long long now = beg;
  while (vs != n) {
    fill(vis + 1, vis + n + 1, 0);
    fill(tag + 1, tag + n + 1, 0);
    long long go = dfs(1, 0, now, 0);
    if (!go) return 0;
    for (long long i = 2; i <= n; i++)
      if (tag[i] && !ok[i]) now += b[i], ok[i] = 1, vs++;
  }
  return 1;
}
signed main() {
  scanf("%lld", &T);
  while (T--) {
    scanf("%lld%lld", &n, &m);
    for (long long i = 1; i <= n; i++) g[i].clear();
    for (long long i = 2; i <= n; i++) scanf("%lld", &a[i]);
    for (long long i = 2; i <= n; i++) scanf("%lld", &b[i]);
    for (long long i = 1; i <= m; i++) {
      long long u, v;
      scanf("%lld%lld", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    long long l = 0, r = *max_element(a + 1, a + n + 1) + 1;
    while (r - l > 1) {
      long long mid = (l + r) >> 1;
      if (chk(mid))
        r = mid;
      else
        l = mid;
    }
    printf("%lld\n", r);
  }
}
