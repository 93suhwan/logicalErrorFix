#include <bits/stdc++.h>
using namespace std;
int n, m, k, MOD, dp[101][101][101], C[101][101], fac[101];
inline void mod(int &x) {
  if (x >= MOD) x -= MOD;
}
inline int solve(int n, int m, int k) {
  if (k > n) return 0;
  if (m > n) return !k ? fac[n] : 0;
  if (m == 1) return k == 1 ? fac[n] : 0;
  if (!n) return !k;
  if (~dp[n][m][k]) return dp[n][m][k];
  int ans = 0;
  for (int i = 1; i + i <= n + 1; i++) {
    int c = (m == 1);
    for (int j = 0; j <= k - c; j++) {
      ans += ((1 + (i + i <= n)) * 1LL * solve(i - 1, m - 1, j) * 1LL *
              solve(n - i, m - 1, k - j - c) % MOD) *
             1LL * C[n - 1][i - 1] % MOD;
      mod(ans);
    }
  }
  return dp[n][m][k] = ans;
}
int main() {
  cin >> n >> m >> k >> MOD;
  for (int i = 0; i <= 100; i++) C[i][0] = 1;
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= i; j++) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
      mod(C[i][j]);
    }
  }
  fac[0] = 1;
  for (int i = 1; i <= 100; i++) fac[i] = fac[i - 1] * 1LL * i % MOD;
  memset(dp, -1, sizeof(dp));
  cout << solve(n, m, k);
}
