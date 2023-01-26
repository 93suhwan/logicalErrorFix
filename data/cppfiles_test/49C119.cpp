#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 15;
const int M = 1 << N;
int a[N], dp[M], p[N][M];
int add(int a, int b) { return (a + b) % mod; }
int mul(int a, int b) { return 1ll * a * b % mod; }
int qpow(int a, int n) {
  int re = 1;
  while (n > 0) {
    if (n & 1) {
      re = mul(re, a);
    }
    a = mul(a, a);
    n >>= 1;
  }
  return re;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) {
      p[j][i] = 1;
    }
    for (int j = 0; j < n; j++) {
      if (i >> j & 1) {
        for (int k = 0; k < n; k++) {
          if (i >> k & 1) continue;
          p[k][i] =
              mul(p[k][i ^ 1 << j], mul(a[k], qpow(add(a[k], a[j]), mod - 2)));
        }
        break;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i < (1 << n); i++) {
    dp[i] = 1;
    for (int j = (i - 1) & i; j; j = (j - 1) & i) {
      int tmp = 1;
      for (int k = 0; k < n; k++) {
        if (j >> k & 1) {
          tmp = mul(tmp, p[k][i ^ j]);
        }
      }
      dp[i] = add(dp[i], mod - mul(dp[j], tmp));
    }
    int tmp = 1;
    for (int j = 0; j < n; j++) {
      if (i >> j & 1) {
        tmp = mul(tmp, p[j][(1 << n) - 1 ^ i]);
      }
    }
    ans = add(ans, mul(mul(dp[i], tmp), __builtin_popcount(i)));
  }
  printf("%d", ans);
  return 0;
}
