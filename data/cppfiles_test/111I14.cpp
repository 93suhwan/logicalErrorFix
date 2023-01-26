#include <bits/stdc++.h>
using namespace std;
const int N = 2005, mod = 998244353;
int ksm(int a, int b) {
  int c = 1;
  while (b) {
    if (b & 1) c = 1ll * c * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return c;
}
int a[N], n, K, sum[N][N], f[2][N][N], fac[N], inv[N];
int main() {
  scanf("%d%d", &n, &K);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int _ = 0;
  if (max(0, a[1] - K) <= 1 && min(n, a[1] + K) >= 1)
    f[_ ^ 1][1][0] = 1, sum[1][1] = 1;
  if (max(0, a[1] - K) <= 0 && min(n, a[1] + K) >= 0)
    f[_ ^ 1][0][1] = 1, sum[1][0] = 1;
  for (int i = 1; i <= n; i++) sum[1][i] += sum[1][i - 1];
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; i++)
    fac[i] = 1ll * fac[i - 1] * i % mod, inv[i] = ksm(fac[i], mod - 2);
  for (int i = 2; i <= n; i++, _ ^= 1) {
    for (int j = max(0, a[i] - K); j <= min(n, a[i] + K); j++) {
      for (int k = 0; j + k - 1 <= n; k++) {
        (f[_][j][k] += 1ll * f[_ ^ 1][j][k] * (j + k) % mod) %= mod;
        (f[_][j][k + 1] += f[_ ^ 1][j][k]) % mod;
        if (j)
          (f[_][j][k] += 1ll *
                         sum[j - 1 + k][min(j - 1, min(n, a[i - 1] + K))] *
                         inv[k] % mod) %= mod;
      }
    }
    for (int j = max(0, a[i - 1] - K); j <= min(n, a[i - 1] + K); j++)
      for (int k = 0; j + k <= n; k++) f[_ ^ 1][j][k] = 0, sum[j + k][k] = 0;
    for (int k = n; k >= 0; k--)
      for (int j = max(0, a[i] - K); j <= min(n, a[i] + K); j++)
        sum[k][j] = (sum[k][j - 1] +
                     (k >= j ? 1ll * f[_][j][k - j] * fac[k - j] % mod : 0)) %
                    mod;
  }
  _ ^= 1;
  int ans = 0;
  for (int j = 0; j <= n; j++)
    for (int k = 0; k + j <= n; k++)
      (ans += 1ll * f[_][j][k] * fac[n - j] % mod * inv[n - j - k] % mod) %=
          mod;
  printf("%d", ans);
  return 0;
}
