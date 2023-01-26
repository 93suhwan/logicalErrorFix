#include <bits/stdc++.h>
using namespace std;
int n, m, g[55][55];
int main() {
  scanf("%d%d", &n, &m);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a < 55 && b < 55) g[a][b] = g[b][a] = 1;
  }
  int nn = min(48, n);
  for (int a = 1; a <= nn; a++)
    for (int b = a + 1; b <= nn; b++)
      for (int c = b + 1; c <= nn; c++)
        for (int d = c + 1; d <= nn; d++)
          for (int e = d + 1; e <= nn; e++)
            if ((g[a][b] && g[a][c] && g[a][d] && g[a][e] && g[b][c] &&
                 g[b][d] && g[b][e] && g[c][d] && g[c][e] && g[d][e]) ||
                (!g[a][b] && !g[a][c] && !g[a][d] && !g[a][e] && !g[b][c] &&
                 !g[b][d] && !g[b][e] && !g[c][d] && !g[c][e] && !g[d][e])) {
              printf("%d %d %d %d %d\n", a, b, c, d, e);
              return 0;
            }
  puts("-1");
  return 0;
}
