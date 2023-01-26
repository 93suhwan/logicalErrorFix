#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000;
int n, m, cnt;
int ans1, ans2, ans;
int dist[maxn][maxn], tim[maxn][maxn];
int a[maxn][maxn];
int cl = 0, cr = 0;
int g(char c) {
  if (c == 'R') return 1;
  if (c == 'L') return 2;
  if (c == 'U') return 3;
  if (c == 'D') return 4;
}
inline void dfs(int x, int y) {
  tim[x][y] = ++cnt;
  int x1 = x, y1 = y;
  if (a[x][y] == 1) {
    ++y1;
  }
  if (a[x][y] == 2) --y1;
  if (a[x][y] == 3) --x1;
  if (a[x][y] == 4) ++x1;
  if (x1 < 0 || y1 < 0 || x1 >= n || y1 >= m) {
    dist[x][y] = 1;
  } else if (tim[x1][y1]) {
    if (dist[x1][y1] == 0) {
      int cyc = tim[x][y] - tim[x1][y1] + 1;
      cl = tim[x1][y1];
      cr = tim[x][y];
      dist[x][y] = cyc;
    } else {
      dist[x][y] = 1 + abs(dist[x1][y1]);
    }
  } else {
    dfs(x1, y1);
    if (tim[x][y] >= cl && tim[x][y] <= cr) {
      dist[x][y] = dist[x1][y1];
    } else {
      dist[x][y] = 1 + abs(dist[x1][y1]);
    }
  }
  if (dist[x][y] > ans) {
    ans = dist[x][y];
    ans1 = x + 1, ans2 = y + 1;
  }
}
signed main() {
  int test;
  cin >> test;
  for (int ee = 0; ee < test; ++ee) {
    cin >> n >> m;
    cl = 0, cr = 0;
    ans1 = ans2 = ans = 0;
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      for (int j = 0; j < m; ++j) {
        a[i][j] = g(s[j]);
      }
    }
    cnt = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (tim[i][j]) continue;
        dfs(i, j);
      }
    }
    cout << ans1 << ' ' << ans2 << ' ' << ans << '\n';
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) dist[i][j] = tim[i][j] = 0;
  }
}
