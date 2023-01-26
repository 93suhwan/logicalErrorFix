#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 7;
const int Mod = 998244353;
int dp[N][N], C[N][N], pw[N][N];
int qpow(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = 1ll * ret * x % Mod;
    x = 1ll * x * x % Mod, y >>= 1;
  }
  return ret;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  dp[n][0] = 1;
  for (int i = 0; i <= n; i++) C[i][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % Mod;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) pw[j][i] = qpow(j, i);
  for (int i = n; i; i--)
    for (int j = 0; j <= m; j++) {
      int to = min(j + i - 1, m);
      for (int k = i; ~k; k--)
        dp[k][to] = (dp[k][to] +
                     1ll * dp[i][j] * C[i][k] % Mod * pw[to - j][i - k] % Mod) %
                    Mod;
    }
  int ans = 0;
  for (int i = 0; i <= m; i++) ans = (ans + dp[0][i]) % Mod;
  printf("%d", ans);
}
