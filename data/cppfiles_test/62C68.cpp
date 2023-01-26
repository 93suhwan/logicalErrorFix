#include <bits/stdc++.h>
using namespace std;
const long long N = 1005;
long long n, m, q;
bool a[N][N];
long long dp1[N][N];
long long dp2[N][N];
long long dp[N][N];
long long ans = 0;
void init() {
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) dp1[i][j] = dp2[i][j] = 1;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) {
      dp1[i][j] += dp2[i][j - 1];
      dp2[i][j] += dp1[i - 1][j];
      dp[i][j] = dp1[i][j] + dp2[i][j] - 1;
      ans += dp[i][j];
    }
}
void fun(long long i, long long j) {
  ans -= dp[i][j];
  if (a[i][j] == 1) {
    dp[i][j] = dp1[i][j] = dp2[i][j] = 0;
  } else {
    dp1[i][j] = dp2[i][j] = 1;
    dp1[i][j] += dp2[i][j - 1];
    dp2[i][j] += dp1[i - 1][j];
    dp[i][j] = dp1[i][j] + dp2[i][j] - 1;
  }
  ans += dp[i][j];
}
signed main() {
  cin >> n >> m >> q;
  init();
  while (q--) {
    long long x, y;
    cin >> x >> y;
    a[x][y] = !a[x][y];
    long long i = x + 1;
    long long j = y + 1;
    fun(x, y);
    while (1) {
      if (i > n || j > m) {
        if (i - 1 <= n && j <= m) fun(i - 1, j);
        if (i <= n && j - 1 <= m) fun(i, j - 1);
        break;
      }
      fun(i, j - 1);
      fun(i - 1, j);
      fun(i, j);
      i++;
      j++;
    }
    cout << ans << endl;
  }
  return 0;
}
