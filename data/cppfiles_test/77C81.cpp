#include <bits/stdc++.h>
using namespace std;
const int N = 10 + 4e6;
long long dp[N];
int n, mod;
void solve() {
  cin >> n >> mod;
  dp[1] = 1, dp[2] = 2;
  for (int i = 2; i <= n; i++) {
    if (i > 2) dp[i] = (dp[i] + dp[i - 1] * 2 + 1) % mod;
    long long d = dp[i] - dp[i - 1];
    for (int j = 2; j <= n / i; j++) dp[i * j] += d;
  }
  cout << (dp[n] % mod + mod) % mod << endl;
}
signed main() {
  ios::sync_with_stdio();
  solve();
  return 0;
}
