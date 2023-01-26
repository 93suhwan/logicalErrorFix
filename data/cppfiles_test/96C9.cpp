#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mod = 998244353;
void solve() {
  int n, x;
  cin >> n >> x;
  vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
  vector<vector<int>> C(n + 1, vector<int>(n + 1, 1));
  vector<vector<int>> pw(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    pw[i][0] = 1;
    for (int j = 1; j <= n; ++j) {
      pw[i][j] = (1ll * i * pw[i][j - 1]) % mod;
    }
  }
  for (int i = 1; i <= x; ++i) {
    dp[1][i] = i;
  }
  int total = 1;
  for (int i = 1; i <= n; ++i) {
    total = (1ll * total * x) % mod;
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = i; j <= x; ++j) {
      for (int k = 1; k <= i; ++k) {
        dp[i][j] =
            (dp[i][j] + (1ll * C[i][k] *
                         ((1ll * pw[i - 1][i - k] * dp[k][j - i + 1]) % mod)) %
                            mod) %
            mod;
      }
    }
  }
  int res = total - dp[n][x];
  if (res < 0) res += mod;
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
