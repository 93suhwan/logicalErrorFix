#include <bits/stdc++.h>
using namespace std;
int arr[1005][1005];
pair<int, int> dp[1005][1005];
pair<int, int> findset(pair<int, int> x) {
  return (x == dp[x.first][x.second])
             ? x
             : dp[x.first][x.second] = findset(dp[x.first][x.second]);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, h, i, j, k, a, b, q, d, c, cnt, cur2, sum = 0, sum2 = 0, t, maxn,
                                                  x = 0, y, z, ans, ans2, idx;
  string str = "", str2, str3;
  char ch;
  cin >> n >> m >> q;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  for (i = 0; i < m; i++) dp[n][i] = make_pair(n, i);
  for (i = n - 1; i >= 0; i--) {
    for (j = 0; j < m; j++) {
      if (arr[i][j] == 2) {
        dp[i][j] = dp[i + 1][j];
      } else
        dp[i][j] = make_pair(i, j);
    }
  }
  for (i = 0; i < q; i++) {
    cin >> a;
    a--;
    x = 0;
    y = a;
    while (x != n) {
      if (arr[x][y] == 2) {
        pair<int, int> temp = findset(make_pair(x, y));
        x = temp.first;
        y = temp.second;
      } else if (arr[x][y] == 1) {
        arr[x][y] = 2;
        dp[x][y] = dp[x + 1][y];
        if (x && arr[x - 1][y] == 2) dp[x - 1][y] = dp[x + 1][y];
        y++;
      } else {
        arr[x][y] = 2;
        dp[x][y] = dp[x + 1][y];
        if (x && arr[x - 1][y] == 2) dp[x - 1][y] = dp[x + 1][y];
        y--;
      }
    }
    cout << y + 1 << " ";
  }
}
