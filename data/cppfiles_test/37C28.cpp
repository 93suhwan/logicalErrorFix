#include <bits/stdc++.h>
using namespace std;
const long long MN = 100005, MOD = 998244353;
long long t, n, u, v, val[MN], ans[MN];
vector<long long> a[MN];
void dfs(long long cur, long long par, long long k) {
  for (long long nxt : a[cur]) {
    if (nxt == par) continue;
    dfs(nxt, cur, k);
  }
  if (val[cur] % k && par)
    val[cur]++;
  else
    val[par]++;
}
int32_t main() {
  cin.tie(0), cin.sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (long long i = 1; i < n; i++) {
      cin >> u >> v;
      a[u].push_back(v);
      a[v].push_back(u);
    }
    ans[1] = 1;
    for (long long i = 1; i < n; i++) ans[1] = ans[1] * 2 % MOD;
    for (long long i = 2; i <= n; i++) {
      if ((n - 1) % i) continue;
      memset(val, 0, sizeof(val));
      dfs(1, 0, i);
      ans[i] = 1;
      for (long long j = 1; j <= n; j++)
        if (val[j] % i) ans[i] = 0;
    }
    for (long long i = n; i > 0; i--) {
      for (long long j = i + i; j <= n; j += i) ans[i] -= ans[j];
    }
    for (long long i = 1; i <= n; i++) printf("%lld ", ans[i]);
    printf("\n");
    for (long long i = 1; i <= n; i++) a[i].clear(), val[i] = ans[i] = 0;
  }
  return 0;
}
