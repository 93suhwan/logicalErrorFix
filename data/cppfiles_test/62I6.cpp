#include <bits/stdc++.h>
using namespace std;
const long long N = 1e3 + 7;
long long n;
long long m;
long long dp[N][N][2];
long long on[N][N];
long long all;
long long q;
void calc(long long x, long long y) {
  long long ban = on[x][y] * (dp[x][y][0] + dp[x][y][1] - 1);
  all += ban;
  for (long long i = 0; i <= 1; i++) {
    long long a = x, b = y;
    bool c = i;
    while (1) {
      if (c == 1)
        ++b;
      else
        ++a;
      if (a > n || b > m) break;
      dp[a][b][!c] += on[x][y] * dp[x][y][c];
      if (on[a][b] == 1) break;
      all += on[x][y] * dp[x][y][c];
      c ^= 1;
    }
  }
  on[x][y] = -on[x][y];
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> q;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      on[i][j] = -1;
      dp[i][j][1] = dp[i - 1][j][0] + 1;
      dp[i][j][0] = dp[i][j - 1][1] + 1;
      all += dp[i][j][0] + dp[i][j][1] - 1;
    }
  }
  while (q--) {
    long long x, y;
    cin >> x >> y;
    calc(x, y);
    cout << all << '\n';
  }
}
