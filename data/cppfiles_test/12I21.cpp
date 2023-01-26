#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2020;
const int inf = 1e9;
char a[N][N];
int d[N][N], px[N][N], py[N][N];
set<pair<int, pair<int, int>>> s;
pair<int, int> dir[8] = {make_pair(-1, -1), make_pair(-1, 0), make_pair(-1, 1),
                         make_pair(0, 1),   make_pair(1, 1),  make_pair(1, 0),
                         make_pair(1, -1),  make_pair(0, -1)};
void init() {}
int dist(int x1, int y1, int x2, int y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i <= n; ++i) {
    scanf("%s", a[i]);
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      d[i][j] = inf;
      if (a[i][j] == '1') {
        d[i][j] = 0;
        px[i][j] = i;
        py[i][j] = j;
        s.insert(make_pair(d[i][j], make_pair(i, j)));
      }
    }
  }
  while (!s.empty()) {
    int x = s.begin()->second.first, y = s.begin()->second.second;
    s.erase(s.begin());
    for (int i = 0; i < 8; ++i) {
      int nx = x + dir[i].first, ny = y + dir[i].second;
      if (nx >= 0 && nx <= n && ny >= 0 && ny <= m) {
        if (d[nx][ny] > dist(px[x][y], py[x][y], nx, ny)) {
          s.erase(make_pair(d[nx][ny], make_pair(nx, ny)));
          d[nx][ny] = dist(px[x][y], py[x][y], nx, ny);
          px[nx][ny] = px[x][y];
          py[nx][ny] = py[x][y];
          s.insert(make_pair(d[nx][ny], make_pair(nx, ny)));
        }
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      ans += d[i][j];
    }
  }
  printf("%lld\n", ans);
}
int main() {
  init();
  int t = 1;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
