#include <bits/stdc++.h>
using namespace std;
int n, mod;
int fac[202], inv[202];
inline int inc(int a, int b) { return (a + b) < mod ? a + b : a + b - mod; }
inline int mul(int a, int b) { return (int)((long long int)a * b % mod); }
inline int pow(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
int dp[202][202][202];
int solve(int m) {
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; i++) dp[0][i][0] = inv[i];
  for (int i = 1; i <= n + 1; i++)
    for (int j = n - n / i; j <= n && j <= m + i - 1; j++)
      for (int k = 0; k <= n; k++)
        for (int p = 0; p <= j && p <= k / i; p++)
          dp[i][j][k] =
              inc(dp[i][j][k], mul(dp[i - 1][j - p][k - i * p], inv[p]));
  int res = 0;
  if (m >= n) res = inv[n];
  for (int k = 1; k <= m; k++) res = inc(res, dp[n + 1 - m][n][k]);
  return res;
}
int main(void) {
  scanf("%d%d", &n, &mod);
  fac[0] = inv[0] = 1;
  for (int i = 1; i <= n; i++) {
    fac[i] = mul(fac[i - 1], i);
    inv[i] = pow(fac[i], mod - 2);
  }
  int ans = 0;
  for (int m = n - 17; m <= n + 1; m++) ans = inc(ans, solve(m));
  printf("%d\n", mul(ans, fac[n]));
  return 0;
}
