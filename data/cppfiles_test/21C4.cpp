#include <bits/stdc++.h>
using namespace std;
template <typename _T>
inline void read(_T &x) {
  x = 0;
  long long f = 1;
  char s = getchar();
  while (s < '0' || s > '9') {
    f = 1;
    if (s == '-') f = -1;
    s = getchar();
  }
  while ('0' <= s && s <= '9') {
    x = (x << 3) + (x << 1) + s - '0';
    s = getchar();
  }
  x *= f;
}
long long n, m, k, p;
long long dp[233][233][233];
long long c[233][233], k_;
long long fac[23333];
signed main() {
  read(n), read(m), read(k_), read(p);
  const long long mod = p;
  c[0][0] = 1;
  fac[0] = 1;
  for (long long i = 1; i <= 100; i++) fac[i] = fac[i - 1] * i, fac[i] %= mod;
  for (long long i = 1; i <= 100; i++) {
    c[i][0] = 1;
    for (long long j = 1; j <= i; j++)
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j], c[i][j] %= mod;
  }
  for (long long i = 0; i <= n; i++) dp[0][i][0] = 1;
  for (long long i = 1; i <= n; i++) dp[i][1][1] = fac[i];
  for (long long i = 1; i <= n; i++)
    for (long long j = i + 1; j <= n; j++) dp[i][j][0] = fac[i];
  for (register long long i = 2; i <= n; i++) {
    for (register long long j = 1; j <= m && j <= i; j++) {
      for (register long long k = 0; k <= i - j + 1 && k <= k_; k++) {
        register long long tmp = dp[i][j][k];
        for (register long long a = 0; a <= i - 1; a++) {
          register long long tmp_ = 0;
          for (register long long b = 0; b <= k; b++) {
            if (dp[a][j - 1][b] && dp[i - 1 - a][j - 1][k - b - (j == 1)]) {
              tmp_ +=
                  ((dp[a][j - 1][b] * dp[i - 1 - a][j - 1][k - b - (j == 1)]) %
                   mod);
              tmp_ -= tmp_ >= mod ? mod : 0;
            }
          }
          tmp_ *= c[i - 1][a];
          tmp_ %= mod;
          tmp += tmp_;
          tmp -= tmp >= mod ? mod : 0;
        }
        dp[i][j][k] = tmp;
      }
    }
  }
  printf("%lld", dp[n][m][k_]);
}
