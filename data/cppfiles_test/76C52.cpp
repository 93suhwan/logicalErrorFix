#include <bits/stdc++.h>
using namespace std;
int n, m, id;
int t[100][100];
int main() {
  int x, y;
  scanf("%d%d", &n, &m);
  n = min(48, n);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    if (x <= n && y <= n) t[x][y] = t[y][x] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (t[i][j])
        for (int k = j + 1; k <= n; k++)
          if (t[i][k] && t[j][k])
            for (int l = k + 1; l <= n; l++)
              if (t[i][l] && t[j][l] && t[k][l])
                for (int o = l + 1; o <= n; o++)
                  if (t[i][o] && t[j][o] && t[k][o] && t[l][o])
                    return !printf("%d %d %d %d %d", i, j, k, l, o);
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) t[i][j] = !t[i][j];
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (t[i][j])
        for (int k = j + 1; k <= n; k++)
          if (t[i][k] && t[j][k])
            for (int l = k + 1; l <= n; l++)
              if (t[i][l] && t[j][l] && t[k][l])
                for (int o = l + 1; o <= n; o++)
                  if (t[i][o] && t[j][o] && t[k][o] && t[l][o])
                    return !printf("%d %d %d %d %d", i, j, k, l, o);
    }
  }
  printf("-1");
  return 0;
}
