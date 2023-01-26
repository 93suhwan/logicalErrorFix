#include <bits/stdc++.h>
using namespace std;
const int N = 409;
int n, m, a[N][N];
int getBlocks(int x1, int y1, int x2, int y2) {
  return a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1];
}
int solve(int i, int j, int a, int b) {
  int cntEmpty = getBlocks(i + 1, j + 1, i + a - 2, j + b - 2);
  int cntBlocks1 = (2 * b - 4) - getBlocks(i, j + 1, i, j + b - 2) -
                   getBlocks(i + a - 1, j + 1, i + a - 1, j + b - 2);
  int cntBlocks2 = (2 * a - 4) - getBlocks(i + 1, j, i + a - 2, j) -
                   getBlocks(i + 1, j + b - 1, i + a - 2, j + b - 1);
  return cntBlocks1 + cntBlocks2 + cntEmpty;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    ;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        char c;
        cin >> c;
        a[i][j] = (c == '1');
        a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
      }
    int ans = 1e9;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        for (int a = 5; i + a - 1 <= n; a++)
          for (int b = 4; j + b - 1 <= m; b++) {
            int cur = solve(i, j, a, b);
            if (cur - (a - 1 -
                       getBlocks(i + 1, j + b - 1, i + a - 2, j + b - 1)) >
                ans)
              break;
            ans = min(ans, cur);
          }
    cout << ans << "\n";
  }
}
