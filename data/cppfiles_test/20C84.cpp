#include <bits/stdc++.h>
using namespace std;
const int maxn = 404;
char s[maxn][maxn];
int sum[maxn][maxn], sr[maxn], sc[maxn], sc2[maxn];
int main(void) {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        sum[i][j] =
            sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + s[i][j] - '0';
      }
    }
    int ans = n * m;
    for (int x = 1; x <= n; x++) {
      for (int y = x + 4; y <= n; y++) {
        int h = y - x - 1;
        for (int j = 1; j <= m; j++) {
          sr[j] = sum[x][j] - sum[x - 1][j] + sum[y][j] - sum[y - 1][j];
          sc[j] = sum[y - 1][j] - sum[y - 1][j - 1] - sum[x][j] + sum[x][j - 1];
          sc2[j] = sc2[j - 1] + sc[j];
        }
        int mn = (int)1e9;
        for (int l = 1, r = 4; r <= m; l++, r++) {
          mn = min(mn, -sc[l] - 2 * l + sr[l] - sc2[l]);
          ans =
              min(ans, mn + 2 * h - sc[r] + 2 * r - 2 - sr[r - 1] + sc2[r - 1]);
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
