#include <bits/stdc++.h>
using namespace std;
const int DIM = 105;
const int MAX = 100;
int dp[DIM][DIM][DIM];
int C[DIM][DIM], p;
void prec() {
  C[0][0] = 1;
  for (int i = 1; i <= MAX; ++i) {
    C[i][0] = C[i][i] = 1;
    C[i][1] = i;
    for (int j = 2; j < i; ++j) {
      C[i][j] = ((long long)C[i - 1][j] + C[i - 1][j - 1]) % p;
    }
  }
}
inline void addmod(int &x, int y) {
  x += y;
  if (x >= p) x -= p;
}
int main() {
  int n, m, k, f = 1;
  cin >> n >> m >> k >> p;
  prec();
  dp[0][1][1] = 1;
  for (int j = 1; j <= m; ++j) {
    dp[0][j][0] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    f = ((long long)f * i) % p;
    dp[i][1][1] = f;
    for (int j = i + 1; j <= m; ++j) {
      dp[i][j][0] = f;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= min(i, m); ++j) {
      for (int q = 0; q <= min(i, k); ++q) {
        for (int l = 0; l < i; ++l) {
          for (int _k = max(0, q + l + 1 - i); _k <= min(l, q); ++_k) {
            if (dp[l][j - 1][_k] && dp[i - l - 1][j - 1][q - _k]) {
              long long val = (long long)C[i - 1][l] * dp[l][j - 1][_k] % p *
                              dp[i - l - 1][j - 1][q - _k] % p;
              addmod(dp[i][j][q], val);
            }
          }
        }
      }
    }
  }
  cout << dp[n][m][k];
  return 0;
}
