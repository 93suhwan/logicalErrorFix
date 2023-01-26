#include <bits/stdc++.h>
using namespace std;
const int maxn = 120;
int n, m, k, p;
int c[maxn][maxn];
long long f[maxn][maxn], g[maxn][maxn];
void init() {
  for (int l = 0; l <= 100; l++) {
    c[l][0] = 1;
    for (int j = 1; j <= l; j++) {
      c[l][j] = (c[l - 1][j] + c[l - 1][j - 1]) % p;
    }
  }
}
int main() {
  int T = 1;
  while (T--) {
    cin >> n >> k >> m >> p;
    init();
    f[0][1] = 1;
    for (int l = 1; l <= n; l++) f[l][1] = 1ll * f[l - 1][1] * l % p;
    f[0][1] = 0;
    f[0][0] = 1;
    for (int ggg = 2; ggg <= k; ggg++) {
      for (int i = 0; i <= n; i++) {
        for (int a = 0; a <= m; a++) {
          if (f[i][a] == 0) continue;
          for (int j = i; i + j + 1 <= n; j++) {
            for (int b = a; a + b <= m; b++) {
              if (i == j && b == a)
                g[i + j + 1][a + b] +=
                    1ll * f[i][a] * f[j][b] % p * c[i + j][i] % p;
              else
                g[i + j + 1][a + b] +=
                    2ll * f[i][a] * f[j][b] % p * c[i + j][i] % p;
            }
          }
        }
      }
      for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
          f[i][j] = g[i][j] % p;
          g[i][j] = 0;
        }
      }
      f[0][0] = 1;
    }
    cout << f[n][m] % p << endl;
  }
}
