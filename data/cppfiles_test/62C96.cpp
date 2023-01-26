#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 9;
const long long MOD = 1e9 + 7;
const int mod = 998244353;
inline long long qpow(long long b, long long e, long long m) {
  long long a = 1;
  for (; e; e >>= 1, b = b * b % m)
    if (e & 1) a = a * b % m;
  return a;
}
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  long long d = exgcd(b, a % b, x, y);
  long long z = x;
  x = y, y = z - y * (a / b);
  return d;
}
long long dp[1009][1009][3];
bool a[1009][1009];
int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j][0] = 1, dp[i][j][1] = 1;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j][0] += dp[i - 1][j][1];
      dp[i][j][1] += dp[i][j - 1][0];
      ans += dp[i][j][0] + dp[i][j][1];
    }
  }
  ans -= n * m;
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[x][y] ^= 1;
    if (a[x][y] == 1) {
      int i = x, j = y, num = 0;
      long long tm = dp[i][j][0];
      while (i <= n && j <= m) {
        if (num % 2 == 0)
          dp[i][j][0] -= tm, j++;
        else
          dp[i][j][1] -= tm, i++;
        ans -= tm;
        num++;
        if (a[i][j] == 1) break;
      }
      i = x, j = y, num = 0;
      tm = dp[i][j][1];
      while (i <= n && j <= m) {
        if (num % 2 == 0)
          dp[i][j][1] -= tm, i++;
        else
          dp[i][j][0] -= tm, j++;
        ans -= tm;
        num++;
        if (a[i][j] == 1) break;
      }
      ans++;
    } else {
      dp[x][y][0] = dp[x - 1][y][1] + 1;
      dp[x][y][1] = dp[x][y - 1][0] + 1;
      int i = x, j = y, num = 1;
      long long tm = dp[x][y][0];
      j++;
      ans += dp[x][y][0];
      while (i <= n && j <= m && a[i][j] == 0) {
        if (num % 2 == 0)
          dp[i][j][0] += tm, j++;
        else
          dp[i][j][1] += tm, i++;
        ans += tm;
        num++;
      }
      i = x, j = y, num = 1;
      tm = dp[x][y][1];
      ans += tm;
      i++;
      while (i <= n && j <= m && a[i][j] == 0) {
        if (num % 2 == 0)
          dp[i][j][1] += tm, i++;
        else
          dp[i][j][0] += tm, j++;
        ans += tm;
        num++;
      }
      ans--;
    }
    printf("%lld\n", ans);
  }
}
