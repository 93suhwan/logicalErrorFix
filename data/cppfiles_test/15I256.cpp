#include <bits/stdc++.h>
const long long MAXN = 105;
const long long MOD = 1000000007;
std::vector<long long> Adj[MAXN];
long long d[MAXN][MAXN];
void dfs(long long u, long long p, long long h, long long dep) {
  d[h][dep]++;
  for (long long j : Adj[u]) {
    if (j == p) continue;
    dfs(j, u, h, dep + 1);
  }
}
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  long long t;
  std::cin >> t;
  long long binom[MAXN][MAXN];
  for (long long i = 0; i < MAXN; i++) binom[i][0] = binom[i][i] = 1;
  for (long long j = 2; j < MAXN; j++)
    for (long long k = 1; k < j; k++)
      binom[j][k] = (binom[j - 1][k - 1] + binom[j - 1][k]) % MOD;
  while (t--) {
    long long n, k;
    std::cin >> n >> k;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < n; j++) d[i][j] = 0;
      Adj[i].clear();
    }
    for (long long i = 1; i < n; i++) {
      long long u, v;
      std::cin >> u >> v;
      u--;
      v--;
      Adj[u].push_back(v);
      Adj[v].push_back(u);
    }
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      dfs(i, -1, i, 0);
      for (long long j = 1; j < n; j++) {
        if (d[i][j] >= k) ans += binom[d[i][j]][k];
        ans %= MOD;
      }
    }
    std::cout << ans << std::endl;
  }
  return 0;
}
