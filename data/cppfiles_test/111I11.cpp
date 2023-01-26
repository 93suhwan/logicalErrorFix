#include <bits/stdc++.h>
using namespace std;
const long long N = 2000 + 5, Mod = 998244353;
int n = 0, k = 0, b[N] = {}, m = 0, p = 0;
int dp[2][N][N] = {}, A[N][N] = {}, ans = 0;
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
  dp[0][0][0] = 1;
  for (int i = 0; i <= n; ++i) {
    A[0][i] = 1;
    for (int j = 1; j <= i; ++j)
      A[j][i] = 1ll * A[j - 1][i] * (i - j + 1) % Mod;
  }
  for (int i = 1; i <= n; ++i) {
    p = p ^ 1;
    for (int j = 0; j <= i; j++) dp[p][j][m] = 0;
    for (int mex = m + 1; mex <= min(b[i] + k, i); ++mex)
      for (int j = 0; j <= i - mex; ++j) {
        if (mex - 1 <= b[i - 1] + k) dp[p][j][mex] = dp[p ^ 1][j][mex - 1];
        dp[p][j][mex] =
            (dp[p][j][mex] + 1ll * dp[p][j + 1][mex - 1] * (j + 1)) % Mod;
        ;
      }
    m = max(m, b[i] - k);
    for (int mex = m; mex <= min(min(b[i - 1], b[i]) + k, i); ++mex)
      for (int j = 0; j <= i - mex; ++j) {
        dp[p][j][mex] =
            (dp[p][j][mex] + 1ll * dp[p ^ 1][j][mex] * (j + mex)) % Mod;
        if (j) dp[p][j][mex] = (dp[p][j][mex] + dp[p ^ 1][j - 1][mex]) % Mod;
      }
  }
  for (int mex = m; mex <= min(b[n] + k, n); ++mex)
    for (int j = 0; j <= n - mex; ++j)
      ans = (ans + 1ll * dp[p][j][mex] * A[j][n - mex]) % Mod;
  printf("%d", ans);
  return 0;
}
