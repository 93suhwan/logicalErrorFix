#include <bits/stdc++.h>
using namespace std;
const int maxn = 405, inf = 1000000000;
int T, n, m;
int a[maxn][maxn], sum[maxn][maxn];
string s;
inline int calc(int a, int b, int c, int d) {
  return sum[c][d] - sum[c][b - 1] - sum[a - 1][d] + sum[a - 1][b - 1];
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
      cin >> s;
      for (int j = 0; j < m; j++) a[i][j + 1] = s[j] == '1';
    }
    int ans = inf;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
    for (int i = 1; i <= n; i++)
      for (int j = i + 4; j <= n; j++) {
        int mn = inf;
        for (int k = 4; k <= m; k++) {
          mn = min(mn, (j - i - 1) - calc(i + 1, k - 3, j - 1, k - 3) +
                           calc(i + 1, k - 2, j - 1, k - 1) +
                           (a[i][k - 1] == 0) + (a[i][k - 2] == 0) +
                           (a[j][k - 1] == 0) + (a[j][k - 2] == 0));
          ans = min(ans, mn + (j - i - 1) - calc(i + 1, k, j - 1, k));
          mn += (a[i][k] == 0) + (a[j][k] == 0) + calc(i + 1, k, j - 1, k);
        }
      }
    printf("%d\n", ans);
  }
  return 0;
}
