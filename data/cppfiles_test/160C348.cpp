#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, sx, sy, tx, ty;
void solve() {
  int ans = 0;
  int dx = 1, dy = 1;
  while (sx != tx && sy != ty) {
    ans++;
    int nx = sx + dx;
    int ny = sy + dy;
    if (nx == 0 || nx == n + 1) {
      dx = -dx;
      nx = sx + dx;
    }
    if (ny == 0 || ny == m + 1) {
      dy = -dy;
      ny = sy + dy;
    }
    sx = nx;
    sy = ny;
  }
  cout << ans << endl;
}
signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m >> sx >> sy >> tx >> ty;
    solve();
  }
}
