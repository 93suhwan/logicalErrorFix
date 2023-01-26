#include <bits/stdc++.h>
using namespace std;
int a[1000000 + 5];
int f[1000000 + 5][2][2];
pair<int, int> g[1000000 + 5][2][2];
void print(int n, int i, int j) {
  if (n == 0) return;
  print(n - 1, g[n][i][j].first, g[n][i][j].second);
  if (j == 0)
    printf("%d ", a[n]);
  else
    printf("%d ", -a[n]);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, i, j, k, l;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (i = 0; i <= n + 1; i++)
      for (j = 0; j < 2; j++)
        for (k = 0; k < 2; k++) f[i][j][k] = 1e9;
    f[1][0][0] = f[1][0][1] = -1e9;
    for (i = 1; i < n; i++)
      for (j = 0; j < 2; j++)
        for (k = 0; k < 2; k++) {
          int x = a[i], y = f[i][j][k];
          if (k) x = -x;
          if (j) swap(x, y);
          for (l = 0; l < 2; l++) {
            int z = a[i + 1];
            if (l) z = -z;
            if (z < y) continue;
            if (z < x) {
              if (f[i + 1][1][l] > x)
                f[i + 1][1][l] = x, g[i + 1][1][l] = make_pair(j, k);
            } else {
              if (f[i + 1][0][l] > y)
                f[i + 1][0][l] = y, g[i + 1][0][l] = make_pair(j, k);
            }
          }
        }
    bool flag = false;
    for (i = 0; i < 2 && !flag; i++)
      for (j = 0; j < 2 && !flag; j++)
        if (f[n][i][j] <= n && !flag) {
          printf("YES\n");
          print(n, i, j);
          flag = true;
          break;
        }
    if (!flag) printf("NO");
    printf("\n");
  }
}
