#include <bits/stdc++.h>
struct R {
  int mod;
  double inv;
  R(int m) : mod(m), inv(1. / m) {}
  uint64_t operator()(uint64_t x) {
    x -= uint64_t(x * inv + .5) * mod;
    return x < mod ? x : x + mod;
  }
} A(2);
int mod;
inline int inc(int x, int y) { return x += y - mod, x += x >> 31 & mod; }
inline int dec(int x, int y) { return x -= y, x += x >> 31 & mod; }
inline int mul(int x, int y) { return A(uint64_t(x) * y); }
int qpow(int a, int b) {
  int c = 1;
  for (; b; b >>= 1, a = mul(a, a))
    if (b & 1) c = mul(a, c);
  return c;
}
const int maxn = 205;
int n, fac[maxn], fic[maxn], low[maxn], dp[maxn][maxn][maxn];
inline void upd(int &x, int y) { x = inc(x, y); }
void init() {
  fac[0] = 1;
  for (int i = int(1); i <= int(n); i++) fac[i] = mul(fac[i - 1], i);
  fic[n] = qpow(fac[n], mod - 2);
  for (int i = int(n); i >= int(1); i--) fic[i - 1] = mul(fic[i], i);
}
int solve(int m) {
  memset(low, 0, sizeof(low));
  int s = 0;
  for (int i = int(1); i <= int(n - m); i++) {
    s += (low[m + i] = i + 1);
  }
  if (s > m) return 0;
  memset(dp, 0, sizeof(dp));
  for (int i = int(1); i <= int(m); i++) {
    dp[0][i][0] = fic[i];
  }
  for (int i = int(0); i <= int(n - m); i++)
    for (int j = int(0); j <= int(n); j++)
      for (int k = int(0); k <= int(m); k++)
        if (k + n - j <= m) {
          for (int l = int(0); l <= int(n - j); l++)
            if (i + 1 >= low[j + l])
              upd(dp[i + 1][j + l][k + n - j], mul(dp[i][j][k], fic[l]));
        }
  int x = 0;
  for (int i = int(0); i <= int(m); i++) {
    upd(x, dp[n - m + 1][n][i]);
  }
  return mul(x, fac[n]);
}
int main() {
  scanf("%d %d", &n, &mod), A = R(mod);
  init();
  int s = 1;
  for (int m = int(n / 2 + 1); m <= int(n); m++) {
    s = inc(s, solve(m));
  }
  printf("%d\n", s);
  return 0;
}
