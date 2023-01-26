#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2010, K = 60, p = 998244353;
inline int red(const int x) { return x >= p ? x - p : x; }
int f[2][K << 1][N], g[K << 1][N], n, k, b[N], fac[N], ifac[N], inv[N];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
  inv[1] = 1;
  for (int i = 2; i < N; ++i) inv[i] = 1ll * (p - p / i) * inv[p % i] % p;
  fac[0] = ifac[0] = 1;
  for (int i = 1; i < N; ++i)
    fac[i] = 1ll * fac[i - 1] * i % p, ifac[i] = 1ll * ifac[i - 1] * inv[i] % p;
  f[0][k][0] = 1;
  for (int i = k; i <= (k << 1); ++i) g[i][0] = 1;
  for (int i = 1; i <= n; ++i) {
    memset(f[i & 1], 0, sizeof(f[i & 1]));
    auto lf = [&](int j, int t) {
      if (j < b[i - 1] - k || j > b[i - 1] + k || t < 0) return 0;
      return f[i & 1 ^ 1][j - b[i - 1] + k][t];
    };
    auto lg = [&](int j, int sm) {
      if (sm < 0) return 0;
      if (j < b[i - 1] - k) return 0;
      if (j >= b[i - 1] + k) return g[(k << 1)][sm];
      return g[j - b[i - 1] + k][sm];
    };
    for (int j = b[i] - k; j <= b[i] + k; ++j) {
      if (j < 0) continue;
      for (int t = 0; t + j <= i; ++t) {
        int &dp = f[i & 1][j - (b[i] - k)][t];
        dp = red(lf(j - 1, t));
        dp = red(dp + red(1ll * lf(j, t) * (j + t) % p + lf(j, t - 1)));
        dp = red(dp + 1ll * lg(j - 2, t + j - 1) * ifac[t] % p);
      }
    }
    memset(g, 0, sizeof(g));
    for (int j = b[i] - k; j <= b[i] + k; ++j) {
      if (j < 0) continue;
      for (int t = 0; t + j <= i; ++t) {
        g[j - b[i] + k][j + t] = 1ll * fac[t] * f[i & 1][j - b[i] + k][t] % p;
      }
    }
    for (int t = 0; t <= i; ++t)
      for (int j = 1; j <= (k << 1); ++j) g[j][t] = red(g[j][t] + g[j - 1][t]);
  }
  int ans = 0;
  for (int j = b[n] - k; j <= b[n] + k; ++j)
    if (j >= 0) {
      for (int t = 0; t + j <= n; ++t) {
        ans = red(ans + 1ll * f[n & 1][j - b[n] + k][t] * fac[n - j] % p *
                            ifac[n - t - j] % p) %
              p;
      }
    }
  printf("%d\n", ans);
  return 0;
}
