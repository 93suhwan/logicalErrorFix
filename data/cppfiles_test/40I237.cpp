#include <bits/stdc++.h>
using namespace std;
const int M = (int)1e5;
const int N = (int)1e5;
const double eps = 1e-6;
const int inf = 0x3f3f3f3f;
const long long mod = (long long)1e9 + 7;
int n = 2, m;
int a[2][M + 5];
void work() {
  scanf("%d", &m);
  for (int i = 1; i <= n; ++i) {
    a[1][m + 1] = a[1][m], a[2][m + 1] = a[2][m];
    for (int j = 1; j <= m; ++j) scanf("%d", &a[i][j]), a[i][j] += a[i][j - 1];
  }
  int ans = inf;
  for (int i = 1; i <= m; ++i) {
    ans = min(ans, max(a[2][i - 1], a[1][m] - a[1][i]));
  }
  printf("%d\n", ans);
}
int main() {
  int T;
  scanf("%d", &T);
  for (int ca = 1; ca <= T; ++ca) {
    work();
  }
  return 0;
}
