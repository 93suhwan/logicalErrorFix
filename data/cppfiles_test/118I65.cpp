#include <bits/stdc++.h>
using namespace std;
long long n;
const long long mod = 998244353;
const long long N = 3e5;
vector<long long> v[N];
long long dp[N][200];
long long sz[N];
long long f[N];
inline void dfs(long long x, long long fa) {
  sz[x] = 1;
  long long s = 0;
  dp[x][0] = 1;
  for (auto y : v[x]) {
    if (y == fa) continue;
    s++;
    dfs(y, x);
    memset(f, 0, sizeof(f));
    for (long long i = 0; i < sz[x]; i++) {
      for (long long j = 0; j <= sz[y]; j++) {
        f[i + j] += dp[x][i] * dp[y][j];
        f[i + j] %= mod;
      }
    }
    for (long long i = 0; i <= sz[x] + sz[y]; i++) dp[x][i] = f[i];
    sz[x] += sz[y];
  }
  for (long long i = sz[x]; i >= 0; i--) {
    (dp[x][i + 1] += dp[x][i] * s) %= mod;
  }
}
long long F[N];
int32_t main() {
  F[0] = 1;
  for (long long i = 1; i <= 250000; i++) F[i] = F[i - 1] * i % mod;
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (long long i = 1; i <= n - 1; i++) {
    long long x, y;
    cin >> x >> y;
    v[x].push_back(y), v[y].push_back(x);
  }
  dfs(1, 0);
  long long ans = 0;
  for (long long i = 0; i <= n; i++) {
    if (i % 2 == 0)
      ans += F[n - i] * dp[1][i];
    else
      ans -= F[n - i] * dp[1][i];
    ans %= mod;
  }
  ans += mod;
  ans %= mod;
  cout << ans;
}
