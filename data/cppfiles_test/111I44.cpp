#include <bits/stdc++.h>
using namespace std;
int n, k;
int b[2010];
long long f[2][2010][110];
long long sum[2][2010][110];
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
  for (register int i = 1; i <= n; i++) scanf("%d", &b[i]);
  fac[0] = 1;
  for (register int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % 998244353;
  inv[0] = 1;
  inv[n] = ksm(fac[n], 998244353 - 2);
  for (register int i = n - 1; i >= 1; i--)
    inv[i] = inv[i + 1] * (i + 1) % 998244353;
  f[0][0][k] = 1;
  int cur = 0;
  for (register int x = 0; x <= k; x++)
    sum[cur][0][x + k] = sum[cur][0][x + k - 1] + f[cur][0][x + k];
  for (register int i = 1; i <= n; i++) {
    cur ^= 1;
    memset(f[cur], 0, sizeof(f[cur]));
    memset(sum[cur][0], 0, sizeof(sum[cur][0]));
    for (register int x = max(-k, -b[i]); x <= min(k, n - b[i]); x++) {
      for (register int j = max(x + b[i] - 1, 1); j <= i; j++) {
        if (x + b[i] - b[i - 1] + k >= 0 && x + b[i] - b[i - 1] <= k) {
          f[cur][j][x + k] =
              j * f[cur ^ 1][j][x + b[i] - b[i - 1] + k] % 998244353;
          f[cur][j][x + k] += (j - (x + b[i])) *
                              f[cur ^ 1][j - 1][x + b[i] - b[i - 1] + k] %
                              998244353;
        }
        int maxx = max(-k, -b[i - 1]),
            minn = min(x + b[i] - 1 - b[i - 1], min(k, n - b[i - 1]));
        if (maxx <= minn) {
          f[cur][j][x + k] += sum[cur ^ 1][j - 1][minn + k];
          if (maxx + k >= 1)
            f[cur][j][x + k] -= sum[cur ^ 1][j - 1][maxx + k - 1];
        }
      }
    }
    for (register int j = 1; j <= i; j++) {
      sum[cur][j][0] = f[cur][j][0];
      for (register int x = -k + 1; x <= k; x++) {
        sum[cur][j][x + k] = sum[cur][j][x + k - 1] + f[cur][j][x + k];
      }
    }
  }
  long long ans = 0;
  for (int x = max(-k, -b[n]); x <= min(k, n - b[n]); x++) {
    for (int j = x + b[n]; j <= n; j++)
      ans += f[n % 2][j][x + k] % 998244353 *
             C(n - (x + b[n]), j - (x + b[n])) % 998244353;
  }
  printf("%lld\n", (ans % 998244353 + 998244353) % 998244353);
  return 0;
}
