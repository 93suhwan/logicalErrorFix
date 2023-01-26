#include <bits/stdc++.h>
using namespace std;
inline long long readint() {
  long long x = 0;
  bool f = 0;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') {
    f = 1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return f ? -x : x;
}
const int maxn = 2e3 + 5, maxm = 50 + 5;
int n, m, b[maxn];
const long long mod = 998244353;
long long ksm(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b % 2 == 1) ans = ans * a % mod;
    a = a * a % mod;
    b /= 2;
  }
  return ans;
}
inline void add(long long& x, long long y) { x = (x + y) % mod; }
long long fac[maxn], ifac[maxn], f[2][maxn][maxm * 2];
int main() {
  n = readint();
  m = readint();
  for (int i = 1; i <= n; i++) b[i] = readint();
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
  ifac[n] = ksm(fac[n], mod - 2);
  for (int i = n - 1; i >= 0; i--) ifac[i] = ifac[i + 1] * (i + 1) % mod;
  f[0][m][0] = 1;
  for (int i = 1; i <= n; i++) {
    memset(f[i % 2], 0, sizeof(f[0]));
    for (int j = max(b[i - 1] - m, 0); j <= min(b[i - 1] + m, n); j++)
      for (int k = 0; k <= n - j - 1; k++) {
        int l = max(b[i] - m, j + 1), r = min(b[i] + m, min(k + j + 1, n));
        if (l > r) continue;
        long long res = f[(i - 1) % 2][j - b[i - 1] + m][k];
        add(f[i % 2][l - b[i] + m][k - l + j + 1], res * fac[k] % mod);
        add(f[i % 2][r - b[i] + m + 1][k - r + j],
            (mod - res * fac[k] % mod) % mod);
      }
    for (int j = max(b[i] - m, 0) + 1; j <= min(b[i] + m, n); j++)
      for (int k = 0; k <= n - j; k++)
        add(f[i % 2][j - b[i] + m][k], f[i % 2][j - 1 - b[i] + m][k + 1]);
    for (int j = max(b[i] - m, 0) + 1; j <= min(b[i] + m, n); j++)
      for (int k = 0; k <= n - j; k++)
        f[i % 2][j - b[i] + m][k] = f[i % 2][j - b[i] + m][k] * ifac[k] % mod;
    for (int j = max(b[i - 1] - m, 0); j <= min(b[i - 1] + m, n); j++)
      for (int k = 0; k <= n - j; k++)
        if (abs(j - b[i]) <= m) {
          long long res = f[(i - 1) % 2][j - b[i - 1] + m][k];
          add(f[i % 2][j - b[i] + m][k], res * (j + k) % mod);
          if (k < n) add(f[i % 2][j - b[i] + m][k + 1], res);
        }
  }
  long long ans = 0;
  for (int i = max(b[n] - m, 0); i <= min(b[n] + m, n); i++)
    for (int j = 0; j <= n - i; j++)
      add(ans,
          f[n % 2][i - b[n] + m][j] * fac[n - i] % mod * ifac[n - i - j] % mod);
  printf("%lld\n", ans);
  return 0;
}
