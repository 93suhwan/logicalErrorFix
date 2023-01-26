#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, N = 2005;
int T, n, f[N][N * 2], g[N][N * 2];
char a[N], b[N];
inline void upd(int& x, int y) { x += y - mod, x += x >> 31 & mod; }
inline int mul(int x, int y) { return long long(x) * y % mod; }
void work(int f[][N * 2]) {
  f[0][n] = 1;
  for (int i = (1); i <= int(n); ++i) {
    memset(f[i], 0, sizeof(f[i][0]) * (n * 2 + 1));
    for (int p = (0); p <= int(1); ++p)
      if (a[i] == '?' || a[i] == '0' + p) {
        for (int q = (0); q <= int(1); ++q)
          if (b[i] == '?' || b[i] == '0' + q) {
            for (int j = (1); j <= int(n * 2 - 1); ++j) {
              upd(f[i][j + p - q], f[i - 1][j]);
            }
          }
      }
  }
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%s%s", &n, a + 1, b + 1);
    for (int i = (1); i <= int(n); ++i)
      if ((i & 1) && a[i] != '?') a[i] ^= 1;
    for (int i = (1); i <= int(n); ++i)
      if ((i & 1) && b[i] != '?') b[i] ^= 1;
    work(f);
    reverse(a + 1, a + n + 1), reverse(b + 1, b + n + 1);
    work(g);
    int x = 0;
    for (int i = (1); i <= int(n - 1); ++i)
      for (int j = (0); j <= int(n * 2); ++j) {
        upd(x, mul(std::abs(j - n), mul(f[i][j], g[n - i][n * 2 - j])));
      }
    printf("%d\n", x);
  }
  return 0;
}
