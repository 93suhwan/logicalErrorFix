#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
long long n, m, a[410][410], sum[410][410], cur[410], ans = 1000000000000000000;
string s;
long long solve(long long x, long long y) {
  long long i, j, curs = 0, mn = 1000000000000000000, ret = 1000000000000000000;
  for (i = 1; i <= n; i++) {
    cur[i] = curs;
    curs += (1 - a[i][x]) + (1 - a[i][y]) + sum[i][y - 1] - sum[i][x];
  }
  for (i = n - 4; i > 0; i--) {
    mn =
        min(mn, cur[i + 4] + (y - x - 1 - (sum[i + 4][y - 1] - sum[i + 4][x])));
    ret = min(ret, mn - cur[i + 1] + y - x - 1 - (sum[i][y - 1] - sum[i][x]));
  }
  return ret;
}
int main() {
  long long i, j, T;
  scanf("%lld", &T);
  while (T--) {
    cin >> n >> m;
    for (i = 0; i < n; i++) {
      cin >> s;
      for (j = 0; j < m; j++) {
        a[i + 1][j + 1] = (s[j] - '0');
      }
    }
    ans = 1000000000000000000;
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        sum[i][j] = sum[i][j - 1] + a[i][j];
      }
    }
    for (i = 1; i <= m; i++) {
      for (j = i + 3; j <= m; j++) {
        ans = min(ans, solve(i, j));
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
