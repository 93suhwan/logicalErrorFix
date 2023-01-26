#include <bits/stdc++.h>
using namespace std;
const int M = 1005;
long long read() {
  long long x = 0, f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9') {
    if (c == '-') f = -1;
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
long long n, m, q, ans, num, dp[M][M][2];
void upd(long long i, long long j, long long w) {
  if (!i || !j) return;
  if (dp[i][j][0]) {
    ans -= dp[i][j][0] + dp[i][j][1];
    dp[i][j][0] = dp[i][j][1] = 1;
    dp[i][j][0] += dp[i + 1][j][1];
    dp[i][j][1] += dp[i][j + 1][0];
    ans += dp[i][j][0] + dp[i][j][1];
  }
  if (!w)
    upd(i, j - 1, 1);
  else
    upd(i - 1, j, 0);
}
signed main() {
  n = read();
  m = read();
  q = read();
  num = n * m;
  for (long long i = n; i >= 1; i--)
    for (long long j = m; j >= 1; j--) {
      dp[i][j][0] = dp[i][j][1] = 1;
      dp[i][j][0] += dp[i + 1][j][1];
      dp[i][j][1] += dp[i][j + 1][0];
      ans += dp[i][j][0] + dp[i][j][1];
    }
  while (q--) {
    long long i = read(), j = read();
    if (dp[i][j][0]) {
      ans -= dp[i][j][0] + dp[i][j][1];
      dp[i][j][0] = dp[i][j][1] = 0;
      num--;
    } else {
      dp[i][j][0] = dp[i][j][1] = 1;
      dp[i][j][0] += dp[i + 1][j][1];
      dp[i][j][1] += dp[i][j + 1][0];
      ans += dp[i][j][0] + dp[i][j][1];
      num++;
    }
    upd(i - 1, j, 0);
    upd(i, j - 1, 1);
    printf("%lld\n", ans - num);
  }
}
