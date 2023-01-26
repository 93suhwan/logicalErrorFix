#include <bits/stdc++.h>
using namespace std;
const int N = 2005, K = 55, mod = 998244353;
int n, k, b[N], f[2 * K][N], g[2 * K][N], C[N][N];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  f[k][0] = 1;
  for (int i = 1; i <= n; i++) {
    memset(g, 0, sizeof(g));
    for (int j = max(0, k - b[i - 1]); j <= 2 * k; j++) {
      int j2 = j + b[i - 1] - b[i] + 1, x = j + b[i - 1] - k;
      if (x < 0 || x > n || j2 > 2 * k) continue;
      for (int d = max(0, -j2); d < i; d++) {
        if (j2 < 0)
          (g[0][d + j2] += f[j][d]) %= mod;
        else
          (g[j2][d] += f[j][d]) %= mod;
      }
    }
    for (int j = 0; j < 2 * k; j++)
      for (int d = 1; d <= i; d++) (g[j + 1][d - 1] += g[j][d]) %= mod;
    for (int j = max(0, k - b[i - 1]); j <= 2 * k; j++) {
      int j2 = j + b[i - 1] - b[i], x = j + b[i - 1] - k;
      if (x < 0 || x > n || j2 < 0 || j2 > 2 * k) continue;
      for (int d = 0; d < i; d++) {
        (g[j2][d] += 1ll * f[j][d] * (d + x) % mod) %= mod;
        (g[j2][d + 1] += 1ll * f[j][d] * (d + 1) % mod) %= mod;
      }
    }
    swap(f, g);
  }
  C[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < n; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
  }
  int ans = 0;
  for (int j = 0; j <= 2 * k; j++) {
    int x = b[n] + j - k;
    if (x < 0 || x > n) continue;
    for (int d = 0; d <= n - x; d++)
      (ans += 1ll * f[j][d] * C[n - x][d] % mod) %= mod;
  }
  printf("%d\n", ans);
  return 0;
}
