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
    while (!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;
      was[x][y] = 1;
      q.pop();
      int e = 0;
      int c = 0;
      for (int i = 0; i < 4; i++) {
        int ux = x + dx[i];
        int uy = y + dy[i];
        if (out(ux, uy)) {
          continue;
        }
        if (a[ux][uy] != '#') {
          c++;
          e |= (p[ux][uy] == 1);
          if (!was[ux][uy]) {
            q.push({ux, uy});
            was[ux][uy] = 1;
          }
        }
      }
      if (c <= 2 && e) {
        p[x][y] = 1;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (p[i][j] == 1 && a[i][j] != 'L') {
          a[i][j] = '+';
        }
        cout << a[i][j];
      }
      cout << '\n';
    }
  }
  return 0;
}
