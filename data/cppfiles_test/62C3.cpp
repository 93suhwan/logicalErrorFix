#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  srand(chrono::steady_clock::now().time_since_epoch().count());
  ;
  long long n, m, q;
  cin >> n >> m >> q;
  vector<vector<bool>> g(n, vector<bool>(m));
  long long ans = n * m;
  long long h = 1, w = 2;
  long long flag = 0;
  while (h <= n && w <= m) {
    ans += (n - h + 1) * (m - w + 1);
    if (flag == 0)
      h++;
    else
      w++;
    flag = 1 - flag;
  }
  h = 2;
  w = 1;
  flag = 1;
  while (h <= n && w <= m) {
    ans += (n - h + 1) * (m - w + 1);
    if (flag == 0)
      h++;
    else
      w++;
    flag = 1 - flag;
  }
  while (q--) {
    long long x, y;
    cin >> x >> y;
    x--;
    y--;
    long long xori = x, yori = y;
    long long delta = -1;
    long long a1 = 1;
    flag = 0;
    while (true) {
      if (flag == 0)
        x--;
      else
        y--;
      flag = 1 - flag;
      if (0 <= x && x < n && 0 <= y && y < m && !g[x][y]) {
        a1++;
      } else
        break;
    }
    flag = 0;
    x = xori;
    y = yori;
    long long a2 = 1;
    while (true) {
      if (flag == 0)
        y++;
      else
        x++;
      flag = 1 - flag;
      if (0 <= x && x < n && 0 <= y && y < m && !g[x][y]) {
        a2++;
      } else
        break;
    }
    delta += a1 * a2;
    a1 = 1;
    flag = 0;
    x = xori;
    y = yori;
    while (true) {
      if (flag == 0)
        y--;
      else
        x--;
      flag = 1 - flag;
      if (0 <= x && x < n && 0 <= y && y < m && !g[x][y]) {
        a1++;
      } else
        break;
    }
    a2 = 1;
    flag = 0;
    x = xori;
    y = yori;
    while (true) {
      if (flag == 0)
        x++;
      else
        y++;
      flag = 1 - flag;
      if (0 <= x && x < n && 0 <= y && y < m && !g[x][y]) {
        a2++;
      } else
        break;
    }
    delta += a1 * a2;
    x = xori;
    y = yori;
    if (g[x][y]) {
      ans += delta;
      g[x][y] = false;
    } else {
      ans -= delta;
      g[x][y] = true;
    }
    cout << ans << '\n';
  }
}
