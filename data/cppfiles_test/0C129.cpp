#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 10;
int fac[N], inv[N];
int dp[N][2];
int n, q;
const int mod = 1e9 + 7;
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int del(int a, int b) { return a < b ? a - b + mod : a - b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }
int qpow(int a, int b) {
  int s = 1;
  while (b) {
    if (b & 1) s = mul(s, a);
    a = mul(a, a);
    b >>= 1;
  }
  return s;
}
void initial() {
  fac[0] = fac[1] = 1;
  n = 3 * n + 3;
  for (int i = 2; i <= n; ++i) fac[i] = mul(fac[i - 1], i);
  inv[n] = qpow(fac[n], mod - 2);
  for (int i = n - 1; i >= 0; --i) inv[i] = mul(inv[i + 1], i + 1);
  n /= 3;
  n -= 1;
}
int C(int n, int m) {
  if (m < 0 || m > n) return 0;
  return mul(fac[n], mul(inv[m], inv[n - m]));
}
int main() {
  scanf("%d%d", &n, &q);
  initial();
  int inv3 = qpow(3, mod - 2);
  dp[0][0] = dp[0][1] = n + 1;
  for (int i = 1; i <= 3 * n; ++i) {
    dp[i][0] =
        mul(del(C(3 * n + 3, i + 1), add(mul(2, dp[i - 1][0]), dp[i - 1][1])),
            inv3);
    dp[i][1] = add(dp[i][0], dp[i - 1][0]);
  }
  while (q--) {
    int x;
    scanf("%d", &x);
    printf("%d\n", dp[x][0]);
  }
  return 0;
}
