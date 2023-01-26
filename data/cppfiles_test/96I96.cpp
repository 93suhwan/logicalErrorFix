#include <bits/stdc++.h>
using namespace std;
const int N = 510, mod = 998244353;
long long dp[510][510], dp2[510][510];
long long qpow(long long a, long long b) {
  if (a == 0) return 0;
  long long s = 1;
  while (b) {
    if (b & 1) s = s * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return s;
}
long long c[510][510];
void init() {
  c[0][0] = 1;
  c[0][1] = 0;
  for (int i = 1; i <= 510; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
      c[i][j] %= mod;
    }
  }
}
int main() {
  init();
  long long ans = 0;
  int n, k;
  cin >> n >> k;
  dp[0][0] = 1;
  for (int j = 0; j <= n; j++) {
    dp[j][n - 1] += c[n][j] * qpow(n - 1, j);
    if (j == n) ans += dp[j][n - 1];
  }
  for (int i = 2; i <= (k - n + 1) + 10; i++) {
    for (int j = 0; j < n - 1; j++) {
      if ((i - 1) * (n - j - 1) >= k) continue;
      int s = (i - 1) > 1 ? 0 : n - 1 + (i - 2);
      for (int l = 0; l <= k; l++) {
        if (l < s) continue;
        for (int d = j; d <= n; d++) {
          if (d == n) {
            ans += dp[j][l] * qpow(min(k, l + (n - j - 1)) - l, d - j),
                ans %= mod;
            continue;
          }
          if (l + (n - j - 1) > k) continue;
          dp2[d][l + (n - j - 1)] += dp[j][l] * c[n - j][d - j] % mod *
                                     qpow(l + (n - j - 1) - l, d - j);
          dp2[d][l + (n - j - 1)] %= mod;
        }
      }
    }
    for (int j = 0; j <= n; j++) {
      for (int l = 0; l <= k; l++) {
        dp[j][l] = dp2[j][l];
        dp2[j][l] = 0;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
