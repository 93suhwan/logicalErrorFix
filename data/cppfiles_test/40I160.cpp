#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[5][N], sum[5][N];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= 2; i++) {
      for (int j = 1; j <= n; j++) {
        scanf("%d", &a[i][j]);
        sum[i][j] = sum[i][j - 1] + a[i][j];
      }
    }
    int res = min(sum[1][n] - a[1][1], sum[2][n] - a[2][n]);
    for (int i = 2; i < n; i++) {
      res = min(res, sum[1][n] - sum[1][i]);
      res = min(res, sum[2][i + 1]);
    }
    printf("%d\n", res);
  }
  return 0;
}
