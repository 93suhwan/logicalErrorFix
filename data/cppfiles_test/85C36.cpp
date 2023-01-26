#include <bits/stdc++.h>
using namespace std;
int n, MOD;
int C[205][205];
int f[205][205][205];
int main() {
  scanf("%d%d", &n, &MOD);
  for (int i = 0; i <= 200; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
      if (C[i][j] >= MOD) C[i][j] -= MOD;
    }
  }
  int ans = 0;
  for (int minv = max(n - 18, 1); minv <= n; minv++) {
    f[minv - 1][0][0] = 1;
    for (int i = minv; i <= n + 1; i++) {
      for (int j = 0; j <= n; j++) {
        for (int k = 0; k <= minv; k++) {
          if ((i - j) * minv < k) {
            f[i][j][k] = f[i - 1][j][k];
          } else {
            for (int x = 0; x <= j && k - x * (i - minv) >= 0; x++) {
              f[i][j][k] += (((long long)(f[i - 1][j - x][k - x * (i - minv)]) *
                              (long long)(C[j][x])) %
                             MOD);
              if (f[i][j][k] >= MOD) f[i][j][k] -= MOD;
            }
          }
        }
      }
    }
    int addval = 0;
    for (int k = 0; k <= minv; k++) {
      addval += f[n + 1][n][k];
      if (addval >= MOD) addval -= MOD;
    }
    ans += addval;
    if (ans >= MOD) ans -= MOD;
    f[minv - 1][0][0] = 0;
    for (int i = minv; i <= n + 1; i++) {
      for (int j = 0; j <= n; j++) {
        for (int k = 0; k <= minv; k++) {
          f[i][j][k] = 0;
        }
      }
    }
  }
  printf("%d", ans);
  return 0;
}
