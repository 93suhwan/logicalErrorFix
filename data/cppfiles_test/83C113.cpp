#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
int t, n, ans;
int f[N], g[N][N];
char str[N];
int main() {
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    scanf("%d", &n);
    scanf("%s", str + 1);
    for (int j = n - 1; j >= 1; j--) g[n][j] = (str[n] == str[j]);
    for (int j = n - 1; j >= 1; j--)
      for (int k = j - 1; k >= 1; k--) {
        if (str[j] == str[k])
          g[j][k] = g[j + 1][k + 1] + 1;
        else
          g[j][k] = 0;
      }
    f[1] = ans = n;
    for (int j = 2; j <= n; j++) {
      f[j] = n - j + 1;
      for (int k = 1; k < j; k++) {
        if (j + g[j][k] > n + 1) continue;
        if (str[j + g[j][k]] > str[k + g[j][k]])
          f[j] = max(f[j], f[k] + n - j - g[j][k] + 1);
      }
      ans = max(ans, f[j]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
