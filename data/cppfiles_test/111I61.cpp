#include <bits/stdc++.h>
using namespace std;
const int N = 2000 + 5, K = 100 + 5, Mod = 998244353;
int n = 0, k = 0, b[N] = {}, d = 0, p = 0;
int dp[2][N][K] = {}, g[N] = {}, A[N][N] = {}, ans = 0;
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
  dp[0][0][k] = 1;
  for (int i = 0; i <= n; ++i) {
    A[0][i] = 1;
    for (int j = 1; j <= i; ++j)
      A[j][i] = 1ll * A[j - 1][i] * (i - j + 1) % Mod;
  }
  for (int i = 1; i <= n; ++i) {
    p = p ^ 1;
    for (int j = 0; j <= i; j++) g[j] = 0;
    for (int mex = d; mex <= min(b[i] + k, i); ++mex)
      for (int j = 0; j <= i - mex; ++j) {
        g[j] = 1ll * g[j + 1] * (j + 1) % Mod;
        if (abs(mex - 1 - b[i - 1]) <= k)
          g[j] = (dp[p ^ 1][j][mex - 1 - b[i - 1] + k] +
                  1ll * g[j + 1] * (j + 1)) %
                 Mod;
        if (abs(mex - b[i]) <= k) {
          dp[p][j][mex - b[i] + k] = g[j];
          if (abs(mex - b[i - 1]) <= k) {
            dp[p][j][mex - b[i] + k] =
                (dp[p][j][mex - b[i] + k] +
                 1ll * dp[p ^ 1][j][mex - b[i - 1] + k] * (j + mex)) %
                Mod;
            if (j)
              dp[p][j][mex - b[i] + k] =
                  (dp[p][j][mex - b[i] + k] +
                   dp[p ^ 1][j - 1][mex - b[i - 1] + k]) %
                  Mod;
          }
        }
      }
    d = max(d, b[i] - k);
  }
  for (int mex = d; mex <= min(b[n] + k, n); ++mex)
    for (int j = 0; j <= n - mex; ++j)
      ans = (ans + 1ll * dp[p][j][mex - b[n] + k] * A[j][n - mex]) % Mod;
  printf("%d", ans);
  return 0;
}
