#include <bits/stdc++.h>
using namespace std;
int main() {
  long long tcs;
  cin >> tcs;
  while (tcs--) {
    long long n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    for (long long i = 0; i < n; ++i)
      for (long long j = 0; j < m; ++j) scanf(" %c ", &mat[i][j]);
    vector<vector<long long>> vis(n, vector<long long>(m, 0));
    long long sx, sy;
    for (long long i = 0; i < n; ++i)
      for (long long j = 0; j < m; ++j)
        if (mat[i][j] == 'L') sx = i, sy = j;
    queue<pair<long long, long long>> q;
    function<bool(long long, long long)> preveri = [&](long long x,
                                                       long long y) {
      if (x < 0 or x >= n) return false;
      if (y < 0 or y >= m) return false;
      if (mat[x][y] == '#') return false;
      return true;
    };
    function<void(long long, long long)> dodaj = [&](long long x, long long y) {
      if (!preveri(x, y)) return;
      if (vis[x][y]) return;
      long long pr = 0, zag = 0;
      long long dx, dy;
      dx = x + 1, dy = y;
      if (preveri(dx, dy)) {
        ++pr;
        if (vis[dx][dy]) ++zag;
      }
      dx = x - 1, dy = y;
      if (preveri(dx, dy)) {
        ++pr;
        if (vis[dx][dy]) ++zag;
      }
      dx = x, dy = y + 1;
      if (preveri(dx, dy)) {
        ++pr;
        if (vis[dx][dy]) ++zag;
      }
      dx = x, dy = y - 1;
      if (preveri(dx, dy)) {
        ++pr;
        if (vis[dx][dy]) ++zag;
      }
      if (mat[x][y] == 'L' or zag >= pr - 1)
        q.push(make_pair(x, y)), vis[x][y] = 1;
    };
    dodaj(sx, sy);
    while (q.size()) {
      auto [x, y] = q.front();
      q.pop();
      long long dx, dy;
      dx = x + 1, dy = y;
      dodaj(dx, dy);
      dx = x - 1, dy = y;
      dodaj(dx, dy);
      dx = x, dy = y + 1;
      dodaj(dx, dy);
      dx = x, dy = y - 1;
      dodaj(dx, dy);
    }
    for (long long i = 0; i < n; ++i) {
      for (long long j = 0; j < m; ++j) {
        if (sx == i and sy == j)
          cout << mat[i][j];
        else if (vis[i][j])
          cout << '+';
        else
          cout << mat[i][j];
      }
      cout << '\n';
    }
  }
}
