#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = {+1, -1, +0, +0};
int dy[4] = {+0, +0, +1, -1};
int main() {
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m, '#'));
    int lx, ly;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        if (a[i][j] == 'L') {
          lx = i;
          ly = j;
        }
      }
    }
    vector<vector<int>> p(n, vector<int>(m));
    p[lx][ly] = +1;
    queue<pii> q;
    q.push({lx, ly});
    auto out = [&](int x, int y) {
      return (min(x, y) < 0 || x >= n || y >= m);
    };
    vector<vector<int>> was(n, vector<int>(m));
    was[lx][ly] = 1;
    while (!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++) {
        int ux = x + dx[i];
        int uy = y + dy[i];
        if (out(ux, uy) || a[ux][uy] != '.') continue;
        int cnt = 0;
        for (int k = 0; k < 4; k++) {
          int zx = ux + dx[k];
          int zy = uy + dy[k];
          if (out(zx, zy) || was[zx][zy] || a[zx][zy] == '#') continue;
          cnt++;
        }
        if (!was[ux][uy] && cnt <= 1) {
          was[ux][uy] = true;
          q.push({ux, uy});
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (was[i][j] && a[i][j] != 'L') {
          a[i][j] = '+';
        }
        cout << a[i][j];
      }
      cout << '\n';
    }
  }
  return 0;
}
