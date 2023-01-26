#include <bits/stdc++.h>
constexpr int maxn = 2e5 + 5;
constexpr int inf = 1e9;
constexpr int mod = 1e9 + 7;
using namespace std;
using lint = long long;
using pii = pair<int, int>;
lint t, n, k;
lint dp[maxn][2];
lint exp(lint a, lint b) {
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
    lint comb = (exp(2, n - 1) - (n + 1) % 2) % mod;
    dp[0][1] = 1;
    dp[0][0] = comb;
    for (lint i = 1; i < k; i++) {
      lint prev = (dp[i - 1][0] + dp[i - 1][1]) % mod;
      dp[i][1] = prev;
      dp[i][0] = (prev * comb) % mod;
    }
    cout << (k == 0 ? 1 : (dp[k - 1][0] + dp[k - 1][1]) % mod) << '\n';
  }
}
