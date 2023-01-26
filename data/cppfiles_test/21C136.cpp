#include <bits/stdc++.h>
using namespace std;
int ncr[111][111], fac[111], p;
int dp[111][111][111];
int dfs(int n, int m, int k) {
  if (n == 0) return (k == 0);
  if (m == 1) return (k == 1 ? fac[n] : 0);
  if (n == 1) return (k == 0);
  if (k * 2 > n + 1) return 0;
  if (m > n) return (k == 0 ? fac[n] : 0);
  if (dp[n][m][k] != -1) return dp[n][m][k];
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++)
      ans = (ans + 1ll * ncr[n - 1][i - 1] * dfs(i - 1, m - 1, j) % p *
                       dfs(n - i, m - 1, k - j) % p) %
            p;
  }
  dp[n][m][k] = ans;
  return ans;
}
int n, m, k;
void solve() {
  int i, j;
  cin >> n >> m >> k >> p;
  for (i = 0; i <= 100; i++) ncr[i][0] = ncr[i][i] = 1;
  for (i = 1; i <= 100; i++) {
    for (j = 1; j <= i; j++)
      ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % p;
  }
  fac[0] = 1;
  for (i = 1; i <= 100; i++) fac[i] = 1ll * fac[i - 1] * i % p;
  memset(dp, -1, sizeof dp);
  printf("%d", dfs(n, m, k));
}
int main(void) {
  int T = 1;
  while (T--) {
    solve();
  }
}
