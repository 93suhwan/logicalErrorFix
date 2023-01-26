#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("popcnt")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long mod = 998244353;
const long long maxn = 555;
long long dp[maxn][maxn], g[maxn][maxn];
long long fact[maxn], revf[maxn], ans;
long long powMod(long long x, long long k) {
  long long ret = 1;
  for (; k; k >>= 1, x = 1ll * x * x % mod) {
    if (k & 1) (ret *= x) %= mod;
  }
  return ret;
}
long long ckn(long long n, long long k) {
  return fact[n] * revf[k] % mod * revf[n - k] % mod;
}
long long n, x;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> x;
  fact[0] = 1;
  memset(dp, 0, sizeof(dp));
  memset(g, 0, sizeof(g));
  for (long long i = 1; i <= 500; ++i) {
    fact[i] = fact[i - 1] * i % mod;
  }
  revf[500] = powMod(fact[500], mod - 2);
  for (long long i = 499; i >= 0; --i) {
    revf[i] = revf[i + 1] * (i + 1) % mod;
  }
  for (long long i = 1; i <= x; ++i) dp[1][i] = 1;
  for (long long i = 2; i <= n; ++i)
    for (long long k = 0; k <= i - 1; ++k) {
      g[i][k] = powMod(i - 1, k) * ckn(i, k) % mod;
    }
  for (long long i = 2; i <= n; ++i)
    for (long long j = i; j <= x; ++j)
      for (long long k = 0; k <= i - 1; ++k) {
        (dp[i][j] += dp[i - k][j - i + 1] * g[i][k] % mod) %= mod;
      }
  ans = powMod(x, n);
  for (long long i = 1; i <= x; ++i) {
    ((ans -= dp[n][i]) += mod) %= mod;
  }
  cout << ans << '\n';
  return 0;
}
