#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long dp[505][505];
long long f[505][505];
long long kpow(long long x, int y) {
  long long ans = 1;
  while (y) {
    if (y & 1) {
      ans = (ans * x) % mod;
    }
    x = (x * x) % mod;
    y >>= 1;
  }
  return ans;
}
void pre() {
  f[0][0] = 1;
  for (int i = 1; i <= 500; i++) {
    f[i][0] = 1;
    for (int j = 1; j < i; j++) {
      f[i][j] = (f[i - 1][j] % mod + f[i - 1][j - 1] % mod) % mod;
    }
    f[i][i] = 1;
  }
}
int main() {
  int n, x;
  scanf("%d%d", &n, &x);
  pre();
  dp[0][0] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= x; j++) {
      if (j < i) {
        dp[i][j] = (kpow(j, i) % mod - kpow(j - 1, i) % mod + mod) % mod;
      }
      if (j >= i) {
        for (int k = 2; k <= i; k++) {
          dp[i][j] = (dp[i][j] +
                      f[i][k] * dp[k][j - i + 1] % mod * kpow(i - 1, i - k)) %
                     mod;
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= x; i++) {
    ans = (ans + dp[n][i]) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
