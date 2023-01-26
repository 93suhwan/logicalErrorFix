#include <bits/stdc++.h>
using namespace std;
const int N = 2000;
int id[N + 9][N + 9], dt[N + 9][N + 9];
int col[N + 9 >> 1];
int n;
char g[N + 9][N + 9];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%s", g[i] + 1);
  if (n & 1) {
    puts("NONE");
    return 0;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      dt[i][j] = (1 & (i - 1 >> 1)) ^ (1 & (j - 1 >> 1));
  for (int i = 1; i + i <= n; i++) {
    for (int x = 1, y = i * 2 - 1; y >= 1; x++, y--) id[x][y] = i;
    for (int x = n - (i - 1) * 2, y = n; x <= n; x++, y--) id[x][y] = i;
    for (int x = 1, y = i * 2; y <= n; x++, y++) id[x][y] = i;
    for (int x = i * 2, y = 1; x <= n; x++, y++) id[x][y] = i;
  }
  memset(col, -1, sizeof(col));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (g[i][j] != '.') {
        int c = (g[i][j] == 'S') ^ dt[i][j];
        if (~col[id[i][j]] && col[id[i][j]] != c) {
          puts("NONE");
          return 0;
        }
        col[id[i][j]] = c;
      }
  for (int i = 1; i + i <= n; i++)
    if (!~col[i]) {
      puts("MULTIPLE");
      return 0;
    }
  puts("UNIQUE");
  for (int i = 1; i <= n; i++, putchar('\n'))
    for (int j = 1; j <= n; j++)
      if (col[id[i][j]] ^ dt[i][j])
        putchar('S');
      else
        putchar('G');
  return 0;
}
