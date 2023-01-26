#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int n;
long long a[20], pr[20][20];
long long dp[(1 << 14) + 10];
long long pot(long long u, long long v) {
  u %= mod;
  long long z = 1;
  while (v) {
    if (v & 1) {
      z = (z * u) % mod;
    }
    u = (u * u) % mod;
    v /= 2;
  }
  return z;
}
long long inv(long long u) { return pot(u, mod - 2); }
long long f(int i, int j) {
  long long ans = 1;
  for (int x = 0; x < n; ++x) {
    if ((1 << x) & i && !((1 << x) & j)) {
      long long cur = 1;
      for (int k = 0; k < n; ++k) {
        if ((1 << k) & i) {
          continue;
        }
        cur = (cur * pr[x][k]) % mod;
      }
      ans = (ans * (1 - cur + mod)) % mod;
    }
  }
  if (__builtin_popcount(i ^ j) % 2 == 0) {
    ans = (mod - ans) % mod;
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      pr[i][j] = (a[i] * inv(a[i] + a[j])) % mod;
    }
  }
  int l = (1 << n) - 1;
  dp[l] = 1;
  for (int i = 1; i < (1 << n); ++i) {
    int j = i;
    do {
      j = (j - 1) & i;
      dp[l ^ i] += dp[l ^ j] * f(i, j);
      dp[l ^ i] %= mod;
    } while (j > 0);
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += dp[(1 << i)];
    ans %= mod;
  }
  printf("%lld\n", ans);
}
