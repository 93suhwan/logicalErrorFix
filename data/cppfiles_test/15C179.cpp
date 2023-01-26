#include <bits/stdc++.h>
using namespace std;
const long long N = 105, MOD = 1e9 + 7;
vector<vector<long long>> adj;
map<long long, map<long long, long long>> cnt;
long long dep[N], ans, dp[N];
long long n, k;
void dfs(long long u, long long p, long long root) {
  cnt[root][dep[u]]++;
  for (auto v : adj[u]) {
    if (v == p) continue;
    dep[v] = dep[u] + 1;
    dfs(v, u, root);
  }
}
void solve() {
  cin >> n >> k;
  adj.clear();
  adj.resize(n + 1);
  for (long long i = 0; i < n - 1; i++) {
    long long u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  ans = 0;
  if (k == 2) {
    ans = n * (n - 1) / 2;
  } else {
    for (long long i = 1; i <= n; i++) {
      cnt.clear();
      for (auto v : adj[i]) {
        dep[v] = 1;
        dfs(v, i, v);
      }
      for (long long j = 1; j <= 100; j++) {
        fill(dp, dp + N, 0);
        dp[0] = 1;
        for (auto v : adj[i]) {
          for (long long kk = 100; ~kk; kk--) {
            dp[kk + 1] = (dp[kk + 1] + dp[kk] * cnt[v][j] % MOD);
          }
        }
        ans = (ans + dp[k]) % MOD;
      }
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
}
