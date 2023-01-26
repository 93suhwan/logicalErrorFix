#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> sum(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] +
                  (a[i - 1][j - 1] == '1');
    }
  auto query1 = [&](int x1, int y1, int x2, int y2) {
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] +
           sum[x1 - 1][y1 - 1];
  };
  auto query0 = [&](int x1, int y1, int x2, int y2) {
    return (y2 - y1 + 1) * (x2 - x1 + 1) - query1(x1, y1, x2, y2);
  };
  int ans = 16;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 4; j <= n; j++) {
      int mi = INT32_MAX / 2;
      for (int r = 1; r <= m; r++) {
        if (r - 3 >= 1) {
          int l = r - 3;
          int res = 0;
          res += query0(i + 1, l, j - 1, l);
          res += query1(i + 1, l + 1, j - 1, l + 2);
          res += query0(i, l + 1, i, l + 2);
          res += query0(j, l + 1, j, l + 2);
          mi = min(res, mi);
          ans = min(ans, mi + query0(i + 1, r, j - 1, r));
          mi += query1(i + 1, r, j - 1, r) + (a[i - 1][r - 1] != '1') +
                (a[j - 1][r - 1] != '1');
        }
      }
    }
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
