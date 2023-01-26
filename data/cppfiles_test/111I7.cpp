#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, x[2], y[2], w, ww, f[2][2001][2001], ans, fact[2001], ifac[2001];
int add(int a, int b) {
  if (a + b >= mod) return a + b - mod;
  return a + b;
}
int del(int a, int b) {
  if (a - b < 0) return a - b + mod;
  return a - b;
}
int mul(int a, int b) { return ((int)(1ll * a * b % mod)); }
int ksm(int a, int b) {
  int s = 1;
  while (b) {
    if (b & 1) s = mul(s, a);
    a = mul(a, a);
    b = (b >> 1);
  }
  return s;
}
int main() {
  register int i, j, k, u, v, s, l, r;
  scanf("%d%d", &n, &m);
  fact[0] = 1;
  for (i = 1; i <= n; i++) fact[i] = mul(fact[i - 1], i);
  ifac[n] = ksm(fact[n], mod - 2);
  for (i = n; i >= 1; i--) ifac[i - 1] = mul(ifac[i], i);
  x[0] = 0;
  y[0] = 0;
  f[0][0][0] = 1;
  w = 0;
  ww = 1;
  for (i = 1; i <= n; i++) {
    swap(w, ww);
    scanf("%d", &x[w]);
    y[w] = min(n, x[w] + m);
    x[w] = max(0, x[w] - m);
    x[w] = max(x[w], x[ww]);
    l = x[w];
    r = min(y[ww], y[w]);
    for (j = l; j <= r; j++) {
      f[w][j][0] = mul(f[ww][j][0], j);
      for (k = 1; k <= i; k++)
        f[w][j][k] = add(f[ww][j][k - 1], mul(f[ww][j][k], j + k));
    }
    for (k = x[ww]; k < i; k++) {
      r = min(y[w], k + 1);
      for (u = x[ww], v = max(x[w], k + 1 - i), s = 0; v <= r; v++) {
        while (u <= y[ww]) {
          if (u < v && u <= k) {
            s = add(s, mul(f[ww][u][k - u], fact[k - u]));
            u++;
          } else
            break;
        }
        f[w][v][k - v + 1] = add(f[w][v][k - v + 1], mul(s, ifac[k - v + 1]));
      }
    }
  }
  for (i = x[w]; i <= y[w]; i++) {
    for (j = 0; j <= n; j++) {
      if (n - i >= j)
        ans = add(ans, mul(f[w][i][j], mul(fact[n - i], ifac[n - i - j])));
    }
  }
  printf("%d\n", ans);
}
