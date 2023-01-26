#include <bits/stdc++.h>
using namespace std;
int n, m, ans, fac[2005], inv[2005], a[2005], l[2005], r[2005],
    f[2][2005][2005];
int C(int n, int m) {
  if (n < m) return 0;
  return (long long)fac[n] * inv[m] % 998244353 * inv[n - m] % 998244353;
}
int main() {
  fac[0] = inv[0] = inv[1] = 1;
  for (int i = 1; i < 2005; i++) fac[i] = (long long)fac[i - 1] * i % 998244353;
  for (int i = 2; i < 2005; i++)
    inv[i] =
        (long long)(998244353 - 998244353 / i) * inv[998244353 % i] % 998244353;
  for (int i = 1; i < 2005; i++)
    inv[i] = (long long)inv[i - 1] * inv[i] % 998244353;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    l[i] = max(a[i] - m, 0), r[i] = min(a[i] + m, i);
  }
  f[0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    int p = (i & 1);
    for (int j = max(l[i], 1); j <= r[i]; j++)
      for (int k = 0; k <= i - j; k++)
        f[p][j][k] = (f[p][j - 1][k + 1] + f[p ^ 1][j - 1][k]) % 998244353;
    for (int j = l[i - 1]; j <= r[i - 1]; j++)
      for (int k = 0; k < i - j; k++)
        if ((l[i] <= j) && (j <= r[i])) {
          f[p][j][k] =
              (f[p][j][k] + (long long)(j + k) * f[p ^ 1][j][k]) % 998244353;
          f[p][j][k + 1] =
              (f[p][j][k + 1] + (long long)(k + 1) * f[p ^ 1][j][k]) %
              998244353;
        }
    for (int j = l[i - 1]; j <= r[i - 1]; j++)
      for (int k = 0; k < i - j; k++) f[p ^ 1][j][k] = 0;
  }
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n - i; j++)
      ans = (ans + (long long)C(n - i, j) * f[n & 1][i][j]) % 998244353;
  printf("%d\n", ans);
  return 0;
}
