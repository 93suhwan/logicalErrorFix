#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const int N = 2 * 1e3 + 10;
const long double eps = 1e-9;
const int mod = 998244353;
char a[N][N];
int d[N][N], v[N][N], n, m;
bool used[N][N];
void nxt(char c, int &x, int &y) {
  if (c == 'U')
    --x;
  else if (c == 'D')
    ++x;
  else if (c == 'R')
    ++y;
  else
    --y;
  return;
}
int cx, cy;
void fillcycle() {
  int x = cx, y = cy, cnt = 1;
  nxt(a[x][y], x, y);
  while (!(x == cx && y == cy)) {
    ++cnt;
    nxt(a[x][y], x, y);
  }
  x = cx, y = cy;
  d[x][y] = cnt;
  v[x][y] = 2;
  nxt(a[x][y], x, y);
  while (!(x == cx && y == cy)) {
    v[x][y] = 2;
    d[x][y] = cnt;
    nxt(a[x][y], x, y);
  }
  return;
}
void cycle(int x, int y) {
  while (!(x <= 0 || y <= 0 || x > n || y > m) && !used[x][y]) {
    v[x][y] = 0;
    used[x][y] = true;
    nxt(a[x][y], x, y);
  }
  if (x <= 0 || y <= 0 || x > n || y > m) return;
  if (v[x][y] != 0) return;
  cx = x;
  cy = y;
  fillcycle();
  return;
}
void gg(int x, int y) {
  while (x > 0 && y > 0 && x <= n && y <= m && v[x][y] == 0) {
    v[x][y] = 1;
    nxt(a[x][y], x, y);
  }
  return;
}
void dfs(int x, int y) {
  int tx = x, ty = y;
  nxt(a[x][y], tx, ty);
  stack<pair<int, int> > vc;
  vc.push({x, y});
  int c = 1;
  while (!(tx <= 0 || ty <= 0 || x > n || y > m) && d[tx][ty] == -1) {
    vc.push({tx, ty});
    nxt(a[tx][ty], tx, ty);
  }
  if (tx <= 0 || ty <= 0 || x > n || y > m)
    c = 1;
  else
    c = d[tx][ty] + 1;
  while (!vc.empty()) {
    tx = vc.top().first;
    ty = vc.top().second;
    vc.pop();
    d[tx][ty] = c;
    ++c;
  }
  return;
}
void solve() {
  cin >> n >> m;
  for (int i = 0; i <= n + 1; ++i) {
    fill(d[i], d[i] + m + 1, -1);
    fill(used[i], used[i] + m + 1, false);
    fill(v[i], v[i] + m + 1, -1);
    if (i > 0 && i <= n) {
      for (int j = 1; j <= m; ++j) cin >> a[i][j];
    }
  }
  for (int i = 0; i <= n + 1; ++i) d[i][0] = d[i][m + 1] = 0;
  for (int i = 0; i <= m + 1; ++i) d[0][i] = d[n + 1][i] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (!used[i][j]) {
        cycle(i, j);
        gg(i, j);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (d[i][j] == -1) dfs(i, j);
    }
  }
  int x = 1, y = 1, ans = -2;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (ans < d[i][j]) ans = d[i][j], x = i, y = j;
    }
  }
  cout << x << " " << y << " " << ans << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
