#include <bits/stdc++.h>
using namespace std;
const int N = 108;
int n, m, _k;
long long mod, fac[N], c[N][N], f[N][N][N];
inline long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    s = (s << 3) + (s << 1) + ch - '0';
    ch = getchar();
  }
  return s * w;
}
int main() {
  n = read();
  m = read();
  _k = read();
  mod = read();
  fac[0] = c[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    fac[i] = (fac[i - 1] * i) % mod;
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
  }
  for (int i = 0; i <= n; ++i) f[0][i][0] = 1;
  for (int i = 1; i <= n; ++i) {
    f[i][1][1] = fac[i];
    for (int j = i + 1; j <= n; ++j) f[i][j][0] = fac[i];
    for (int j = 2; j <= min(i, m); ++j) {
      for (int k = 0; k <= min(_k, i - j + 1); ++k) {
        int lim = k - (j == 1);
        f[i][j][k] += f[i - 1][j - 1][lim] * 2;
        for (int pos = 2; pos < i; ++pos)
          for (int l = 0; l <= lim; ++l) {
            if (f[pos - 1][j - 1][l] && f[i - pos][j - 1][lim - l]) {
              f[i][j][k] +=
                  (f[pos - 1][j - 1][l] * f[i - pos][j - 1][lim - l] % mod) *
                  c[i - 1][pos - 1] % mod;
            }
          }
        f[i][j][k] %= mod;
      }
    }
  }
  printf("%lld\n", f[n][m][_k]);
  return 0;
}
