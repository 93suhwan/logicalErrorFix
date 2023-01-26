#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> g[n + 1];
  for (long long i = 1; i < n; i++) {
    long long u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  if (k == 2) {
    cout << n * (n - 1) / 2 % mod << "\n";
    return;
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    long long len = (long long)g[i].size();
    vector<vector<long long>> cnt(n + 1, vector<long long>(len + 1));
    queue<pair<long long, pair<long long, long long>>> q;
    vector<bool> used(n + 1);
    used[i] = true;
    for (long long j = 0; j < len; j++) {
      used[g[i][j]] = true;
      q.push({g[i][j], {1, j + 1}});
      cnt[1][j + 1]++;
    }
    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      long long v = cur.first, depth = cur.second.first,
                subtree = cur.second.second;
      for (long long u : g[v]) {
        if (!used[u]) {
          used[u] = true;
          q.push({u, {depth + 1, subtree}});
          cnt[depth + 1][subtree]++;
        }
      }
    }
    for (long long depth = 1; depth <= n; depth++) {
      vector<vector<long long>> dp(len + 1, vector<long long>(k + 1));
      dp[0][0] = 1;
      for (long long j = 1; j <= len; j++) {
        for (long long vers = 0; vers <= k; vers++) {
          dp[j][vers] += dp[j - 1][vers];
          if (vers > 0) dp[j][vers] += dp[j - 1][vers - 1] * cnt[depth][j];
          dp[j][vers] %= mod;
        }
      }
      ans += dp[len][k];
      ans %= mod;
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
