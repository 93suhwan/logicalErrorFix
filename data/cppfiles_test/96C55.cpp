#include <bits/stdc++.h>
using namespace std;
long long mod_pow(long long x, long long n, long long mod) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}
int main() {
  long long n, x, MOD = 998244353;
  vector<vector<int>> c(501, vector<int>(501, 1));
  for (int i = (2); i < (501); i++) {
    for (int j = (1); j < (i); j++) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
    }
  }
  cin >> n >> x;
  vector<vector<vector<int>>> s(n + 1,
                                vector<vector<int>>(x + 1, vector<int>(1, 0)));
  for (int i = (2); i < (n + 1); i++) {
    for (int j = (1); j < (x + 1); j++) {
      for (int k = (0); k < (i + 1); k++) {
        long long dp = 0;
        if (k == 0) {
          dp = mod_pow(min(i - 1, j), i, MOD);
        }
        if (k > 1 && j >= i) {
          dp = c[i][k];
          dp = 1LL * dp * mod_pow(i - 1, i - k, MOD) % MOD;
          dp = 1LL * dp * s[k][j - i + 1][0] % MOD;
        }
        s[i][j][0] = (s[i][j][0] + dp) % MOD;
      }
    }
  }
  long long ans = 0;
  cout << s[n][x][0] << endl;
}
