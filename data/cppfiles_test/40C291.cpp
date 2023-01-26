#include <bits/stdc++.h>
using namespace std;
int a[3][100010], sum[3][100010];
int main() {
  int t, m;
  cin >> t;
  while (t--) {
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) scanf("%d", &a[1][i]);
    for (int i = 1; i <= m; i++) scanf("%d", &a[2][i]);
    sum[1][0] = 0;
    sum[2][0] = 0;
    for (int i = 1; i <= m; i++) sum[1][i] = sum[1][i - 1] + a[1][i];
    for (int i = 1; i <= m; i++) sum[2][i] = sum[2][i - 1] + a[2][i];
    int res = 1000000000;
    for (int i = 1; i <= m; i++) {
      res = min(res, max(sum[1][m] - sum[1][i], sum[2][i - 1]));
    }
    printf("%d\n", res);
  }
}
