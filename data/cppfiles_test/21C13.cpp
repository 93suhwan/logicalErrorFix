#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize(2)
#pragma GCC optimize(3)
inline int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
inline long long llread() {
  long long x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
long long fact[110], c[110][110];
long long f[110][110][110];
long long n, m, k, P;
signed main() {
  n = llread(), m = llread(), k = llread(), P = llread();
  c[0][0] = fact[0] = 1;
  for (long long i = (1); i <= (n); i++) {
    c[i][0] = c[i][i] = 1;
    for (long long j = (1); j <= (i - 1); j++)
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % P;
  }
  for (long long i = (1); i <= (n); i++) fact[i] = (fact[i - 1] * i) % P;
  for (long long i = (0); i <= (n); i++) f[0][i][0] = 1;
  for (long long i = (1); i <= (n); i++) {
    f[i][1][1] = fact[i];
    for (long long j = (i + 1); j <= (n); j++) f[i][j][0] = fact[i];
    for (long long j = (2); j <= (min(i, m)); j++) {
      for (long long p = (0); p <= (min(i - j + 1, k)); p++) {
        f[i][j][p] = (f[i][j][p] + (f[i - 1][j - 1][p - (j == 1)] * 2)) % P;
        for (long long q = (2); q <= (i - 1); q++) {
          for (long long w = (0); w <= (p - (j == 1)); w++) {
            if (f[q - 1][j - 1][w] && f[i - q][j - 1][p - (j == 1) - w]) {
              f[i][j][p] = (f[i][j][p] + f[q - 1][j - 1][w] *
                                             f[i - q][j - 1][p - (j == 1) - w] %
                                             P * c[i - 1][q - 1]) %
                           P;
            }
          }
        }
      }
    }
  }
  printf("%lld\n", f[n][m][k]);
  return 0;
}
