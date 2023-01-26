#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long n, k, b;
long long dep[200010], fa[200010], vis[200010], cnt[200010], p[200010];
long long ans = -1e18;
vector<long long> g[200010];
void dfs(long long u) {
  dep[u] = dep[fa[u]] + 1;
  for (auto v : g[u])
    if (v != fa[u]) {
      fa[v] = u;
      dfs(v);
    }
}
bool cmp1(long long u, long long v) { return dep[u] > dep[v]; }
bool cmp2(long long u, long long v) { return cnt[u] > cnt[v]; }
signed main() {
  scanf("%lld%lld", &n, &k);
  for (long long i = 1; i < n; i++) {
    long long u, v;
    scanf("%lld%lld", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1);
  for (long long i = 1; i <= n; i++) p[i] = i;
  sort(p + 1, p + n + 1, cmp1);
  for (long long i = 1; i <= n; i++) {
    long long u = p[i];
    while (u && !vis[u]) vis[u] = 1, cnt[p[i]]++, u = fa[u];
  }
  memset(vis, 0, sizeof(vis));
  sort(p + 1, p + n + 1, cmp2);
  b = n;
  for (long long i = 1; i <= k; i++) {
    long long u = p[i];
    while (u && !vis[u]) vis[u] = 1, b--, u = fa[u];
    long long B = min(b, n / 2);
    ans = max(ans, (i - B) * (n - B - i));
  }
  printf("%lld\n", ans);
  return 0;
}
