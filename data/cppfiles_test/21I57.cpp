#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int dp[N][N][N], n, m, k, p, c[N][N], fac[N];
inline int dfs(int i, int d, int k) {
  if (~dp[i][d][k]) return dp[i][d][k];
  if (d == m) return 0;
  int &g = dp[i][d][k];
  g = 0;
  for (int j = 0; j <= (i - 1) / 2; ++j)
    for (int x = 0; x <= j && x <= k; ++x)
      g = (g + (1ll + (j != i - 1 - j)) * dfs(j, d + 1, x) *
                   dfs(i - 1 - j, d + 1, k - x) % p * c[i - 1][j]) %
          p;
  return g;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &p);
  fac[0] = 1;
  for (int i = c[0][0] = 1; i <= n; ++i) {
    c[i][0] = 1;
    fac[i] = 1ll * fac[i - 1] * i % p;
    for (int j = 1; j <= i; ++j) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % p;
  }
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i <= n; ++i) dp[0][i][0] = 1;
  for (int i = 1; i <= n; ++i) dp[i][m][1] = fac[i];
  printf("%d\n", dfs(n, 1, k));
  return 0;
}
