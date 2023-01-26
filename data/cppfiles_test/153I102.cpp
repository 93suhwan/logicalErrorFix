#include <bits/stdc++.h>
inline int Max(const int &a, const int &b) { return a > b ? a : b; }
inline int Min(const int &a, const int &b) { return a > b ? b : a; }
inline int read() {
  int f = 1, x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
const int N = 30;
const int NN = (1 << 23) + 7;
const int M = 2e4 + 7;
const int mod = 998244353;
int n, len, nn;
char ch[M];
int s[N][N], mn[N];
long long dp[NN], res;
int main() {
  n = read(), nn = 1 << n;
  for (int i = 0; i <= n - 1; ++i) {
    scanf("%s", ch);
    len = strlen(ch);
    for (int j = 0; j <= len - 1; ++j) {
      ++s[i][ch[j] - 'a'];
    }
  }
  for (int i = 1; i <= nn - 1; ++i) {
    for (int k = 0; k <= 25; ++k) mn[k] = 1 << 30;
    for (int j = 0; j <= n - 1; ++j) {
      if ((i >> j) & 1) {
        for (int k = 0; k <= 25; ++k) mn[k] = Min(mn[k], s[j][k]);
      }
    }
    long long su = 1;
    for (int k = 0; k <= 25; ++k) {
      su = su * (mn[k] + 1) % mod;
    }
    int num = __builtin_popcount(i) & 1 ? 1 : -1;
    dp[i] = num * su;
  }
  for (int i = 0; i <= n - 1; ++i) {
    for (int j = 1; j <= nn - 1; ++j) {
      if ((j >> i) & 1) {
        dp[j] = (dp[j] + dp[j ^ (1 << i)]) % mod;
      }
    }
  }
  for (int i = 0; i <= nn - 1; ++i) {
    int s = 0, ss = 0;
    for (int j = 0; j <= n - 1; ++j) {
      if ((i >> j) & 1) {
        ++s, ss += j + 1;
      }
    }
    res ^= 1ll * s * ss * dp[i];
  }
  printf("%lld\n", res);
  return 0;
}
