#include <bits/stdc++.h>
using namespace std;
const long long MAX_N = 100 + 7;
long long C[MAX_N][MAX_N];
long long fac[MAX_N];
void init(long long n, long long MOD) {
  C[0][0] = 1;
  for (long long i = 1; i <= n; ++i) {
    C[i][0] = 1;
    for (long long j = 1; j <= i; ++j) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
      if (C[i][j] >= MOD) C[i][j] -= MOD;
    }
  }
  fac[0] = 1;
  for (long long i = 1; i <= n; ++i) {
    fac[i] = fac[i - 1] * i % MOD;
  }
}
long long n, m, k, MOD;
long long dp[MAX_N][MAX_N][MAX_N];
long long dfs(long long u, long long n, long long k) {
  if (u > m || !n) {
    if (k)
      return 0;
    else
      return fac[n];
  }
  if (u == m) k -= 1;
  if (dp[u][n][k] >= 0) return dp[u][n][k];
  dp[u][n][k] = 0;
  for (long long i = 0; i <= n - 1; ++i) {
    for (long long j = max(0ll, m - n + k + i - u - 1);
         j <= min(k, i + u + 2 - m); ++j) {
      dp[u][n][k] += dfs(u + 1, i, j) * dfs(u + 1, n - 1 - i, k - j) % MOD *
                     C[n - 1][i] % MOD;
      if (dp[u][n][k] >= MOD) dp[u][n][k] -= MOD;
    }
  }
  return dp[u][n][k];
}
signed main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k >> MOD;
  init(n, MOD);
  for (long long i = 0; i <= n; ++i) {
    for (long long j = 0; j <= n; ++j) {
      for (long long w = 0; w <= k; ++w) {
        if (m - i + w - 1 <= j)
          dp[i][j][w] = -1;
        else
          dp[i][j][w] = 0;
      }
    }
  }
  cout << dfs(1, n, k) << endl;
  return 0;
}
