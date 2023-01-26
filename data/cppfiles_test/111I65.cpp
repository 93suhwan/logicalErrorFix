#include <bits/stdc++.h>
using namespace std;
int n, k;
int b[210];
long long f[210][210][210];
long long g[210][210];
long long fac[210], inv[210];
long long ksm(long long x, int y) {
  long long ans = 1;
  while (y > 0) {
    if (y & 1) ans = ans * x % 998244353;
    y >>= 1;
    x = x * x % 998244353;
  }
  return ans;
}
long long C(int n, int m) {
  return fac[n] * inv[n - m] % 998244353 * inv[m] % 998244353;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % 998244353;
  inv[0] = 1;
  inv[n] = ksm(fac[n], 998244353 - 2);
  for (int i = n - 1; i >= 1; i--) inv[i] = inv[i + 1] * (i + 1) % 998244353;
  f[0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int x = max(b[i] - k, 0); x <= min(b[i] + k, n); x++) {
      for (int j = max(x - 1, 1); j <= i; j++) {
        f[i][x][j] = j * f[i - 1][x][j] % 998244353;
        f[i][x][j] += (j - x) * f[i - 1][x][j - 1] % 998244353;
        f[i][x][j] %= 998244353;
        for (int y = max(b[i - 1] - k, 0);
             y <= min(min(b[i - 1] + k, n - b[i - 1]), x - 1); y++) {
          f[i][x][j] += f[i - 1][y][j - 1];
          f[i][x][j] %= 998244353;
        }
      }
    }
  }
  long long ans = 0;
  for (int x = max(b[n] - k, 0); x <= min(b[n] + k, n); x++) {
    for (int j = x; j <= n; j++) {
      ans += f[n][x][j] * C(n - x, j - x) % 998244353;
      ans %= 998244353;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
