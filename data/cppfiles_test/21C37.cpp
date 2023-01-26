#include <bits/stdc++.h>
using namespace std;
int f[100 + 1][100 + 1][100 + 1], res, C[100 + 1][100 + 1];
signed main() {
  int n, m, k, p;
  cin >> n >> m >> k >> p;
  for (int i = 1; i <= n; ++i) f[1][i][i == m] = 1, f[0][i][0] = 1;
  for (int i = 0; i <= n; ++i) C[i][0] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= i; ++j) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
  if (k > (n + 1) / 2) {
    puts("0");
    return 0;
  }
  for (register int i = 2; i <= n; ++i)
    for (register int t = 1, op; t <= n - 1; ++t) {
      op = (t == m);
      for (register int j = 0; j <= i - 1; ++j)
        for (register int s = 0; s <= min(k, (j + 1) / 2); ++s)
          for (register int s2 = 0; s2 <= min((i - op - j + 1) / 2, k - s - op);
               ++s2) {
            int res = 1ll * f[j][t + 1][s] * f[i - 1 - j][t + 1][s2] % p *
                      C[i - 1][j] % p;
            f[i][t][s + s2 + op] = (f[i][t][s + s2 + op] + res) % p;
          }
    }
  printf("%d\n", f[n][1][k]);
  return 0;
}
