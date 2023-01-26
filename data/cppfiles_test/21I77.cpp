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
    for (register long long j = min(i, m); j; j--) {
      for (register long long k = 0; k <= min(i, k_); k++) {
        register long long tmp = dp[i][j][k];
        for (register long long a = 0; a <= i - 1; a++) {
          register long long tmp_ = 0, b = 0;
          register long long tmp0(0), tmp1(0), tmp2(0), tmp3(0), tmp4(0),
              tmp5(0), tmp6(0), tmp7(0);
          for (; b + 8 <= k; b += 8) {
            tmp0 +=
                ((dp[a][j - 1][b] * dp[i - 1 - a][j - 1][k - b - (j == 1)]) %
                 mod);
            tmp0 -= tmp0 >= mod ? mod : 0;
            tmp1 += ((dp[a][j - 1][b + 1] *
                      dp[i - 1 - a][j - 1][k - (b + 1) - (j == 1)]) %
                     mod);
            tmp1 -= tmp1 >= mod ? mod : 0;
            tmp2 += ((dp[a][j - 1][b + 2] *
                      dp[i - 1 - a][j - 1][k - (b + 2) - (j == 1)]) %
                     mod);
            tmp2 -= tmp2 >= mod ? mod : 0;
            tmp3 += ((dp[a][j - 1][b + 3] *
                      dp[i - 1 - a][j - 1][k - (b + 3) - (j == 1)]) %
                     mod);
            tmp3 -= tmp3 >= mod ? mod : 0;
            tmp4 += ((dp[a][j - 1][b + 4] *
                      dp[i - 1 - a][j - 1][k - (b + 4) - (j == 1)]) %
                     mod);
            tmp4 -= tmp4 >= mod ? mod : 0;
            tmp5 += ((dp[a][j - 1][b + 5] *
                      dp[i - 1 - a][j - 1][k - (b + 5) - (j == 1)]) %
                     mod);
            tmp5 -= tmp5 >= mod ? mod : 0;
            tmp6 += ((dp[a][j - 1][b + 6] *
                      dp[i - 1 - a][j - 1][k - (b + 6) - (j == 1)]) %
                     mod);
            tmp6 -= tmp6 >= mod ? mod : 0;
            tmp7 += ((dp[a][j - 1][b + 7] *
                      dp[i - 1 - a][j - 1][k - (b + 7) - (j == 1)]) %
                     mod);
            tmp7 -= tmp7 >= mod ? mod : 0;
          }
          for (; b <= k; b++)
            tmp_ +=
                ((dp[a][j - 1][b] * dp[i - 1 - a][j - 1][k - b - (j == 1)]) %
                 mod);
          tmp_ += tmp0 + tmp1 + tmp2 + tmp3 + tmp4 + tmp5 + tmp6 + tmp7;
          tmp_ %= mod;
          tmp_ *= c[i - 1][a];
          tmp_ %= mod;
          tmp += tmp_;
          tmp -= tmp >= mod ? mod : 0;
        }
        dp[i][j][k] = tmp;
        if (!dp[i][j][k] && k != 0) break;
      }
    }
  }
  printf("%lld", dp[n][m][k_]);
}
