#include <bits/stdc++.h>
using lint = long long;
constexpr lint maxn = 2e5 + 5;
constexpr lint inf = 1e9;
constexpr lint mod = 1e9 + 7;
using namespace std;
using pii = pair<lint, lint>;
lint t, n, k;
lint dp[maxn][2];
lint exp(lint a, lint b) {
  a %= mod;
  lint ret = 1;
  while (b) {
    if (b & 1) ret *= a;
    a *= a;
    ret %= mod;
    a %= mod;
    b >>= 1;
  }
  return ret;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    if (k == 0) {
      cout << 1 << '\n';
      continue;
    }
    if (n % 2 == 0) {
      lint comb = exp(2, n - 1) - 1;
      dp[0][1] = 1;
      dp[0][0] = comb;
      for (lint i = 1; i < k; i++) {
        lint prev = (dp[i - 1][0] + dp[i - 1][1]) % mod;
        dp[i][0] = (prev * comb) % mod;
        dp[i][1] = exp(exp(2, mod), n * i / mod) * exp(2, n * i % mod) % mod;
      }
    } else {
      lint comb = exp(2, n - 1);
      dp[0][1] = 1;
      dp[0][0] = comb;
      for (lint i = 1; i < k; i++) {
        lint prev = (dp[i - 1][0] + dp[i - 1][1]) % mod;
        dp[i][0] = (prev * comb) % mod;
        dp[i][1] = prev % mod;
      }
    }
    cout << (dp[k - 1][0] + dp[k - 1][1]) % mod << '\n';
  }
}
