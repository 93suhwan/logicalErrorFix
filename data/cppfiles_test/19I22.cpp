#include <bits/stdc++.h>
using namespace std;
int T;
int n, a[10001];
int f[10001][2501];
int main() {
  cin >> T;
  for (int ij = 1; ij <= T; ij++) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    memset(f, -1, sizeof(f));
    int ans = 2000000;
    f[1][a[1] + 1000] = a[1];
    f[1][1000 - a[1]] = a[1];
    for (int i = 2; i <= n; i++) {
      for (int j = -1000; j <= 0; j++) {
        if (f[i - 1][j + 1000] != -1) {
          if (f[i - 1][j + 1000] + j <= j + a[i]) {
            if (f[i][j + a[i] + 1000] == -1) {
              f[i][j + a[i] + 1000] = a[i];
            } else {
              f[i][j + a[i] + 1000] = min(f[i][j + a[i] + 1000], a[i]);
            }
          } else {
            if (f[i][j + a[i] + 1000] == -1) {
              f[i][j + a[i] + 1000] = f[i - 1][j + 1000];
            } else {
              f[i][j + a[i] + 1000] =
                  min(f[i][j + a[i] + 1000], f[i - 1][j + 1000]);
            }
          }
          if (j - a[i] >= -1000) {
            if (f[i][j - a[i] + 1000] == -1) {
              f[i][j - a[i] + 1000] = f[i - 1][j + 1000] + a[i];
            } else {
              f[i][j - a[i] + 1000] =
                  min(f[i - 1][j + 1000] + a[i], f[i][j - a[i] + 1000]);
            }
          }
        }
      }
      for (int j = 1; j <= 1000; j++) {
        if (f[i - 1][j + 1000] != -1) {
          if (j - f[i - 1][j + 1000] >= j - a[i]) {
            if (f[i][j - a[i] + 1000] == -1) {
              f[i][j - a[i] + 1000] = a[i];
            } else {
              f[i][j - a[i] + 1000] = min(f[i][j - a[i] + 1000], a[i]);
            }
          } else {
            if (f[i][j - a[i] + 1000] == -1) {
              f[i][j - a[i] + 1000] = f[i - 1][j + 1000];
            } else {
              f[i][j - a[i] + 1000] =
                  min(f[i][j - a[i] + 1000], f[i - 1][j + 1000]);
            }
          }
          if (j + a[i] <= 1000) {
            if (f[i][j + a[i] + 1000] == -1) {
              f[i][j + a[i] + 1000] = f[i - 1][j + 1000] + a[i];
            } else {
              f[i][j + a[i] + 1000] =
                  min(f[i - 1][j + 1000] + a[i], f[i][j + a[i] + 1000]);
            }
          }
        }
      }
    }
    for (int i = -1000; i <= 1000; i++) {
      if (f[n][i + 1000] == -1) continue;
      if (f[n][i + 1000] < ans) ans = f[n][i + 1000];
    }
    printf("%d\n", ans);
  }
  return 0;
}
