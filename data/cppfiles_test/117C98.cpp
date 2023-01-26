#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  auto solve = []() {
    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};
    int n, m;
    cin >> n >> m;
    auto valid = [n, m](int x, int y) {
      return x >= 0 && x < n && y >= 0 && y < m;
    };
    vector<vector<char> > a(n, vector<char>(m));
    vector<vector<bool> > win(n, vector<bool>(m, false));
    vector<vector<int> > cnt(n, vector<int>(m, 0));
    int sx, sy;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> a[i][j];
        if (a[i][j] == 'L') sx = i, sy = j;
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (a[i][j] == '.') {
          for (int d = 0; d < 4; ++d) {
            int ii = i + dx[d];
            int jj = j + dy[d];
            cnt[i][j] += valid(ii, jj) && a[ii][jj] != '#';
          }
        }
      }
    }
    queue<pii> q;
    q.emplace(sx, sy);
    win[sx][sy] = true;
    while (q.size()) {
      auto [x, y] = q.front();
      q.pop();
      for (int i = 0; i < 4; ++i) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (!valid(xx, yy) || a[xx][yy] == '#' || win[xx][yy]) continue;
        --cnt[xx][yy];
        if (cnt[xx][yy] <= 1) {
          win[xx][yy] = true, a[xx][yy] = '+', q.emplace(xx, yy);
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << a[i][j];
      }
      cout << '\n';
    }
  };
  int t;
  cin >> t;
  while (t--) solve();
}
