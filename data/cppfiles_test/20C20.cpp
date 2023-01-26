#include <bits/stdc++.h>
using namespace std;
int arr[401][401];
int pfx[401][401];
int dp[401][401][401];
int ptl(int y2, int x2, int y1, int x1) {
  int a1 =
      pfx[y2][x2] - pfx[y2][x1 - 1] - pfx[y1 - 1][x2] + pfx[y1 - 1][x1 - 1];
  int a0 = (y2 - y1 + 1) * (x2 - x1 + 1) - a1;
  int b1 =
      pfx[y2 - 1][x2 - 1] - pfx[y2 - 1][x1] - pfx[y1][x2 - 1] + pfx[y1][x1];
  int b0 = (y2 - y1 - 1) * (x2 - x1 - 1) - b1;
  return a0 - b0 + b1 - !arr[y1][x1] - !arr[y1][x2] - !arr[y2][x1] -
         !arr[y2][x2];
}
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      string p;
      cin >> p;
      p = " " + p;
      for (int j = 1; j <= m; j++) {
        arr[i][j] = p[j] - '0';
        pfx[i][j] =
            pfx[i - 1][j] + pfx[i][j - 1] - pfx[i - 1][j - 1] + arr[i][j];
      }
    }
    int ans = 2100000000;
    for (int j1 = 1; j1 <= m; j1++)
      for (int j2 = j1 + 3; j2 <= m; j2++) {
        dp[j1][j2][5] = ptl(5, j2, 1, j1);
        ans = min(ans, dp[j1][j2][5]);
        for (int i = 6; i <= n; i++) {
          int a1 = pfx[i - 1][j2 - 1] - pfx[i - 1][j1] - pfx[i - 2][j2 - 1] +
                   pfx[i - 2][j1];
          int a0 = j2 - j1 - 1 - a1;
          int b1 =
              pfx[i][j2 - 1] - pfx[i][j1] - pfx[i - 1][j2 - 1] + pfx[i - 1][j1];
          int b0 = j2 - j1 - 1 - b1;
          dp[j1][j2][i] = min(dp[j1][j2][i - 1] + !arr[i - 1][j1] +
                                  !arr[i - 1][j2] - a0 + a1 + b0,
                              ptl(i, j2, i - 4, j1));
          ans = min(ans, dp[j1][j2][i]);
        }
      }
    cout << ans << "\n";
  }
  return 0;
}
