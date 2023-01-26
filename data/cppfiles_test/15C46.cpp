#include <bits/stdc++.h>
const long long inf = 0x3f3f3f3f;
const double dinf = 1e100;
using namespace std;
const long long maxn = 205;
const long long mod = 1e9 + 7;
long long n, k;
long long d[maxn];
long long a[maxn][maxn];
vector<long long> e[maxn];
long long dp[maxn][maxn], w[maxn];
void dfs(long long u, long long fa, long long rt) {
  d[u] = d[fa] + 1, a[rt][d[u]]++;
  for (auto x : e[u]) {
    if (x == fa) continue;
    dfs(x, u, rt);
  }
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (long long i = (1); i <= (n); ++i) e[i].clear();
    for (long long i = (1); i <= ((n - 1)); ++i) {
      long long l, r;
      cin >> l >> r;
      e[l].push_back(r), e[r].push_back(l);
    }
    if (k == 2) {
      cout << n * (n - 1) / 2 << endl;
    } else {
      long long ans = 0;
      for (long long i = (1); i <= (n); ++i) {
        d[i] = 0;
        for (long long j = 0; j < e[i].size(); ++j) {
          dfs(e[i][j], i, e[i][j]);
        }
        for (long long j = (1); j <= (n); ++j) {
          long long p = 0;
          for (auto x : e[i]) {
            w[++p] = a[x][j];
          }
          memset(dp, 0, sizeof(dp));
          dp[0][0] = 1;
          for (long long i = (1); i <= (p); ++i) {
            for (long long j = 0; j <= min(i, k); ++j) {
              if (j > 0)
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * w[i] % mod) % mod;
              dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            }
          }
          ans = (ans + dp[p][k]) % mod;
        }
        memset(a, 0, sizeof(a));
      }
      cout << ans << endl;
    }
  }
  return 0;
}
