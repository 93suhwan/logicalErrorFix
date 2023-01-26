#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500;
char mp[MAXN][MAXN];
int f[MAXN][MAXN];
int cal(int a, int b, int c, int d) {
  return f[a][b] + f[c - 1][d - 1] - f[a][d - 1] - f[c - 1][b];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t, n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> mp[i][j];
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + mp[i][j] - '0';
      }
    }
    int ans = 16;
    for (int x = 1; x <= n; x++) {
      for (int y = 1; y <= m; y++) {
        for (int i = x + 4; i <= n; i++) {
          for (int j = y + 3; j <= m; j++) {
            int jia_l = mp[x][y] + mp[i][y] - '0' - '0';
            int jia_r = mp[i][j] + mp[x][j] - '0' - '0';
            int wai = cal(i, j, x, y);
            int nei = cal(i - 1, j - 1, x + 1, y + 1);
            int len = i - x - 1;
            int width = j - y - 1;
            int num = nei + 2 * (width + len) - (wai - nei - jia_l - jia_r);
            if (ans < num) break;
            ans =
                min(ans, nei + 2 * (len + width) - (wai - nei - jia_l - jia_r));
          }
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
