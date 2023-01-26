#include <bits/stdc++.h>
inline int read() {
  char c = getchar();
  int x = 0;
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - 48, c = getchar();
  return x;
}
const int maxn = 105;
int N, M, K, mod, C[maxn][maxn], fac[maxn];
int dp[maxn][maxn][maxn], vis[maxn][maxn][maxn];
inline int dqm(int x) { return x < 0 ? x + mod : x; }
inline int qm(int x) { return x >= mod ? x - mod : x; }
int solve(int n, int m, int k) {
  if (m * k > n * (n - 1) / 2) return 0;
  if (k < 0) return 0;
  if (!n) return k == 0;
  if (m <= 0 && k == 0) return fac[n];
  if (m < 0) return 0;
  if (vis[n][m][k]) return dp[n][m][k];
  vis[n][m][k] = 1;
  for (signed int i = 1; i <= n; i++)
    for (signed int j = 0; j <= k; ++j) {
      dp[n][m][k] = qm(dp[n][m][k] +
                       1ll * C[n - 1][i - 1] * solve(i - 1, m - 1, j) % mod *
                           solve(n - i, m - 1, k - j - (m == 1)) % mod);
    }
  return dp[n][m][k];
}
int main() {
  scanf("%d%d%d%d", &N, &M, &K, &mod);
  for (signed int i = 0; i <= 100; ++i) C[i][0] = C[i][i] = 1;
  for (signed int i = 1; i <= 100; ++i)
    for (signed int j = 1; j < i; j++)
      C[i][j] = qm(C[i - 1][j - 1] + C[i - 1][j]);
  fac[0] = 1;
  for (signed int i = 1; i <= 100; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
  printf("%d\n", solve(N, M, K));
  return 0;
}
