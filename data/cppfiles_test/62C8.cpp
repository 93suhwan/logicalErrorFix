#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
long long read() {
  long long s = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return s * f;
}
long long a[1010][1010];
long long dp[1010][1010][2];
signed main() {
  long long T = 1;
  while (T--) {
    long long n = read(), m = read(), q = read();
    for (long long i = 1, iend = n; i <= iend; ++i) {
      for (long long j = 1, jend = m; j <= jend; ++j) {
        a[i][j] = 1;
      }
    }
    long long ans = 0;
    for (long long i = 1, iend = n; i <= iend; ++i) {
      for (long long j = 1, jend = m; j <= jend; ++j) {
        dp[i][j][0] = dp[i][j][1] = 1;
        dp[i][j][0] += dp[i - 1][j][1];
        dp[i][j][1] += dp[i][j - 1][0];
        ans += dp[i][j][0] + dp[i][j][1] - 1;
      }
    }
    while (q--) {
      long long x = read(), y = read();
      long long nx = x, ny = y;
      long long lf = 0;
      while (1) {
        if (lf % 2 == 0) {
          --nx;
          if (a[nx][ny] == 0) break;
          lf++;
        } else {
          --ny;
          if (a[nx][ny] == 0) break;
          lf++;
        }
      }
      long long rf = 0;
      nx = x, ny = y;
      while (1) {
        if (rf % 2 == 1) {
          ++nx;
          if (a[nx][ny] == 0) break;
          rf++;
        } else {
          ++ny;
          if (a[nx][ny] == 0) break;
          rf++;
        }
      }
      long long sum1 = (rf + 1) * (lf + 1);
      nx = x, ny = y;
      lf = 0;
      while (1) {
        if (lf % 2 == 1) {
          --nx;
          if (a[nx][ny] == 0) break;
          lf++;
        } else {
          --ny;
          if (a[nx][ny] == 0) break;
          lf++;
        }
      }
      rf = 0;
      nx = x, ny = y;
      while (1) {
        if (rf % 2 == 0) {
          ++nx;
          if (a[nx][ny] == 0) break;
          rf++;
        } else {
          ++ny;
          if (a[nx][ny] == 0) break;
          rf++;
        }
      }
      long long sum2 = (rf + 1) * (lf + 1);
      a[x][y] = 1 - a[x][y];
      sum1 += sum2;
      sum1--;
      if (a[x][y] == 1)
        ans += sum1;
      else
        ans -= sum1;
      cout << ans << '\n';
    }
  }
}
