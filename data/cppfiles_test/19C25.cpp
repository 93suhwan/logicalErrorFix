#include <bits/stdc++.h>
using namespace std;
int T;
int n, a[10001];
int f[10001][3001];
int main() {
  cin >> T;
  for (int ij = 1; ij <= T; ij++) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= 2050; j++) {
        f[i][j] = 2000000000;
      }
    }
    f[1][a[1]] = 0;
    for (int i = 2; i <= n; i++) {
      for (int j = 0; j <= 2050; j++) {
        if (f[i - 1][j] != 2000000000) {
          if (j + a[i] <= 2000) {
            f[i][j + a[i]] = min(f[i][j + a[i]], max(0, f[i - 1][j] - a[i]));
          }
          if (j - a[i] >= 0) {
            f[i][j - a[i]] = min(f[i][j - a[i]], f[i - 1][j] + a[i]);
          } else {
            f[i][0] = min(f[i][0], f[i - 1][j] + a[i]);
          }
        }
      }
    }
    int ans = 2000000000;
    for (int i = 0; i <= 2050; i++) {
      ans = min(ans, f[n][i] + i);
    }
    printf("%d\n", ans);
  }
  return 0;
}
