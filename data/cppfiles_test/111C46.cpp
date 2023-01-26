#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n, m, a[2005], f[2][2005][105], g[2][2005][105];
int Bg, Ed, bg, ed, C[2005][2005], ans;
inline int val(int i, int x) { return a[i] - m + x; }
inline int id(int i, int x) { return x - a[i] + m; }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  f[0][0][m] = 1;
  for (int j = m; j <= m + m; ++j) g[0][0][j] = 1;
  for (int i = 1; i <= n; ++i) {
    memset(f[i & 1], 0, sizeof(f[0]));
    memset(g[i & 1], 0, sizeof(g[0]));
    for (int j = 1; j <= i; ++j) {
      Bg = max(id(i, 0), 0), Ed = min(id(i, j), m + m);
      for (int x = Bg, k, t, cur; x <= Ed; ++x) {
        k = val(i, x), t = id(i - 1, k), cur = 0;
        if (0 <= t && t <= m + m)
          cur = ((long long)f[~i & 1][j][t] * j +
                 (long long)f[~i & 1][j - 1][t] * (j - k)) %
                p;
        bg = max(id(i - 1, 0), 0), ed = min(id(i - 1, k - 1), m + m);
        if (bg <= ed)
          cur = ((long long)cur + g[~i & 1][j - 1][ed] -
                 (bg ? g[~i & 1][j - 1][bg - 1] : 0)) %
                p;
        f[i & 1][j][x] = cur;
        if (x > Bg)
          g[i & 1][j][x] = (g[i & 1][j][x - 1] + cur) % p;
        else
          g[i & 1][j][x] = cur;
      }
    }
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
    C[i][0] = 1;
  }
  for (int j = 1; j <= n; ++j) {
    Bg = max(id(n, 0), 0), Ed = min(id(n, j), m + m);
    for (int x = Bg, k; x <= Ed; ++x) {
      k = val(n, x);
      ans = (ans + (long long)f[n & 1][j][x] * C[n - k][j - k]) % p;
    }
  }
  printf("%d\n", (ans + p) % p);
  return 0;
}
