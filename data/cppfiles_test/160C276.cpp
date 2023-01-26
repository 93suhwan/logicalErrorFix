#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, xb, yb, xd, yd;
  cin >> n >> m >> yb >> xb >> yd >> xd;
  int ans = 0;
  int x = 1, y = 1;
  while (true) {
    if (xb == xd) break;
    if (yb == yd) break;
    if (xb == m) x = -x;
    if (yb == n) y = -y;
    xb += x;
    yb += y;
    ++ans;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
