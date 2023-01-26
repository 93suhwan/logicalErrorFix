#include <bits/stdc++.h>
using namespace std;
const int mm = 2e5 + 100;
int d[mm], sum[3000][3000], num[3000], ans[3000][3000];
int n, m;
int main() {
  int i, j, t, a, b, c, p, k, kk, z;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &k);
    memset(sum, 0, sizeof(sum));
    memset(ans, 0, sizeof(ans));
    for (i = 1; i <= n; i++) scanf("%d", &d[i]);
    for (i = n; i >= 1; i--) {
      num[i] = i - d[i];
      for (j = 0; j <= n; j++) {
        if (num[i] == j)
          sum[i][j] = sum[i + 1][j] + 1;
        else
          sum[i][j] = sum[i + 1][j];
      }
    }
    int o = 0x3f3f3f3f;
    if (sum[1][0] >= k) o = min(o, 0);
    for (i = 1; i <= n; i++) ans[0][i] = sum[1][i];
    for (i = 1; i <= n; i++) {
      for (j = 0; j <= i; j++) {
        if (j == 0)
          ans[i][j] = sum[1][0];
        else
          ans[i][j] = ans[i - 1][j];
        if (j == 0) continue;
        ans[i][j] =
            max(ans[i][j], ans[i - 1][j - 1] - sum[i][j - 1] + sum[i + 1][j]);
        if (ans[i][j] >= k) o = min(o, j);
      }
    }
    if (o != 0x3f3f3f3f)
      printf("%d\n", o);
    else
      printf("-1\n");
  }
}
