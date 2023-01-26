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
  for (int i = 2; i <= n; ++i)
    for (int t = 1; t <= min(i, n - 1); ++t)
      for (int j = 0; j <= i - 1; ++j)
        for (int s = 0; s <= j; ++s)
          for (int s2 = 0; s2 <= i - (t == m) - j; ++s2)
            f[i][t][s + s2 + (t == m)] =
                (f[i][t][s + s2 + (t == m)] + 1ll * f[j][t + 1][s] *
                                                  f[i - 1 - j][t + 1][s2] % p *
                                                  C[i - 1][j] % p) %
                p;
  printf("%d\n", f[n][1][k]);
  return 0;
}
