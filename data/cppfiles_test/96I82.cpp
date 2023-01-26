#include <bits/stdc++.h>
using namespace std;
long long m = 998244353;
long long dp[501][501];
long long binpow(long long a, long long n) {
  if (n == 0) return 1;
  if (n % 2 == 1)
    return binpow(a, n - 1) * a % m;
  else {
    long long b = binpow(a, n / 2);
    return b * b % m;
  }
}
long long f[501];
long long c(long long n, long long k) {
  return f[n] * binpow(f[k], m - 2) % m * binpow(f[n - k], m - 2) % m;
}
int main() {
  long long n, x;
  cin >> n >> x;
  f[0] = 1;
  for (int i = 1; i <= n; i++) f[i] = f[i - 1] * i % m;
  long long ans = 0;
  dp[n][1] = 1;
  for (int i = n; i > 1; i--) {
    for (int j = 1; j <= x; j++) {
      for (int h = 1; h <= i; h++) {
        dp[h][j + i - 1] +=
            dp[i][j] * max(1ll, binpow(i - 1, i - h)) * c(i, h) % m;
        dp[h][j + i - 1] %= m;
      }
    }
  }
  for (int i = 0; i <= x; i++) ans = (ans + dp[1][i] * (x + 1 - i)) % m;
  cout << (binpow(x, n) + m - ans) % m;
  return 0;
}
