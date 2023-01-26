#include <bits/stdc++.h>
using namespace std;
bool flag = true, c[55][55];
int n, m, i[10];
int main() {
  scanf("%d%d", &n, &m), n = min(n, 48);
  for (int j = 1, x, y; j <= m; j++) {
    scanf("%d%d", &x, &y);
    if (x <= n && y <= n) c[x][y] = 1, c[y][x] = 1;
  }
  for (i[1] = 1; i[1] <= n; i[1]++)
    for (i[2] = i[1] + 1; i[2] <= n; i[2]++)
      for (i[3] = i[2] + 1; i[3] <= n; i[3]++)
        for (i[4] = i[3] + 1; i[4] <= n; i[4]++)
          for (i[5] = i[4] + 1; i[5] <= n; i[5]++) {
            for (int j = 1; j <= 5; j++)
              for (int k = j + 1; k <= 5; k++)
                if (!c[i[j]][i[k]]) {
                  flag = false;
                  break;
                }
            if (flag) {
              for (int j = 1; j <= 5; j++) printf("%d ", i[j]);
              return puts(""), 0;
            } else
              flag = true;
            for (int j = 1; j <= 5; j++)
              for (int k = j + 1; k <= 5; k++)
                if (c[i[j]][i[k]]) {
                  flag = false;
                  break;
                }
            if (flag) {
              for (int j = 1; j <= 5; j++) printf("%d ", i[j]);
              return puts(""), 0;
            } else
              flag = true;
          }
  return puts("-1"), 0;
}
