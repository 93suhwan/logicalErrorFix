#include <bits/stdc++.h>
using namespace std;
const int maxn = 440;
int T, n, m, cnt[maxn][maxn], a[maxn], b[maxn], c[maxn], d[maxn], suma[maxn],
    md[maxn], ans;
char s[maxn][maxn];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
      scanf("%s", s[i] + 1);
    }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) cnt[i][j] = cnt[i - 1][j] + (s[i][j] == '1');
    ans = n * m;
    for (int r1 = 1; r1 <= n; r1++) {
      for (int r2 = r1 + 4; r2 <= n; r2++) {
        for (int i = 1; i <= m; i++) {
          int tt = r2 - r1 - 1;
          int cc = cnt[r2 - 1][i] - cnt[r1][i];
          a[i] = cc + (s[r1][i] == '0') + (s[r2][i] == '0');
          b[i] = tt - cc;
          suma[i] = suma[i - 1] + a[i];
          c[i] = b[i] + suma[i - 1];
          d[i] = suma[i] - b[i];
          md[i] = -(1 << 29);
          md[i] = max(md[i], d[i]);
          if (i >= 4) ans = min(ans, c[i] - md[i - 3]);
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
