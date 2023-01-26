#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 10;
const long long mod = 1e9 + 7;
const long long INF = 0x3f3f3f3f3f3f3f3f;
long long pow2[N] = {1};
long long dp[N] = {1};
long long n, k;
long long ksm(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return res % mod;
}
void solve() {
  cin >> n >> k;
  if (n & 1) {
    for (long long i = 1; i <= k; i++)
      dp[i] = (1 + pow2[n - 1]) % mod * dp[i - 1] % mod;
  } else {
    for (long long i = 1; i <= k; i++)
      dp[i] = (ksm(pow2[n], i - 1) + dp[i - 1] * (pow2[n - 1] - 1) % mod) % mod;
  }
  cout << dp[k] << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (long long i = 1; i <= 2e5 + 10; i++) pow2[i] = 2 * pow2[i - 1] % mod;
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
