#include <bits/stdc++.h>
using namespace std;
const int N = 60, M = 1500;
int n, m;
int g[N][N], t[6];
int check(int a, int b, int c, int d, int e) {
  t[1] = a, t[2] = b, t[3] = c, t[4] = d, t[5] = e;
  int f = 1;
  for (int i = 1; i <= 5; i++) {
    for (int j = i + 1; j <= 5; j++) {
      if (g[t[i]][t[j]] != 1) {
        f = 0;
        break;
      }
    }
    if (f == 0) break;
  }
  if (f) return 1;
  f = 1;
  for (int i = 1; i <= 5; i++) {
    for (int j = i + 1; j <= 5; j++) {
      if (g[t[i]][t[j]] != 0) {
        f = 0;
        break;
      }
    }
    if (f == 0) break;
  }
  if (f) return 1;
  return 0;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x > 50 || y > 50) continue;
    g[x][y] = g[y][x] = 1;
  }
  n = min(n, 50);
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      for (int k = j + 1; k <= n; k++)
        for (int l = k + 1; l <= n; l++)
          for (int p = l + 1; p <= n; p++)
            if (check(i, j, k, l, p)) {
              printf("%d %d %d %d %d\n", i, j, k, l, p);
              return 0;
            }
  puts("-1");
  return 0;
}
