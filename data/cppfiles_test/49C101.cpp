#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, N = 107, M = 40007;
int f[M], s[N][N], ans, a[N], i, j, n;
int P(int x, int y, int res = 1) {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (x & (1 << i - 1))
        if (y & (1 << j - 1)) res = 1LL * res * s[i][j] % mod;
  return res;
}
int pow(int x, int n) {
  int res = 1;
  while (n) {
    if (n & 1) res = 1LL * res * x % mod;
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return res;
}
int main() {
  for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d", a + i);
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j)
      s[i][j] = 1LL * a[i] * pow(a[i] + a[j], mod - 2) % mod;
  for (i = 1; i < (1 << n); ++i) {
    f[i] = 1;
    for (j = i & (i - 1); j; j = (j - 1) & i)
      f[i] = (f[i] - 1LL * f[j] * P(j, i - j) % mod + mod) % mod;
  }
  for (i = 1; i < (1 << n); ++i)
    ans = (ans +
           1LL * f[i] * P(i, (1 << n) - 1 - i) % mod * __builtin_popcount(i)) %
          mod;
  printf("%d\n", ans);
}
