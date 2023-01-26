#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, x[2], y[2], w, ww, f[2][2001][2001], ans, p[2001][2001];
int add(const int a, const int b) {
  if (a + b >= mod) return a + b - mod;
  return a + b;
}
int del(const int a, const int b) {
  if (a - b < 0) return a - b + mod;
  return a - b;
}
int mul(const int a, const int b) { return ((int)(1ll * a * b % mod)); }
int main() {
  register int i, j, k, u, v, s, l, r;
  scanf("%d%d", &n, &m);
  p[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    p[i][0] = 1;
    for (int j = 1; j <= i; j++) p[i][j] = add(p[i - 1][j], p[i - 1][j - 1]);
  }
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
        f[w][j][k] = add(mul(f[ww][j][k - 1], k), mul(f[ww][j][k], j + k));
    }
    for (k = x[ww]; k < i; k++) {
      r = min(y[w], k + 1);
      for (u = x[ww], v = max(x[w], k + 1 - i), s = 0; v <= r; v++) {
        while (u <= y[ww]) {
          if (u < v && u <= k) {
            s = add(s, f[ww][u][k - u]);
            u++;
          } else
            break;
        }
        f[w][v][k - v + 1] = add(f[w][v][k - v + 1], s);
      }
    }
    for (k = x[ww]; k <= y[ww]; k++) {
      for (j = 0; j < i; j++) {
        f[ww][k][j] = 0;
      }
    }
  }
  for (i = x[w]; i <= y[w]; i++) {
    r = n - i;
    for (j = 0; j <= r; j++) {
      ans = add(ans, mul(f[w][i][j], p[n - i][j]));
    }
  }
  printf("%d\n", ans);
}
