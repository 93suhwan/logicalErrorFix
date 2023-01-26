#include <bits/stdc++.h>
using namespace std;
const int N = 500;
int n, m;
int a[N][N];
int x[N][N], y[N][N], s[N][N];
void solve() {
  memset(a, 0, sizeof(a));
  memset(x, 0, sizeof(x));
  memset(y, 0, sizeof(y));
  memset(s, 0, sizeof(s));
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    string str;
    cin >> str;
    str = " " + str;
    for (int j = 1; j <= m; j++) {
      a[i][j] = str[j] - '0';
      x[i][j] = a[i][j] + x[i][j - 1];
      if (a[i][j] == 1) {
        s[i][j] = 1 + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
      } else
        s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      y[j][i] = y[j - 1][i] + a[j][i];
    }
  }
  int ans = 16;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 4; j <= n; j++) {
      for (int k = 1; k <= m; k++) {
        for (int z = k + 3; z <= m; z++) {
          int all = 0;
          int x2 = j - 1, y2 = z - 1, x1 = i + 1, y1 = k + 1;
          int c1 =
              s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
          int c2 = z - k - 1 - (x[i][z - 1] - x[i][k]);
          int c3 = z - k - 1 - (x[j][z - 1] - x[j][k]);
          int c4 = j - i - 1 - (y[j - 1][k] - y[i][k]);
          int sum = c1 + c2 + c3 + c4;
          if (sum > 16) break;
          int c5 = j - i - 1 - (y[j - 1][z] - y[i][z]);
          sum += c5;
          ans = min(ans, sum);
        }
      }
    }
  }
  cout << ans << endl;
}
int main() {
  int Case;
  scanf("%d", &Case);
  while (Case--) solve();
  return 0;
}
