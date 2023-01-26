#include <bits/stdc++.h>
const int inf = 1 << 29;
inline void upd(int &v, int x) {
  if (v > x) v = x;
}
char s[510], t[510];
int f[510], dp[2][510][510];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  scanf("%s%s", s, t);
  f[0] = -1;
  for (int i = 1; i < m; i++) {
    int j = f[i];
    while (j != -1 && t[i] != t[j]) {
      j = f[j];
    }
    f[i + 1] = j + 1;
  }
  int u = n - m + 1;
  for (int i = 0; i <= u; i++) {
    for (int j = 0; j < m; j++) {
      dp[0][i][j] = inf;
    }
  }
  dp[0][0][0] = 0;
  int y = 0, z = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= u; j++) {
      for (int k = 0; k < m; k++) {
        dp[z][j][k] = inf;
      }
    }
    for (int j = 0; j <= u; j++) {
      for (int k = 0; k < m; k++) {
        int x = dp[y][j][k];
        if (x == inf) continue;
        for (int l = 0; l < 2; l++) {
          int p = k, nj = j;
          while (p != -1 && (s[i] == t[p]) == l) {
            p = f[p];
          }
          if (++p == m) {
            nj++;
            p = f[k];
            while (p != -1 && (s[i] == t[p]) == l) {
              p = f[p];
            }
            ++p;
          }
          upd(dp[z][nj][p], x + l);
        }
      }
    }
    y ^= 1;
    z ^= 1;
  }
  for (int j = 0; j <= u; j++) {
    int ans = inf;
    for (int k = 0; k < m; k++) {
      upd(ans, dp[y][j][k]);
    }
    if (ans == inf) ans = -1;
    printf("%d ", ans);
  }
  return 0;
}
