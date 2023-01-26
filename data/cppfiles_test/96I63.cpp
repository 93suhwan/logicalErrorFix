#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mod = 998244353;
void solve() {
  int n, x;
  cin >> n >> x;
  vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
  for (int i = 1; i <= x; ++i) {
    dp[1][i] = 1;
  }
  int total = 1;
  for (int i = 1; i <= n; ++i) {
    total = (1ll * total * x) % mod;
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = i; j <= x; ++j) {
      for (int k = 1; k <= i; ++k) {
        dp[i][j] = (dp[i][j] + dp[k][j - i + 1]) % mod;
      }
    }
  }
  int res = total;
  for (int i = 1; i <= x; ++i) {
    res = (res - dp[n][i] + mod) % mod;
  }
  cout << res << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
