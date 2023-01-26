#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int dp[maxn][maxn][maxn], C[maxn][maxn], fac[maxn];
int mod;
inline void add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
int main() {
  int n, m, k;
  scanf("%d%d%d%d", &n, &m, &k, &mod);
  C[0][0] = 1;
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (!i && !j) continue;
      if (j)
        C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
      else
        C[i][j] = C[i - 1][j];
    }
    fac[i] = 1ll * fac[i - 1] * i % mod;
  }
  dp[1][1][1] = 1;
  for (int i = 0; i <= k; ++i)
    for (int j = 0; j <= m; ++j) dp[0][i][j] = 1;
  for (int i = 0; i <= n; ++i) {
    dp[i][0][0] = fac[i];
    if (i != 1) dp[1][0][i] = 1;
  }
  for (int h = 1; h <= m; ++h) {
    vector<int> g[maxn];
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= min(i, k); ++j) {
        if (dp[i][j][h - 1]) g[i].push_back(j);
      }
    }
    for (int i = 0; i <= n - 1; ++i) {
      if (g[i].empty()) continue;
      for (int j = 0; j <= n - 1 - i; ++j) {
        if (g[j].empty() || !i && !j) continue;
        for (auto x : g[i]) {
          for (auto y : g[j]) {
            if (x + y + (h == 1) > min(i + j + 1, k)) continue;
            add(dp[i + j + 1][x + y + (h == 1)][h], 1ll * C[i + j][i] *
                                                        dp[i][x][h - 1] % mod *
                                                        dp[j][y][h - 1] % mod);
          }
        }
      }
    }
  }
  printf("%d\n", dp[n][k][m]);
}
