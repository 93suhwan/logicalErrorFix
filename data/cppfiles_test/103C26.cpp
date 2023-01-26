#include <bits/stdc++.h>
using namespace std;
const int N = 2001;
int f[N][N], n, m, tim[N][N];
int p[N][N];
int ans = 0, ans1, ans2;
int cl, cr, cnt;
inline void dfs(int x, int y) {
  tim[x][y] = ++cnt;
  int ux = x, uy = y;
  if (p[x][y] == 1) ++uy;
  if (p[x][y] == 2) --uy;
  if (p[x][y] == 3) --ux;
  if (p[x][y] == 4) ++ux;
  if (ux < 1 || ux > n || uy < 1 || uy > m)
    f[x][y] = 1;
  else if (tim[ux][uy]) {
    if (!f[ux][uy]) {
      cl = tim[ux][uy], cr = tim[x][y];
      int cyc = cr - cl + 1;
      f[x][y] = cyc;
    } else {
      f[x][y] = 1 + f[ux][uy];
    }
  } else {
    dfs(ux, uy);
    if (tim[x][y] >= cl && tim[x][y] <= cr)
      f[x][y] = f[ux][uy];
    else
      f[x][y] = 1 + f[ux][uy];
  }
  if (f[x][y] > ans) {
    ans = f[x][y];
    ans1 = x, ans2 = y;
  }
}
signed main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    cnt = 0;
    cl = 0, cr = 0;
    ans = ans1 = ans2 = 0;
    for (int i = 1; i <= n; ++i) {
      string str;
      cin >> str;
      for (int j = 0; j < str.size(); ++j) {
        int xx = 0;
        if (str[j] == 'R')
          xx = 1;
        else if (str[j] == 'L')
          xx = 2;
        else if (str[j] == 'U')
          xx = 3;
        else
          xx = 4;
        p[i][j + 1] = xx;
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (!tim[i][j]) dfs(i, j);
      }
    }
    cout << ans1 << " " << ans2 << " " << ans << "\n";
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) f[i][j] = 0, tim[i][j] = 0;
  }
  return 0;
}
