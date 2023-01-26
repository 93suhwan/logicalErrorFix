#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int n, mod, fac[N], ifac[N];
inline void inc(int& x, int y) { x = x + y >= mod ? x + y - mod : x + y; }
inline int qpow(int x, int y) {
  int res = 1;
  for (; y; y >>= 1, x = 1ll * x * x % mod)
    (y & 1) && (res = 1ll * res * x % mod);
  return res;
}
inline void pre() {
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[n] = qpow(fac[n], mod - 2);
  for (int i = n - 1; ~i; --i) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
}
int f[N][N][30], ans;
inline void work(int a1) {
  memset(f, 0, sizeof f);
  int mx = n + 1 - a1;
  f[0][0][0] = 1;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j <= a1; ++j)
      for (int k = 0; k <= mx; ++k) {
        int& d = f[i][j][k];
        if (!d) continue;
        for (int ct = 1; ct <= n - i; ++ct) {
          if (i + ct > k + a1) break;
          if (i + ct == k + a1 && i) break;
          if (i + ct > a1 && k + a1 < i + ct + 1) break;
          int sum = j + ct * k;
          if (i + ct == n) {
            inc(ans, 1ll * d * ifac[ct] % mod);
            break;
          }
          for (int t = k + 1; t <= mx && sum + (n - ct - i) * t <= a1; ++t)
            inc(f[i + ct][sum][t], 1ll * d * ifac[ct] % mod);
        }
      }
}
int main() {
  scanf("%d%d", &n, &mod);
  pre();
  for (int i = max(1, n - (int)(sqrt(2 * n + 0.01))); i <= n + 1; ++i) work(i);
  ans = 1ll * ans * fac[n] % mod;
  printf("%d\n", ans);
  return 0;
}
