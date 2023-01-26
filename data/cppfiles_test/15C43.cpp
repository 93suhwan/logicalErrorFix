#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long long N = 1e3;
const long long MOD = 1e9 + 7;
const long long inf = 1e10;
const long double eps = 1e-12;
const long double EPS = 1e-10;
long long rx[] = {1, -1, 0, 0};
long long ry[] = {0, 0, 1, -1};
vector<long long> g[N];
long long used[N], dp[N][N], cnt[N];
long long rundp(long long m, long long k) {
  for (long long i = 0; i <= m; ++i) {
    for (long long j = 0; j <= k; ++j) {
      dp[i][j] = 0;
    }
  }
  dp[0][0] = 1;
  for (long long i = 0; i < m; ++i) {
    for (long long j = 0; j <= k; ++j) {
      dp[i + 1][j] += dp[i][j];
      dp[i + 1][j] %= MOD;
      dp[i + 1][j + 1] += (dp[i][j] * cnt[i]);
      dp[i + 1][j + 1] %= MOD;
    }
  }
  return dp[m][k];
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long Q;
  cin >> Q;
  while (Q--) {
    long long n, k;
    cin >> n >> k;
    for (long long i = 0; i < n; ++i) g[i].clear();
    for (long long i = 1; i < n; ++i) {
      long long x, y;
      cin >> x >> y;
      x--;
      y--;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    if (k == 2) {
      cout << (n * (n - 1) / 2) % MOD << '\n';
      continue;
    }
    long long ans = 0;
    for (long long c = 0; c < n; ++c) {
      fill(used, used + n, 0);
      used[c] = 1;
      vector<pair<long long, long long> > layer;
      long long m = g[c].size();
      for (long long i = 0; i < m; ++i) {
        long long x = g[c][i];
        layer.push_back({x, i});
        cnt[i] = 1;
        used[x] = 1;
      }
      while (!layer.empty()) {
        ans = ans + rundp(m, k);
        ans %= MOD;
        vector<pair<long long, long long> > nlayer;
        for (auto to : layer) {
          cnt[to.second]--;
          for (auto x : g[to.first]) {
            if (used[x]) continue;
            nlayer.push_back({x, to.second});
            used[x] = 1;
            cnt[to.second]++;
          }
        }
        layer = nlayer;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
