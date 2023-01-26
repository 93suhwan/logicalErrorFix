#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e2 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9 + 9;
vector<long long> g[maxn];
long long dp[maxn][maxn];
long long depth[maxn][maxn];
long long maxdep, cc;
void dfs(long long x, long long p, long long t, long long level) {
  maxdep = max(maxdep, level);
  if (t == -1) {
    long long tot = 0;
    for (auto i : g[x]) dfs(i, x, ++tot, 1);
    cc = tot;
  } else {
    depth[t][level]++;
    for (auto i : g[x]) {
      if (i == p) continue;
      dfs(i, x, t, level + 1);
    }
  }
}
long long rundp(long long n, long long level, long long k) {
  dp[0][0] = 1;
  for (long long i = 1; i <= n; i++) {
    for (long long c = 0; c <= cc; c++) {
      if (c == 0)
        dp[i][c] = dp[i - 1][c];
      else
        dp[i][c] =
            (dp[i - 1][c] + dp[i - 1][c - 1] * depth[i][level] % mod) % mod;
    }
  }
  return dp[cc][k];
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k, ans = 0;
    cin >> n >> k;
    for (long long i = 1; i <= n; i++) g[i].clear();
    for (long long i = 1; i < n; i++) {
      long long u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    if (k == 2) {
      cout << n * (n - 1) / 2 << '\n';
      continue;
    }
    for (long long i = 1; i <= n; i++) {
      maxdep = 0;
      memset(depth, 0, sizeof(depth));
      dfs(i, -1, -1, 0);
      for (long long j = 1; j <= maxdep; j++) {
        memset(dp, 0, sizeof(dp));
        ans = (rundp(n, j, k) + ans) % mod;
      }
    }
    cout << ans << '\n';
  }
}
