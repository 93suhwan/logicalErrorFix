#include <bits/stdc++.h>
const int N = 205;
int MOD;
inline int mval(int x) { return x >= MOD ? x - MOD : x; }
inline void inc(int &x, int a) { x = mval(x + a); }
int n, fac[N], inv[N], f[N][N][N], ans;
int main() {
  scanf("%d%d", &n, &MOD);
  fac[0] = inv[0] = inv[1] = 1;
  for (int i = 2; i <= n; ++i)
    inv[i] = MOD - 1ll * (MOD / i) * inv[MOD % i] % MOD;
  for (int i = 1; i <= n; ++i)
    fac[i] = 1ll * i * fac[i - 1] % MOD,
    inv[i] = 1ll * inv[i - 1] * inv[i] % MOD;
  f[n + 2][0][0] = 1;
  for (int i = n + 1; i; --i) {
    for (int j = 0; j < n; ++j)
      for (int s = 0; s <= n; ++s)
        if (f[i + 1][j][s]) {
          int val = f[i + 1][j][s];
          for (int t = 0; t + j <= n && s + t + j <= n; ++t)
            if (t + j >= n + 2 - i) {
              inc(f[i][j + t][s + t + j], 1ll * val * inv[t] % MOD);
            }
          if (s <= i) {
            inc(ans, 1ll * inv[n - j] * val % MOD);
          }
          if (j + i - 1 == n && i > 1 && s + j <= i - 1) {
            inc(ans, 1ll * inv[n - j] * val % MOD);
          }
        }
  }
  printf("%d\n", (1ll * ans * fac[n]) % MOD);
  return 0;
}
