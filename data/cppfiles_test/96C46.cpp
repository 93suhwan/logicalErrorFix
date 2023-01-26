#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const int N = 510;
const long long mod = 998244353;
int n, m;
long long dp[2][N + N][N + N], C[N][N], ppow[N][N];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  dp[0][0][0] = 1;
  C[0][0] = 1;
  for (int i = 1; i <= 500; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
  }
  for (int i = 1; i <= 500; i++) {
    ppow[i][0] = 1;
    for (int j = 1; j <= 500; j++) {
      ppow[i][j] = ppow[i][j - 1] * i % mod;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= m + 10; i++) {
    int nw = (i & 1);
    int bf = (nw ^ 1);
    memset(dp[nw], 0, sizeof dp[nw]);
    int mnn = 1e9;
    for (int j = 0; j <= n - 2; j++) {
      for (int dam = 0; dam <= m; dam++) {
        if (!dp[bf][j][dam]) continue;
        int ndam = dam + (n - j - 1);
        for (int die = 0; die + j <= n; die++) {
          dp[nw][j + die][ndam] =
              (dp[nw][j + die][ndam] + dp[bf][j][dam] * C[n - j][die] % mod *
                                           ppow[min(n - j - 1, m - dam)][die]) %
              mod;
          if (dp[nw][j + die][ndam]) mnn = min(mnn, ndam);
        }
      }
    }
    for (int dam = 0; dam <= m + n; dam++) {
      dp[nw][n - 1][dam] = 0;
      ans = (ans + dp[nw][n][dam]) % mod;
    }
  }
  cout << ans << '\n';
}
