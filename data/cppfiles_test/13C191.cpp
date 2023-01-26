#include <bits/stdc++.h>
int tcase, n, m, K;
char ans[110][110];
void addH(int x, int y) {
  char c = (y % 4 == 1 ? 'a' : 'b');
  if (x & 1) c = 'a' - c + 'b';
  ans[x][y] = ans[x][y + 1] = c;
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
    bool flag = false;
    if (n & 1) {
      if (K < m / 2) goto FAILED;
      for (int i = 1; i <= m; i += 2) addH(n, i);
      K -= m / 2;
      n--;
      flag = true;
    }
    for (int i = 1; i + 1 <= m; i += 2) {
      if (K >= n) {
        for (int j = 1; j <= n; j++) addH(j, i);
        K -= n;
      } else if (K & 1)
        goto FAILED;
      else {
        for (int j = 1; j <= K; j++) addH(j, i);
        K = 0;
        break;
      }
    }
    if (K) goto FAILED;
    n += flag ? 1 : 0;
    for (int i = 1; i <= n; i++)
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
