#include <bits/stdc++.h>
using namespace std;
int dp[500 + 1][500 + 1], pow_[500 + 1][500 + 1], C[500 + 1][500 + 1];
void preCal() {
  for (int i = 1; i <= 500; ++i) {
    pow_[i][0] = 1;
    for (int j = 1; j <= 500; ++j) {
      pow_[i][j] = pow_[i][j - 1] * 1ll * i % 998244353;
    }
  }
  C[0][0] = 1;
  for (int i = 1; i <= 500; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j <= i - 1; ++j) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
      if (C[i][j] >= 998244353) {
        C[i][j] -= 998244353;
      }
    }
  }
}
void solve() {
  for (int j = 1; j <= 500; ++j) {
    dp[0][j] = 1;
  }
  for (int j = 1; j <= 500; ++j) {
    dp[1][j] = 0;
  }
  for (int i = 2; i <= 500; ++i) {
    dp[i][0] = 0;
    for (int j = 1; j <= 500; ++j) {
      if (j >= i) {
        for (int k = 0; k <= i; ++k) {
          int p = C[i][k] * 1ll * pow_[i - 1][k] % 998244353;
          dp[i][j] += dp[i - k][j - (i - 1)] * 1ll * p % 998244353;
          if (dp[i][j] >= 998244353) {
            dp[i][j] -= 998244353;
          }
        }
      } else {
        dp[i][j] = pow_[j][i];
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  preCal();
  solve();
  cout << dp[n][m];
  return 0;
}
