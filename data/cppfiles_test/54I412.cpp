#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 10;
const long long mod = 1e9 + 7;
const long long INF = 0x3f3f3f3f3f3f3f3f;
long long dp[N];
long long n, k;
long long qpow(long long a, long long b) {
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
  dp[0] = 1;
  if (n & 1) {
    for (long long i = k; i >= 1; i--) {
      dp[i] = ((1 << (n - 1)) + 1) % mod * dp[i - 1] % mod;
    }
  } else {
    for (long long i = k; i >= 1; i--) {
      dp[i] = (qpow((1 << n), k - 1) +
               ((1 << (n - 1)) - 1) % mod * dp[i - 1] % mod) %
              mod;
    }
  }
  cout << dp[k] << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
