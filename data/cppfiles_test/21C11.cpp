#include <bits/stdc++.h>
using namespace std;
int n, m, k;
long long p, c[105][105], c2[105][105], f[105][105][105];
int main() {
  cin >> n >> m >> k >> p;
  for (int i = 0; i <= n; ++i) {
    c[i][0] = c[i][i] = 1 % p;
    for (int j = 1; j < i; ++j) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % p;
  }
  for (int i = 0; i <= n; ++i) {
    c2[i][0] = c2[i][i] = 2 % p;
    for (int j = 1; j < i; ++j)
      c2[i][j] = (c2[i - 1][j - 1] + c2[i - 1][j]) % p;
  }
  f[1][1][1] = 1;
  for (int i = 2; i <= n; ++i)
    f[i][1][1] = f[i - 1][1][1] * i % p, f[1][i][0] = 1;
  for (int _m = 1; _m < m; ++_m) {
    for (int x = 1; x < n; ++x) {
      int nm = _m + 1;
      for (int i = 0; i <= x; ++i) {
        if (!f[x][_m][i]) continue;
        for (int y = n - 1 - x, s = n; y; --y, --s) {
          for (int j = y; j >= 0; --j) {
            (f[s][nm][i + j] += f[x][_m][i] * f[y][_m][j] % p * c[x + y][x]) %=
                p;
          }
        }
        (f[x + 1][nm][i] += f[x][_m][i] * 2) %= p;
      }
    }
  }
  printf("%lld\n", (f[n][m][k] % p + p) % p);
  return 0;
}
