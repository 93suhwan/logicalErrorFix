#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n, m, k, p;
int f[maxn][maxn][maxn], c[maxn][maxn], fac[maxn];
int dp(int i, int j, int k) {
  if (f[i][j][k] != -1) return f[i][j][k];
  f[i][j][k] = 0;
  if (j > i || k > i || i * j == 0) {
    if (!k) f[i][j][k] = fac[i];
    return f[i][j][k];
  }
  for (int v = 1; v <= i; ++v)
    for (int w = max(0, k - (j == 1) - (i - v)); w <= min(k - (j == 1), v - 1);
         ++w) {
      int cur;
      cur =
          (1ll * dp(v - 1, j - 1, w) * dp(i - v, j - 1, k - (j == 1) - w)) % p;
      cur = (cur * 1ll * c[i - 1][v - 1]) % p;
      f[i][j][k] = (f[i][j][k] + cur) % p;
    }
  return f[i][j][k];
}
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &p);
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = (fac[i - 1] * 1ll * i) % p;
  for (int i = 0; i <= n; ++i) {
    c[i][i] = c[i][0] = 1;
    for (int j = 1; j < i; ++j) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % p;
  }
  memset(f, -1, sizeof(f));
  printf("%d\n", dp(n, m, k));
  return 0;
}
