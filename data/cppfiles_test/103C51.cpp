#include <bits/stdc++.h>
using namespace std;
struct qxl {
  int x, y;
  char fx;
} w[4000005];
int t, n, m, maxm, h, x, y, p, d, v[2005][2005], dis[2005][2005], z, a, s;
char q[2005][2005];
int main() {
  cin >> t;
  for (int i = 1; i <= t; i++) {
    scanf("%d%d", &n, &m);
    getchar();
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= m; k++) {
        q[j][k] = getchar();
        v[j][k] = 0;
        dis[j][k] = 0;
      }
      getchar();
    }
    maxm = 0;
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= m; k++)
        if (!v[j][k]) {
          h = 0;
          w[0].x = j;
          w[0].y = k;
          w[0].fx = q[j][k];
          p = 0;
          z = 0;
          a = w[h].x;
          s = w[h].y;
          while (1) {
            v[a][s] = 2;
            if (w[h].fx == 'R') s++;
            if (w[h].fx == 'L') s--;
            if (w[h].fx == 'U') a--;
            if (w[h].fx == 'D') a++;
            if (a < 1 || s < 1 || a > n || s > m) break;
            if (v[a][s] == 2) p = 1;
            if (v[a][s] == 1) z = dis[a][s];
            if (v[a][s]) break;
            h++;
            w[h].x = a;
            w[h].y = s;
            w[h].fx = q[a][s];
          }
          d = h + 1 + z;
          if (maxm < d) {
            maxm = d;
            x = w[0].x;
            y = w[0].y;
          }
          for (int l = 0; l <= h; l++) {
            v[w[l].x][w[l].y] = 1;
            dis[w[l].x][w[l].y] = d;
            if (p == 1 && w[l].x == a && w[l].y == s) p = 2;
            if (p != 2) d--;
          }
        }
    printf("%d %d %d\n", x, y, maxm);
  }
  return 0;
}
