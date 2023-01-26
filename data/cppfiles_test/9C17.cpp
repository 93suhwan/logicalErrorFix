#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, c;
  scanf("%d%d%d", &n, &m, &k);
  int a[n][m];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) scanf("%d", &a[i][j]);
  for (int i = 0; i < k; ++i) {
    scanf("%d", &c);
    int x = 0, y = c - 1;
    while (x < n) {
      if (a[x][y] == 1) {
        a[x][y++] = 2;
      } else if (a[x][y] == 3) {
        a[x][y--] = 2;
      } else {
        ++x;
      }
    }
    if (i) putchar(' ');
    printf("%d", y + 1);
  }
  puts("");
}
