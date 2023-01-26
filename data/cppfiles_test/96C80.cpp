#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353, MAXN = 505;
int c[MAXN][MAXN], pkt[MAXN][MAXN], dp[MAXN][MAXN];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, x;
  cin >> n >> x;
  c[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
    }
  }
  for (int i = 0; i <= x; i++) {
    pkt[i][0] = 1;
    for (int j = 1; j <= n; j++) pkt[i][j] = (1LL * pkt[i][j - 1] * i) % MOD;
  }
  for (int i = 1; i <= x; i++) {
    dp[1][i] = 0;
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= x; j++) {
      dp[i][j] = pkt[min(i - 1, j)][i];
      if (i <= j) {
        for (int k = 0; k < i; k++) {
          dp[i][j] = (dp[i][j] +
                      (1LL * ((1LL * c[i][k] * dp[i - k][j - i + 1]) % MOD) *
                       pkt[i - 1][k]) %
                          MOD) %
                     MOD;
        }
      }
    }
  }
  cout << dp[n][x] << '\n';
  return 0;
}
