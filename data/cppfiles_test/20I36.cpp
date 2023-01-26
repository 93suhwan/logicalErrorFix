#include <bits/stdc++.h>
using namespace std;
const int N = 400 + 5, INF = 1e9 + 5;
int t, n, m, prefix[N][N], cnts[5], ans;
char c;
bool arr[N][N];
int getcnt(int x, int y, int x2, int y2) {
  return prefix[x2][y2] - (prefix[x2][y - 1] + prefix[x - 1][y2]) +
         prefix[x - 1][y - 1];
}
void solve() {
  ans = INF;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> c;
      arr[i][j] = (c == '1');
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] -
                     prefix[i - 1][j - 1] + arr[i][j];
    }
  }
  for (int a = 5; a <= 5; a++) {
    for (int i = 1; i <= n - a + 1; i++) {
      cnts[1] = cnts[2] = cnts[3] = cnts[4] = INF;
      for (int j = 1; j <= m; j++) {
        ans = min(ans, min(cnts[3], cnts[4]) +
                           ((a - 2) - getcnt(i + 1, j, i + a - 2, j)));
        cnts[4] = min(cnts[4], min(cnts[3], cnts[4]) +
                                   getcnt(i + 1, j, i + a - 2, j) + !arr[i][j] +
                                   !arr[i + a - 1][j]);
        cnts[3] = min(INF, cnts[2] + getcnt(i + 1, j, i + a - 2, j) +
                               !arr[i][j] + !arr[i + a - 1][j]);
        cnts[2] = min(INF, cnts[1] + getcnt(i + 1, j, i + a - 2, j) +
                               !arr[i][j] + !arr[i + a - 1][j]);
        cnts[1] = min(INF, ((a - 2) - getcnt(i + 1, j, i + a - 2, j)));
      }
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    solve();
  }
}
