#include <bits/stdc++.h>
const int maxn = 407;
using namespace std;
int T, n, m, ans;
char t[maxn];
int a[maxn][maxn], sum[maxn][maxn], s[maxn], p[maxn], q[maxn];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
      scanf("%s", t + 1);
      for (int j = 1; j <= m; j++) a[i][j] = t[j] - '0';
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) sum[i][j] = sum[i - 1][j] + a[i][j];
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 4; j <= n; j++) {
        int maxx = -0x3f3f3f3f;
        for (int k = 1; k <= m; k++) {
          s[k] = s[k - 1] + sum[j - 1][k] - sum[i][k];
          p[k] = p[k - 1] + (1 - a[i][k]);
          q[k] = q[k - 1] + (1 - a[j][k]);
        }
        for (int k = 4; k <= m; k++) {
          maxx = max(maxx, -(j - i - 1 - (s[k - 3] - s[k - 4])) + s[k - 3] +
                               p[k - 3] + q[k - 3]);
          ans = min(ans, j - i - 1 - (s[k] - s[k - 1]) + s[k - 1] + p[k - 1] +
                             q[k - 1] - maxx);
        }
      }
    }
    printf("%d\n", ans);
  }
}
