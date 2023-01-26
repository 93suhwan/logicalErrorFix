#include <bits/stdc++.h>
const long long mod = 998244353;
const long long MAX = INT_MAX;
const long long inf = LLONG_MAX;
const double pi = 3.14159265358979323846;
long long dirX[] = {1, -1, 0, 0};
long long dirY[] = {0, 0, 1, -1};
using namespace std;
void print_bool(bool zeman_modnar) {
  if (zeman_modnar)
    cout << "YES"
         << "\n";
  else
    cout << "NO"
         << "\n";
}
long long fastexp(long long a, long long b) {
  long long ans = 1;
  long long temp = a;
  while (b > 0) {
    if (b & 1) ans = (ans * temp) % mod;
    temp = (temp * temp) % mod;
    b >>= 1;
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  long long x;
  cin >> x;
  long long dp[n + 1][x + 1];
  memset(dp, 0, sizeof dp);
  long long ncr[501][501];
  for (long long i = 0; i <= 500; i++) {
    ncr[i][0] = ncr[i][i] = 1;
    for (long long j = 1; j < i; j++) {
      ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % mod;
    }
  }
  dp[n][0] = 1;
  for (long long i = n; i >= 1; i--) {
    for (long long j = 0; j <= x; j++) {
      if (dp[i][j] == 0) continue;
      long long damage = min(x, j + i - 1);
      long long contri = 1;
      for (long long k = i; k >= 0; k--) {
        dp[k][damage] += (dp[i][j] * (ncr[i][k] * contri) % mod) % mod;
        dp[k][damage] %= mod;
        contri *= (damage - j);
        contri %= mod;
      }
    }
  }
  long long ans = 0;
  for (long long i = 0; i <= x; i++) {
    ans += dp[0][i];
    ans %= mod;
  }
  cout << ans << "\n";
  return 0;
}
