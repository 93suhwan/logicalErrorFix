#include <bits/stdc++.h>
inline int fmo(int x) { return x + ((x >> 31) & 1000000007); }
inline int fp(int x, int k = 1000000007 - 2) {
  int res = 1;
  for (; k; k >>= 1, x = 1ll * x * x % 1000000007)
    if (k & 1) res = 1ll * res * x % 1000000007;
  return res;
}
const int W = 37;
int C[W + 1][W + 1];
inline void init() {
  for (int i = 0; i <= W; i++) C[i][0] = 1;
  for (int i = 1; i <= W; i++)
    for (int j = 1; j <= i; j++)
      C[i][j] = fmo(C[i - 1][j] + C[i - 1][j - 1] - 1000000007);
}
int n, q, a[200005];
int b[200005], c[W + 1][200005];
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]), a[i] = fmo(a[i] + 114514 - 1000000007);
  c[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    int tmp = 1;
    for (int j = 0; j <= W; j++, tmp = 1ll * tmp * i % 1000000007)
      c[j][i] = fmo(c[j][i - 1] + tmp - 1000000007);
    b[i] = fmo(b[i - 1] + fp(a[i], W) - 1000000007);
    a[i] = fmo(a[i] + a[i - 1] - 1000000007);
  }
  init();
  while (q--) {
    int L, R, d;
    scanf("%d%d%d", &L, &R, &d);
    int l = R - L + 1,
        s = 1ll * fp(l) *
            fmo(fmo(a[R] - a[L - 1]) -
                1ll * l * (l - 1) / 2 % 1000000007 * d % 1000000007) %
            1000000007;
    int res = 0;
    for (int i = 0; i <= W; i++)
      res = fmo(res +
                1ll * C[W][i] * fp(s, i) % 1000000007 * fp(d, W - i) %
                    1000000007 * c[W - i][l - 1] % 1000000007 -
                1000000007);
    puts(res == fmo(b[R] - b[L - 1]) ? "Yes" : "No");
  }
}
