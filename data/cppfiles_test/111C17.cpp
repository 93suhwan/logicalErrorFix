#include <bits/stdc++.h>
using namespace std;
const int N = 2005, M = 55, mod = 998244353;
int n, m, b[N], fac[N], ifac[N], dp[2][N][N * 2], sum[2][N][N * 2];
int L[N], R[N];
int fpow(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = 1ll * res * x % mod;
    x = 1ll * x * x % mod, y >>= 1;
  }
  return res;
}
void init(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[n] = fpow(fac[n], mod - 2);
  for (int i = n - 1; i >= 0; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
}
int main() {
  init(2000);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= n; i++) L[i] = max(0, b[i] - m), R[i] = min(i, b[i] + m);
  dp[0][0][0] = 1, sum[0][0][0] = 1, L[0] = 0, R[0] = n;
  for (int i = 1; i <= n; i++) {
    for (int j = L[i]; j <= R[i]; j++)
      for (int k = j; k <= i; k++) {
        dp[i & 1][j][k] =
            (dp[i & 1][j][k] + 1ll * k * dp[i - 1 & 1][j][k]) % mod;
        if (k)
          dp[i & 1][j][k] = (dp[i & 1][j][k] + dp[i - 1 & 1][j][k - 1]) % mod;
        if (j && k)
          dp[i & 1][j][k] = (dp[i & 1][j][k] +
                             1ll * sum[i - 1 & 1][min(j - 1, R[i - 1])][k - 1] *
                                 ifac[k - j]) %
                            mod;
        sum[i & 1][j][k] = 1ll * dp[i & 1][j][k] * fac[k - j] % mod;
        if (j)
          sum[i & 1][j][k] = (sum[i & 1][j][k] + sum[i & 1][j - 1][k]) % mod;
      }
    for (int j = L[i - 1]; j <= R[i - 1]; j++)
      for (int k = j; k <= i - 1; k++)
        dp[i - 1 & 1][j][k] = sum[i - 1 & 1][j][k] = 0;
  }
  int ans = 0;
  for (int j = L[n]; j <= R[n]; j++)
    for (int k = j; k <= n; k++)
      ans =
          (ans + 1ll * dp[n & 1][j][k] * fac[n - j] % mod * ifac[n - k]) % mod;
  printf("%d\n", ans);
  return 0;
}
