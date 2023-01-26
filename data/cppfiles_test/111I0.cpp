#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int b[N], n, k;
int f[2][105][N], g[2][105][N];
long long jc[N * 2], inv[N * 2];
int main() {
  scanf("%d %d", &n, &k);
  for (int i = (1), e_ = (n); i <= e_; i++) scanf("%d", &b[i]), b[i] -= k;
  k += k;
  jc[0] = inv[0] = jc[1] = inv[1] = 1;
  for (int i = (2), e_ = (n + n + 2); i <= e_; i++)
    jc[i] = jc[i - 1] * i % 998244353,
    inv[i] = inv[998244353 % i] * (998244353 - 998244353 / i) % 998244353;
  for (int i = (2), e_ = (n + n + 2); i <= e_; i++)
    inv[i] = inv[i - 1] * inv[i] % 998244353;
  long long ans = 0;
  f[0][0][0] = 1;
  for (int i = (0), e_ = (n); i <= e_; i++) {
    int u = (i & 1), v = u ^ 1;
    for (int j = (0), e_ = (k + 1); j <= e_; j++)
      memset(f[v][j], 0, sizeof(f[v][j][0]) * (i + 2)),
          memset(g[v][j], 0, sizeof(g[v][j]) * (i + 2));
    for (int j = (0), e_ = (k); j <= e_; j++)
      for (int t = (0), e_ = (i); t <= e_; t++)
        if (g[u][j][t]) {
          ((f[u][j][t] += g[u][j][t]) &&
           (f[u][j][t] -= (f[u][j][t] >= 998244353) ? 998244353 : 0));
          if (t && j < k)
            (g[u][j + 1][t - 1] =
                 ((1ll * g[u][j][t] * t) + (g[u][j + 1][t - 1])) % 998244353);
        }
    for (int j = (0), e_ = (k); j <= e_; j++)
      for (int t = (0), e_ = (i); t <= e_; t++)
        if (f[u][j][t]) {
          if (i == n) {
            int d = n - b[i] - j;
            if (d >= t)
              (ans = ((1ll * f[u][j][t] * jc[d] % 998244353 * inv[d - t]) +
                      (ans)) %
                     998244353);
            continue;
          }
          int x = j - (b[i + 1] - b[i]);
          if (x > k) continue;
          if (x >= 0)
            (f[v][x][t] = ((1ll * f[u][j][t] * (b[i] + j + t)) + (f[v][x][t])) %
                          998244353),
                (f[v][x][t + 1] =
                     ((f[u][j][t]) + (f[v][x][t + 1])) % 998244353);
          if (x < -1) {
            int d = b[i + 1] - (b[i] + j) - 1;
            if (t >= d)
              (g[v][0][t - d] =
                   ((1ll * f[u][j][t] * jc[t] % 998244353 * inv[t - d]) +
                    (g[v][0][t - d])) %
                   998244353);
          } else
            ((g[v][x + 1][t] += f[u][j][t]) &&
             (g[v][x + 1][t] -= (g[v][x + 1][t] >= 998244353) ? 998244353 : 0));
        }
  }
  printf("%lld", ans);
  return 0;
}
