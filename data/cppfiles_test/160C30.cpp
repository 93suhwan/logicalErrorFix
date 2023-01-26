#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, x1, y1, x2, y2;
  cin >> n >> m >> x1 >> y1 >> x2 >> y2;
  int dx = 1, dy = 1, ans = 0;
  while (x1 != x2 && y1 != y2) {
    if (x1 == n) dx = -1;
    if (x1 == 0) dx = 1;
    if (y1 == m) dy = -1;
    if (y1 == 0) dy = 1;
    x1 += dx;
    y1 += dy;
    ans++;
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
