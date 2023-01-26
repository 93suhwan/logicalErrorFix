#include <bits/stdc++.h>
int abs_(int a) { return a > 0 ? a : -a; }
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    static char aa[2000 + 1], bb[2000 + 1];
    static int dp[2000 + 1][2000 * 2 + 1], dq[2000 + 1][2000 * 2 + 1];
    int n, i, d;
    scanf("%d%s%s", &n, aa, bb);
    for (i = 1; i < n; i += 2)
      if (aa[i] != '?') aa[i] = aa[i] == '0' ? '1' : '0';
    for (i = 1; i < n; i += 2)
      if (bb[i] != '?') bb[i] = bb[i] == '0' ? '1' : '0';
    for (i = 0; i <= n; i++)
      for (d = -n; d <= n; d++) dp[i][n + d] = dq[i][n + d] = 0;
    dp[0][n + 0] = 1, dq[0][n + 0] = 0;
    for (i = 0; i < n; i++)
      for (d = -n; d <= n; d++) {
        int x = dp[i][n + d], y = dq[i][n + d], d_ = abs_(d);
        if (x == 0 && y == 0) continue;
        if ((aa[i] == '?' || aa[i] == '0') && (bb[i] == '?' || bb[i] == '0')) {
          dp[i + 1][n + d] = (dp[i + 1][n + d] + x) % 1000000007;
          dq[i + 1][n + d] =
              (dq[i + 1][n + d] + y + (long long)x * d_) % 1000000007;
        }
        if ((aa[i] == '?' || aa[i] == '0') && (bb[i] == '?' || bb[i] == '1')) {
          dp[i + 1][n + d - 1] = (dp[i + 1][n + d - 1] + x) % 1000000007;
          dq[i + 1][n + d - 1] =
              (dq[i + 1][n + d - 1] + y + (long long)x * d_) % 1000000007;
        }
        if ((aa[i] == '?' || aa[i] == '1') && (bb[i] == '?' || bb[i] == '0')) {
          dp[i + 1][n + d + 1] = (dp[i + 1][n + d + 1] + x) % 1000000007;
          dq[i + 1][n + d + 1] =
              (dq[i + 1][n + d + 1] + y + (long long)x * d_) % 1000000007;
        }
        if ((aa[i] == '?' || aa[i] == '1') && (bb[i] == '?' || bb[i] == '1')) {
          dp[i + 1][n + d] = (dp[i + 1][n + d] + x) % 1000000007;
          dq[i + 1][n + d] =
              (dq[i + 1][n + d] + y + (long long)x * d_) % 1000000007;
        }
      }
    printf("%d\n", dq[n][n + 0]);
  }
  return 0;
}
