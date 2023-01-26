#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, xb, yb, xd, yd;
  cin >> n >> m >> yb >> xb >> yd >> xd;
  int ans;
  if (xb == xd || yb == yd) {
    ans = 0;
  } else if (xb > xd) {
    if (yd < yb) {
      ans = (2 * (abs(m - xb))) + abs(xd - xb);
    } else {
      ans = yd - yb;
    }
  } else if (xd > xb) {
    if (yd < yb) {
      ans = xd - xb;
    } else {
      ans = yd - yb;
    }
  } else {
    ans = min(abs(yd - yb), abs(xd - xb));
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
