#include <bits/stdc++.h>
using namespace std;
long long mul(long long a, long long b) { return a * b % 998244353; }
long long quickmi(long long x, long long y) {
  long long ans = 1;
  long long base = x % 998244353;
  if (!y) return 1;
  while (y) {
    if (y & 1) ans = (ans * base) % 998244353;
    y >>= 1;
    base = (base * base) % 998244353;
  }
  return ans;
}
long long dp[505][505];
long long C[505][505];
void init() {
  C[0][0] = 1;
  for (int i = 1; i < 505; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % 998244353;
    }
  }
}
int main() {
  init();
  long long n, k;
  cin >> n >> k;
  for (int i = 1; i <= k; i++) dp[1][i] = i, dp[2][i] = i * (i - 1);
  for (int i = 3; i <= n; i++)
    for (int j = 1; j <= k; j++) {
      if (j < i) {
        dp[i][j] = 0;
        continue;
      }
      for (int l = 0; l < i; l++) {
        dp[i][j] += mul(mul(dp[i - l][j - i + 1], quickmi(i - 1, l)), C[i][l]);
        dp[i][j] %= 998244353;
      }
    }
  cout << (quickmi(k, n) - dp[n][k] + 998244353) % 998244353;
  return 0;
}
