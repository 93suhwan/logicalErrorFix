#include <bits/stdc++.h>
using namespace std;
int n, k;
int b[2010];
long long f[2][110][2010];
long long fac[2010], inv[2010];
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
  f[0][k][0] = 1;
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    cur ^= 1;
    memset(f[cur], 0, sizeof(f[cur]));
    for (int x = max(-k, -b[i]); x <= min(k, n - b[i]); x++) {
      for (int j = max(x + b[i] - 1, 1); j <= i; j++) {
        f[cur][x + k][j] =
            j * f[cur ^ 1][x + b[i] - b[i - 1] + k][j] % 998244353;
        f[cur][x + k][j] += (j - (x + b[i])) *
                            f[cur ^ 1][x + b[i] - b[i - 1] + k][j - 1] %
                            998244353;
        f[cur][x + k][j] %= 998244353;
        for (int y = max(-k, -b[i - 1]);
             y <= min(x + b[i] - 1 - b[i - 1], min(k, n - b[i - 1])); y++) {
          f[cur][x + k][j] += f[cur ^ 1][y + k][j - 1];
          f[cur][x + k][j] %= 998244353;
        }
      }
    }
  }
  long long ans = 0;
  for (int x = max(-k, -b[n]); x <= min(k, n - b[n]); x++) {
    for (int j = x + b[n]; j <= n; j++) {
      ans += f[n % 2][x + k][j] * C(n - (x + b[n]), j - (x + b[n])) % 998244353;
      ans %= 998244353;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
