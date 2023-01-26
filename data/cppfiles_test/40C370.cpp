#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 2e5 + 10, mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
using namespace std;
int a[3][N], ans[3][N];
int n = 2, m;
signed main(void) {
  std::ios::sync_with_stdio(false);
  ;
  int t;
  cin >> t;
  while (t--) {
    cin >> m;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) cin >> a[i][j];
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) ans[i][j] = ans[i][j - 1] + a[i][j];
    int res = INF;
    for (int i = 1; i <= m; i++)
      res = min(res, max(ans[1][m] - ans[1][i], ans[2][i - 1]));
    cout << res << endl;
  }
  return 0;
}
