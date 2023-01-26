#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
char a[maxn], b[maxn];
int n, m, k;
int g[maxn][maxn][maxn];
int Ne[maxn], to[2][maxn];
void kmp() {
  int p = 0;
  Ne[1] = 0;
  for (int i = 2; i <= m; i++) {
    while (p && b[p + 1] != b[i]) p = Ne[p];
    if (b[p + 1] == b[i]) {
      p++;
      Ne[i] = p;
    }
  }
}
int main() {
  cin >> n >> m;
  scanf("%s", a + 1);
  scanf("%s", b + 1);
  kmp();
  k = n - m + 1;
  memset(g, 0x3f, sizeof(g));
  g[0][0][0] = 0;
  for (int j = 0; j <= m; j++) {
    int p = j;
    while (p != 0 && b[p + 1] != '0') p = Ne[p];
    if (b[p + 1] == '0')
      to[0][j] = p + 1;
    else
      to[0][j] = 0;
    p = j;
    while (p != 0 && b[p + 1] != '1') p = Ne[p];
    if (b[p + 1] == '1')
      to[1][j] = p + 1;
    else
      to[1][j] = 0;
    printf("(%d,%d)", to[0][j], to[1][j]);
  }
  putchar('\n');
  for (int i = 0; i < n; i++) {
    for (int l = 0; l <= k; l++) {
      for (int j = 0; j <= m; j++) {
        if (g[i][j][l] == g[0][0][1]) continue;
        int fl = (a[i + 1] != '0');
        g[i + 1][to[0][j]][l + to[0][j] / m] =
            min(g[i + 1][to[0][j]][l + to[0][j] / m], g[i][j][l] + fl);
        fl = (a[i + 1] != '1');
        g[i + 1][to[1][j]][l + to[1][j] / m] =
            min(g[i + 1][to[1][j]][l + to[1][j] / m], g[i][j][l] + fl);
      }
    }
  }
  for (int i = 0; i <= k; i++) {
    int ans = g[0][0][1];
    for (int j = 0; j <= m; j++) ans = min(ans, g[n][j][i]);
    if (ans == g[0][0][1]) ans = -1;
    printf("%d ", ans);
  }
  return 0;
}
