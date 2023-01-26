#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5;
const int MOD = 998244353;
int C[N][N], pw[N][N];
int dp[N][N], n, k;
void init(int m = 5e2 + 1) {
  for (int i = 0; i <= m; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
  }
  for (int i = 0; i <= m; i++) {
    pw[i][0] = 1;
    for (int j = 1; j <= m; j++) pw[i][j] = (long long)pw[i][j - 1] * i % MOD;
  }
}
int main() {
  init();
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      if (i > j)
        dp[i][j] = pw[j][i];
      else {
        dp[i][j] = pw[i - 1][i];
        for (int l = 0; l < i; l++)
          dp[i][j] = (dp[i][j] + (long long)C[i][l] * pw[i - 1][l] % MOD *
                                     dp[i - l][j - i + 1] % MOD) %
                     MOD;
      }
    }
  }
  printf("%d\n", dp[n][k]);
  return 0;
}
