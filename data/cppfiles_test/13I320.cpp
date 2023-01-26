#include <bits/stdc++.h>
int tcase, n, m, K;
char ans[110][110];
void addH(int x, int y) {
  char c = (x % 4 == 1 ? 'a' : 'b');
  for (int i = 1; i <= y; i++) ans[i][x] = ans[i][x + 1] = c, c = 'a' - c + 'b';
}
void addV(int x, int y) {
  char c = (x % 4 == 1 ? 'x' : 'y');
  if (y & 1) c = 'x' - c + 'y';
  ans[x][y] = ans[x + 1][y] = c;
}
int main() {
  scanf("%d", &tcase);
  while (tcase--) {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) ans[i][j] = 0;
    if (n & 1) {
      for (int i = 1; i <= m; i += 2) {
        if (K >= n)
          addH(i, n), K -= n;
        else if (K & 1) {
          addH(i, K);
          K = 0;
          break;
        } else {
          if (i + 3 <= m) {
            addH(i, K - 1);
            addH(i + 2, 1);
            K = 0;
            break;
          }
          goto FAILED;
        }
      }
    } else {
      for (int i = 1; i <= m; i += 2) {
        if (K >= n)
          addH(i, n), K -= n;
        else if (K & 1)
          goto FAILED;
        else {
          addH(i, K);
          K = 0;
          break;
        }
      }
    }
    for (int i = 1; i <= n; i += 2)
      for (int j = 1; j <= m; j++)
        if (!ans[i][j]) addV(i, j);
    printf("YES\n");
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) printf("%c", ans[i][j]);
      printf("\n");
    }
    continue;
  FAILED:
    printf("NO\n");
  }
  return 0;
}
