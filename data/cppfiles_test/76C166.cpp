#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9;
long long dp[200005];
void solve() {
  long long n, mod, sum = 0;
  cin >> n >> mod;
  dp[1] = 1, sum = 1;
  for (long long i = 2; i <= n; i++) {
    dp[i] = sum;
    long long val = 0;
    for (long long l = 1, r; l <= i; l = r + 1) {
      r = i / (i / l);
      val = (val + (r - l + 1) * dp[i / l] % mod) % mod;
    }
    dp[i] = val;
    sum = (sum + dp[i]) % mod;
  }
  cout << dp[n];
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
