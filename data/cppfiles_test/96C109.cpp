#include <bits/stdc++.h>
using namespace std;
const int N = 505, mod = 998244353;
int C[N][N], dp[N][N], pw[N][N];
int dfs(int n, int x) {
  if (~dp[n][x]) return dp[n][x];
  if (x < n) {
    return dp[n][x] = pw[x][n];
  }
  int &ans = dp[n][x];
  ans = pw[n - 1][n];
  for (int y = 2; y <= n; ++y) {
    ans = (ans + 1ll * C[n][n - y] * pw[n - 1][n - y] % mod *
                     dfs(y, x - (n - 1)) % mod) %
          mod;
  }
  return ans;
}
int main() {
  memset(dp, -1, sizeof dp);
  C[0][0] = pw[0][0] = 1;
  for (int i = 1; i < N; ++i) {
    pw[i][0] = 1;
    for (int j = 1; j < N; ++j) {
      pw[i][j] = 1ll * pw[i][j - 1] * i % mod;
    }
  }
  for (int i = 1; i < N; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
  }
  int n, x;
  scanf("%d%d", &n, &x);
  printf("%d\n", dfs(n, x));
  return 0;
}
