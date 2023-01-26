#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
int n, k, dp[505][505], C[505][505], pw[505][505];
int main() {
  cin >> n >> k;
  for (int i = (0), iend = (500); i <= iend; ++i) {
    C[i][0] = 1;
    for (int j = (1), jend = (i); j <= jend; ++j)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
    pw[i][0] = 1;
    for (int j = (1), jend = (500); j <= jend; ++j)
      pw[i][j] = 1ll * pw[i][j - 1] * i % P;
  }
  for (int i = (0), iend = (k); i <= iend; ++i) dp[0][i] = 1;
  for (int i = (0), iend = (k); i <= iend; ++i) dp[1][i] = 0;
  for (int i = (2), iend = (n); i <= iend; ++i) {
    for (int j = (1), jend = (k); j <= jend; ++j) {
      for (int p = (0), pend = (i); p <= pend; ++p)
        if (p != i - 1) {
          dp[i][j] = (dp[i][j] + 1ll * C[i][p] * pw[min(i - 1, j)][p] % P *
                                     (dp[i - p][max(j - i + 1, 0)])) %
                     P;
        }
    }
  }
  cout << dp[n][k] << endl;
  return 0;
}
