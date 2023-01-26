#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int mod = 998244353;
LL dp[507][507], C[507][507], mi[507][507];
int qpow(int a, int k, int p = mod) {
  int res = 1 % p;
  while (k) {
    if (k & 1) res = (LL)res * a % p;
    k >>= 1;
    a = (LL)a * a % p;
  }
  return res;
}
void solve() {
  for (int i = 1; i <= 500; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    for (int j = 0; j <= 500; j++) mi[i][j] = qpow(i, j);
    dp[0][i] = 1;
  }
  for (int i = 1; i <= 500; i++) {
    for (int j = 1; j <= 500; j++) {
      if (j < i)
        dp[i][j] = mi[j][i];
      else {
        for (int k = 0; k <= i; k++) {
          dp[i][j] =
              (dp[i][j] + C[i][k] * dp[i - k][j - i + 1] * mi[i - 1][k]) % mod;
        }
      }
    }
  }
}
signed main() {
  ios::sync_with_stdio(false);
  solve();
  int tt = 1;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    cout << dp[n][x] << endl;
  }
}
