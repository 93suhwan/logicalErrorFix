#include <bits/stdc++.h>
using namespace std;
const int N = 410;
char a[N][N];
int n, m, sum[N][N], best[N];
int get(int x1, int x2, int y1, int y2) {
  return sum[x2][y2] + sum[x1 - 1][y1 - 1] - sum[x1 - 1][y2] - sum[x2][y1 - 1];
}
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) scanf("%s", a[i] + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      sum[i][j] =
          sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + (a[i][j] == '1');
    }
  }
  int ans = 1e9;
  for (int i = 1; i + 4 <= n; i++) {
    for (int j = i + 4; j <= n; j++) {
      best[m + 1] = 1e9;
      for (int k = m; k >= 1; k--) {
        best[k] = min(best[k + 1], (k - 1 - get(i, i, 1, k - 1)) +
                                       (k - 1 - get(j, j, 1, k - 1)) +
                                       get(i + 1, j - 1, 1, k - 1) +
                                       (j - i - 1 - get(i + 1, j - 1, k, k)));
      }
      for (int k = 1; k + 3 <= m; k++) {
        ans = min(ans, best[k + 3] -
                           (get(i + 1, j - 1, 1, k) + (k - get(i, i, 1, k)) +
                            (k - get(j, j, 1, k))) +
                           (j - i - 1 - get(i + 1, j - 1, k, k)));
      }
    }
  }
  cout << ans << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
