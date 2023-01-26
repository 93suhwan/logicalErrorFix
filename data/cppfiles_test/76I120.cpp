#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.14159265358979323846;
const long long M = 1e18 + 7;
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const int mod = 998244353;
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<long long> dp(MX, 0), dp1(MX, 0), pre(MX, 0);
  dp1[1] = 0;
  for (long long i = 2; i < (n + 1); ++i) {
    pre[i] = (pre[i - 1] + pre[i]) % m;
    dp[i] += dp1[i - 1] + pre[i] + (i + 1) / 2 + 1;
    dp[i] %= m;
    for (int j = 2; j * i <= n; j++) {
      pre[i * j] += dp[i];
      pre[i * j] %= m;
      if (j * i + j > n) continue;
      int x = j * i + j;
      pre[x] -= dp[i];
      pre[x] %= m;
    }
    dp1[i] += (dp1[i - 1] + dp[i]) % m;
  }
  cout << dp[n] << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
