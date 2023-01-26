#include <bits/stdc++.h>
using namespace std;
long long t;
long long k, n;
long long u_, v_;
vector<long long> g[107];
long long d[107][107];
long long f[107][107];
long long v[107];
long long dfs(long long root, long long cur, long long dis) {
  d[root][dis]++;
  v[cur] = 1;
  for (auto nxt : g[cur]) {
    if (v[nxt] == 0) {
      dfs(root, nxt, dis + 1);
    }
  }
}
signed main() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    long long ans = 0;
    for (long long i = 1; i <= n; ++i) {
      g[i].clear();
    }
    for (long long i = 1; i <= n - 1; ++i) {
      cin >> u_ >> v_;
      g[u_].push_back(v_);
      g[v_].push_back(u_);
    }
    if (k == 2) {
      cout << ((n * (n - 1)) / 2) << endl;
      continue;
    }
    for (long long i = 1; i <= n; ++i) {
      if (g[i].size() >= k) {
        memset(d, 0, sizeof(d));
        memset(v, 0, sizeof(v));
        v[i] = 1;
        for (long long j = 0; j < g[i].size(); ++j) {
          dfs(j + 1, g[i][j], 1);
        }
        for (long long dep = 1; dep <= n; dep++) {
          for (long long j = 0; j <= g[i].size(); j++) {
            f[j][0] = 1;
          }
          for (long long j = 1; j <= g[i].size(); j++) {
            for (long long k = 1; k <= j; k++) {
              f[j][k] =
                  (f[j - 1][k] + (f[j - 1][k - 1] * d[j][dep]) % 1000000007) %
                  1000000007;
            }
          }
          ans += f[g[i].size()][k];
          ans %= 1000000007;
        }
      }
    }
    cout << ans << endl;
  }
}
