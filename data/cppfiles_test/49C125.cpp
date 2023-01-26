#include <bits/stdc++.h>
using namespace std;
const int N = 15, M = 1 << 15;
const long long mod = 1e9 + 7;
long long qpow(long long a, long long b) {
  long long ans = 1;
  for (; b; b >>= 1, a = a * a % mod)
    if (b & 1) ans = ans * a % mod;
  return ans;
}
long long dp[M], val[N][M], sum[N][M], a[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      val[i][j] = a[i] * qpow(a[i] + a[j], mod - 2) % mod;
  int mx = 1 << n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < mx; j++) {
      sum[i][j] = 1;
      for (int k = 0; k < n; k++)
        if ((1 << k) & j) sum[i][j] = sum[i][j] * val[i][k] % mod;
    }
  }
  for (int i = 1; i < mx; i++) {
    for (int j = 0; j < n; j++)
      if (i & (1 << j)) dp[i]++;
    for (int j = i & (i - 1); j; j = (j - 1) & i) {
      long long del = dp[j];
      for (int k = 0; k < n; k++)
        if (((1 << k) & i) && !((1 << k) & j)) del = del * sum[k][j] % mod;
      dp[i] = (dp[i] - del + mod) % mod;
    }
  }
  printf("%lld\n", dp[mx - 1]);
  return 0;
}
