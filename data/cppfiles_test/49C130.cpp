#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long fpow(long long a, long long b) {
  long long r = 1;
  for (a %= mod; b; b >>= 1) {
    if (b & 1) r = r * a % mod;
    a = a * a % mod;
  }
  return r;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; ++i) cin >> a[i];
  long long dp[1 << n], mul[1 << n][n], inner[1 << n][2];
  for (int i = 0; i < 1 << n; ++i) {
    mul[i][0] = mul[i][1] = 1;
    for (int j = 0; j < n; ++j) {
      if (i >> j & 1) mul[i][1] = mul[i][1] * a[j] % mod;
    }
    for (int j = 2; j < n; ++j) {
      mul[i][j] = mul[i][j - 1] * mul[i][1] % mod;
    }
    if (i > 0) {
      int b = 31 - __builtin_clz(i);
      inner[i][0] = inner[i ^ (1 << b)][0];
      for (int j = 0; j < b; ++j) {
        if (i >> j & 1) inner[i][0] = inner[i][0] * (a[b] + a[j]) % mod;
      }
    } else {
      inner[i][0] = 1;
    }
    inner[i][1] = fpow(inner[i][0], mod - 2);
  }
  for (int i = 1; i < 1 << n; ++i) {
    dp[i] = 1;
    for (int j = (i - 1) & i; j; j = (j - 1) & i) {
      dp[i] -= dp[j] * mul[j][__builtin_popcount(i ^ j)] % mod * inner[j][0] %
               mod * inner[i ^ j][0] % mod * inner[i][1] % mod;
    }
    dp[i] %= mod;
  }
  long long ans = 0;
  for (int i = 1; i < 1 << n; ++i) {
    int p = (1 << n) - 1;
    ans += mul[i][__builtin_popcount(i ^ p)] * inner[i][0] % mod *
           inner[i ^ p][0] % mod * inner[p][1] % mod * dp[i] % mod *
           __builtin_popcount(i) % mod;
  }
  ans %= mod;
  if (ans < 0) ans += mod;
  cout << ans << '\n';
}
