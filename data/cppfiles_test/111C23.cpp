#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && (c != '-')) c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
const int N = 2e3 + 10, mod = 998244353;
int n, m, l[N], r[N], f[N][N], _f[N][N], g[N][N];
inline int Mod(int x) { return x >= mod ? x - mod : x; }
inline int power(int a, int b) {
  int ret = 1;
  for (; b; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) ret = 1ll * ret * a % mod;
  return ret;
}
int fac[N], ifac[N];
inline void init(int n) {
  fac[0] = 1;
  for (int i = (1); i <= (n); i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[n] = power(fac[n], mod - 2);
  for (int i = (n - 1); i >= (0); i--)
    ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
}
inline int C(int n, int m) {
  if (m < 0 || n < m) return 0;
  return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
int main() {
  n = read(), m = read(), init(n);
  for (int i = (1); i <= (n); i++) {
    int x = read();
    l[i] = max(0, x - m);
    r[i] = min(n, x + m);
  }
  f[0][0] = 1;
  for (int i = (0); i < (n); i++) {
    for (int j = (l[i]); j <= (r[i]); j++)
      for (int k = (0); k <= (i); k++)
        if (f[j][k]) {
          if (j >= l[i + 1] && j <= r[i + 1]) {
            _f[j][k] = (_f[j][k] + 1ll * f[j][k] * (j + k)) % mod;
            _f[j][k + 1] = Mod(_f[j][k + 1] + f[j][k]);
          }
          if (j < r[i + 1]) g[j + 1][k] = Mod(g[j + 1][k] + f[j][k]);
          f[j][k] = 0;
        }
    for (int j = (l[i]); j <= (r[i + 1]); j++) {
      if (j >= l[i + 1]) {
        for (int k = (0); k <= (i); k++) _f[j][k] = Mod(_f[j][k] + g[j][k]);
      }
      if (j < r[i + 1]) {
        for (int k = (1); k <= (i); k++)
          if (g[j][k])
            g[j + 1][k - 1] = (g[j + 1][k - 1] + 1ll * g[j][k] * k) % mod;
      }
      for (int k = (0); k <= (i); k++) g[j][k] = 0;
    }
    for (int j = (l[i + 1]); j <= (r[i + 1]); j++)
      for (int k = (0); k <= (i + 1); k++) f[j][k] = _f[j][k], _f[j][k] = 0;
  }
  int ans = 0;
  for (int j = (l[n]); j <= (r[n]); j++)
    for (int k = (0); k <= (n); k++)
      if (f[j][k])
        ans = (ans + 1ll * f[j][k] * C(n - j, k) % mod * fac[k]) % mod;
  printf("%d\n", ans);
}
