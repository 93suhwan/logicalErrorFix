#include <bits/stdc++.h>
using namespace std;
const int int_inf = 0x3f3f3f3f;
const long long int ll_inf = 0x3f3f3f3f3f3f3f3f;
const int max_n = 1e5 + 5;
const long long int mod = 998244353;
long long int qpow(long long int a, int b) {
  long long int res = 1;
  while (b) {
    if (b & 1) {
      res = res * a % mod;
    }
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
long long int x[505], invx[505];
inline long long int C(int a, int b) {
  if (a < b || a < 0 || b < 0) return 0;
  return x[a] * invx[b] % mod * invx[a - b] % mod;
}
void init(int n) {
  invx[0] = x[0] = 1;
  for (int i = 1; i <= n; i++) {
    x[i] = x[i - 1] * i % mod;
    invx[i] = qpow(x[i], mod - 2);
  }
  return;
}
long long int dp[505][505];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  init(505);
  int n, x;
  cin >> n >> x;
  for (int i = 1; i <= n; i++) dp[i][0] = 1;
  for (int i = 1; i <= x; i++) dp[0][i] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= x; j++) {
      if (j - i < 0) {
        dp[i][j] = qpow(j, i);
        continue;
      }
      for (int o = 0; o <= i; o++) {
        dp[i][j] = (dp[i][j] + dp[i - o][j - i + 1] * qpow(i - 1, o) % mod *
                                   C(i, o) % mod) %
                   mod;
      }
    }
  }
  cout << dp[n][x] << '\n';
  return 0;
}
