#include <bits/stdc++.h>
using namespace std;
const long long N = 1e2 + 1e1 + 7;
long long n, m, k, P;
long long f[N][N][N], C[N][N];
signed main() {
  scanf("%lld%lld%lld%lld", &n, &m, &k, &P);
  C[0][0] = 1;
  for (long long i = 1; i <= n; i++) {
    C[i][0] = 1;
    for (long long j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
  }
  for (long long i = 0; i <= n + 1; i++) f[0][0][i] = 1;
  for (long long i = 1; i <= n; i++)
    for (long long j = 0; j <= min(i, k); j++)
      for (long long t = 1; t <= n - m; t++) {
        for (long long p = 1; p <= i; p++) {
          long long l = p - 1, r = i - p;
          for (long long lj = 0; lj <= j - (t == m); lj++) {
            long long rj = j - (t == m) - lj;
            f[i][j][t] = (f[i][j][t] + C[i - 1][l] * f[l][lj][t + 1] % P *
                                           f[r][rj][t + 1] % P) %
                         P;
          }
        }
      }
  printf("%lld\n", f[n][k][1]);
}
