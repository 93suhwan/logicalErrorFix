#include <bits/stdc++.h>
using namespace std;
const int N = 2005, p = 998244353;
int f[2][105][N], n, k, b[N], fac[N], inv[N], sum[2][105][N], L[N], R[N], R2[N];
int qp(int x, int y) {
  int ans = 1;
  while (y) {
    if (y & 1) ans = 1ll * ans * x % p;
    x = 1ll * x * x % p;
    y >>= 1;
  }
  return ans;
}
int C(int x, int y) {
  if (x < 0 || y < 0 || x < y) return 0;
  return 1ll * fac[x] * inv[y] % p * inv[x - y] % p;
}
signed main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i <= N - 5; i++) fac[i] = 1ll * fac[i - 1] * i % p;
  inv[N - 5] = qp(fac[N - 5], p - 2) % p;
  for (int i = N - 6; i >= 1; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % p;
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> b[i], L[i] = max(0, b[i] - k), R[i] = min(n, k + b[i]),
                 R2[i] = min(n, L[i] + 2 * k);
  int op = 0;
  f[0][0][0] = 1;
  for (int i = 0; i <= 2 * k; i++) sum[0][i][0] = 1;
  for (int i = 1; i <= n; i++) {
    op ^= 1;
    memset(sum[op], 0, sizeof sum[op]);
    memset(f[op], 0, sizeof f[op]);
    for (int x = L[i]; x <= R2[i]; x++)
      for (int j = x; j <= i; j++) {
        if (x <= R[i]) {
          if (x - L[i - 1] >= 0 && j)
            f[op][x - L[i]][j] =
                1ll * (j - x) * f[op ^ 1][min(2 * k, x - L[i - 1])][j - 1] % p;
          if (x - L[i - 1] >= 0)
            f[op][x - L[i]][j] =
                (f[op][x - L[i]][j] +
                 1ll * j * f[op ^ 1][min(2 * k, x - L[i - 1])][j] % p) %
                p;
          if (x - L[i - 1] - 1 >= 0 && j)
            f[op][x - L[i]][j] =
                (f[op][x - L[i]][j] +
                 sum[op ^ 1][min(2 * k, x - L[i - 1] - 1)][j - 1]) %
                p;
        }
        if (x - L[i])
          sum[op][x - L[i]][j] =
              (sum[op][x - L[i] - 1][j] + f[op][x - L[i]][j]) % p;
        else
          sum[op][x - L[i]][j] = f[op][x - L[i]][j];
      }
  }
  int ans = 0;
  for (int x = L[n]; x <= R[n]; x++)
    for (int j = x; j <= n; j++)
      ans = (ans + 1ll * C(n - x, j - x) * f[op][x - L[n]][j] % p) % p;
  cout << ans;
  return 0;
}
