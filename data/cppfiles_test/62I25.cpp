#include <bits/stdc++.h>
using namespace std;
const long long N = 1005;
long long n, m, q;
bool a[N][N];
long long dp1[N][N];
long long dp2[N][N];
long long ans = 0;
void init() {
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) dp1[i][j] = dp2[i][j] = 1;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) {
      dp1[i][j] += dp2[i][j - 1];
      dp2[i][j] += dp1[i - 1][j];
    }
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) ans += dp1[i][j] + dp2[i][j] - 1;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> q;
  init();
  while (q--) {
    long long x, y;
    cin >> x >> y;
    for (long long i = x; i <= n; i++)
      for (long long j = y; j <= m; j++) {
        if (i == x && j == y) {
          if (a[i][j] == 0) ans -= dp1[i][j] + dp2[i][j] - 1;
          a[x][y] = !a[x][y];
          if (a[i][j] == 1) {
            dp1[i][j] = 0;
            dp2[i][j] = 0;
          } else {
            dp1[i][j] = 1;
            dp2[i][j] = 1;
            dp1[i][j] += dp2[i][j - 1];
            dp2[i][j] += dp1[i - 1][j];
          }
          if (a[i][j] == 0) ans += dp1[i][j] + dp2[i][j] - 1;
        } else {
          if (a[i][j] == 0) ans -= dp1[i][j] + dp2[i][j] - 1;
          if (a[i][j] == 1) {
            dp1[i][j] = 0;
            dp2[i][j] = 0;
          } else {
            dp1[i][j] = 1;
            dp2[i][j] = 1;
            dp1[i][j] += dp2[i][j - 1];
            dp2[i][j] += dp1[i - 1][j];
          }
          if (a[i][j] == 0)
            ans += dp1[i][j] + dp2[i][j] - 1;
          else
            break;
        }
      }
    cout << ans << endl;
  }
  return 0;
}
