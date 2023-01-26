#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
const long long INFF = 1e18;
const long long MAXN = 510;
const long long MOD = 998244353;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long getTC() {
  if (1) {
    long long t;
    cin >> t;
    return t;
  } else
    return 1;
}
long long add(long long x, long long y) {
  return ((x % MOD) + (y % MOD)) % MOD;
}
long long sub(long long x, long long y) {
  long long ret = ((x % MOD) - (y % MOD)) % MOD;
  if (ret < 0) ret += MOD;
  return ret;
}
long long mul(long long x, long long y) {
  return ((x % MOD) * (y % MOD)) % MOD;
}
long long modpow(long long x, long long y) {
  if (!y) return 1;
  long long z = modpow(x, y / 2);
  z = mul(z, z);
  if (y & 1) z = mul(z, x);
  return z;
}
long long reverse(long long x) { return modpow(x, MOD - 2); }
long long bagi(long long x, long long y) { return mul(x, reverse(y)); }
void solve() {
  long long n;
  cin >> n;
  vector<long long> tab(n);
  for (auto &it : tab) cin >> it;
  vector<vector<long long>> dp(2, vector<long long>(n + 3, 0));
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    if (tab[i] == 0) {
      dp[0][0] = add(dp[0][0], dp[0][0]);
      dp[0][0] = add(dp[0][0], 1);
    } else {
      dp[1][tab[i]] = add(dp[1][tab[i]], dp[1][tab[i]]);
      dp[0][tab[i]] = add(dp[0][tab[i]], dp[0][tab[i]]);
      if (tab[i] > 2)
        dp[1][tab[i]] = add(dp[1][tab[i]], dp[0][tab[i] - 2]);
      else if (tab[i] == 2)
        dp[1][tab[i]] = add(dp[1][tab[i]], dp[0][tab[i] - 2]);
      dp[0][tab[i]] = add(dp[0][tab[i]], dp[0][tab[i] - 1]);
      if (tab[i] == 1) dp[1][tab[i]] = add(dp[1][tab[i]], 1);
    }
  }
  for (long long i = 0; i <= n; i++) {
    ans = add(ans, dp[0][i]);
    ans = add(ans, dp[1][i]);
  }
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = getTC();
  while (t--) {
    solve();
  }
  return 0;
}
