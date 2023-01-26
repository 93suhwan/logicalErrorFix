#include <bits/stdc++.h>
using namespace std;
int n, m, dp[1005][1005], ans[1005][1005], cnt;
int main() {
  scanf("%d%d", &n, &m);
  if (n <= m) {
    printf("1\n");
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++) printf("1 ");
    return 0;
  }
  int res = 1;
  while (res < n) {
    cnt++;
    int t = 1;
    while (res <= n && t < m) {
      for (int i = 1; i <= m && i + res - 1 <= n; i++)
        for (int j = i + 1; j <= m && j + res - 1 <= n; j++)
          ans[res + i - 1][res + j - 1] = cnt + 1;
      for (int i = res + m; i <= n; i++)
        for (int j = 1; j <= m && j + res - 1 <= n; j++)
          ans[j + res - 1][i] = cnt;
      t++;
      res += m;
    }
  }
  printf("%d\n", cnt + 1);
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) printf("%d ", ans[i][j]);
  return 0;
}
