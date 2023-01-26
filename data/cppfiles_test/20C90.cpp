#include <bits/stdc++.h>
using namespace std;
const int N = 405, Inf = 0x3f3f3f3f;
int T, n, m;
int f[N];
int sum[N][N];
char s[N];
int calc(int x1, int y1, int x2, int y2) {
  return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    int ans = Inf, cur = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%s", s + 1);
      for (int j = 1; j <= m; j++)
        sum[i][j] =
            sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (s[j] == '1');
    }
    for (int i = 1; i <= n - 4; i++)
      for (int j = i + 4; j <= n; j++) {
        for (int k = 4; k <= m; k++)
          f[k] = calc(i + 1, 1, j - 1, k - 1) - calc(i, 1, i, k - 1) -
                 calc(j, 1, j, k - 1) - calc(i + 1, k, j - 1, k) + (k << 1) +
                 j - i - 3;
        for (int k = m - 1; k >= 4; k--) f[k] = min(f[k], f[k + 1]);
        for (int k = 1; k <= m - 3; k++) {
          cur = f[k + 3] - calc(i + 1, 1, j - 1, k) + calc(i, 1, i, k) +
                calc(j, 1, j, k) - (k << 1) - calc(i + 1, k, j - 1, k) + j - i -
                1;
          ans = min(ans, cur);
        }
      }
    printf("%d\n", ans);
  }
  return 0;
}
