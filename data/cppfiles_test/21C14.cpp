#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
long long n, m, k, mod, d[105][105][105], c[105][105];
int main() {
  cin >> n >> m >> k >> mod;
  for (long long i = 0; i <= 100; i++) {
    c[i][0] = c[i][i] = 1;
    for (long long j = 1; j < i; j++) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
  }
  for (long long i = 0; i <= m; i++) {
    d[0][i][0] = 1;
  }
  for (long long i = 1; i <= n; i++) {
    d[i][1][1] = (d[i - 1][1][1] * i) % mod;
    if (i == 1) d[i][1][1] = 1;
  }
  for (long long i = 1; i < m; i++) {
    for (long long l = 0; l < n; l++) {
      for (long long x = 0; x <= l; x++) {
        if (d[l][i][x]) {
          for (long long r = 0; l + r < n; r++) {
            for (long long y = 0; y <= r; y++) {
              if (d[r][i][y]) {
                d[l + r + 1][i + 1][x + y] +=
                    c[l + r][l] % mod * d[l][i][x] % mod * d[r][i][y] % mod;
                d[l + r + 1][i + 1][x + y] %= mod;
              }
            }
          }
        }
      }
    }
  }
  cout << d[n][m][k] << endl;
}
