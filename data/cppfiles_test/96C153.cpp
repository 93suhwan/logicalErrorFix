#include <bits/stdc++.h>
template <class T>
inline T max(const T &x, const T &y) {
  return x > y ? x : y;
}
template <class T>
inline T min(const T &x, const T &y) {
  return x < y ? x : y;
}
template <class T>
inline bool chkmax(T &x, const T &y) {
  return x < y ? x = y, true : false;
}
template <class T>
inline bool chkmin(T &x, const T &y) {
  return x > y ? x = y, true : false;
}
inline int read() {
  register int x = 0, v = 1;
  register char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') v = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * v;
}
const int MAmN = 500;
const int MOD = 998244353;
int n, m;
int dp[MAmN | 1][MAmN | 1], C[MAmN | 1][MAmN | 1];
inline int add(int x, int y) { return x + y >= MOD ? x + y - MOD : x + y; }
inline int sub(int x, int y) { return x < y ? x - y + MOD : x - y; }
inline void Add(int &x, int y) { x = add(x, y); }
inline void Sub(int &x, int y) { x = sub(x, y); }
int fpow(int x, int y) {
  --y;
  for (int i = x; y; y >>= 1, i = 1ll * i * i % MOD)
    if (y & 1) x = 1ll * x * i % MOD;
  return x;
}
int main() {
  n = read();
  m = read();
  C[0][0] = 1;
  for (int i = 1; i <= MAmN; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j) C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= min(m, i - 1); ++j)
      for (int k = 0, pw1 = 1, pw2 = fpow(j, i - 1), inv = fpow(j, MOD - 2);
           k < i;
           ++k, pw1 = 1ll * pw1 * (j - 1) % MOD, pw2 = 1ll * pw2 * inv % MOD)
        Add(dp[i][j], 1ll * pw1 * pw2 % MOD);
    for (int j = i; j <= m; ++j) {
      for (int k = i - 1, pw = min(i - 1, m); k;
           --k, pw = 1ll * pw * min(i - 1, m) % MOD)
        Add(dp[i][j], 1ll * dp[k][j - i + 1] * C[i][k] % MOD * pw % MOD);
      Add(dp[i][j], dp[i][j - i + 1]);
    }
  }
  int ans = 0;
  for (int i = 1; i <= m; ++i) Add(ans, dp[n][i]);
  printf("%d\n", ans);
  return 0;
}
