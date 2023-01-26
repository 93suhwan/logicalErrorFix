#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
const int N = 10005;
int f[N][2005];
int main() {
  int _;
  scanf("%d", &_);
  for (int j = 1; j <= 1000; j++) {
    f[0][j] = INF;
  }
  while (_--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      for (int j = 0; j <= 2000; j++) {
        f[i][j] = INF;
      }
      for (int j = 0; j <= 2000; j++) {
        f[i][max(0, j - x)] = min(f[i][max(0, j - x)], f[i - 1][j] + x);
        if (j + x <= 2000)
          f[i][j + x] = min(f[i][j + x], max(0, f[i - 1][j] - x));
      }
    }
    int ans = INF;
    for (int j = 0; j <= 1000; j++) {
      ans = min(ans, f[n][j] + j);
    }
    printf("%d\n", ans);
  }
  return 0;
}
