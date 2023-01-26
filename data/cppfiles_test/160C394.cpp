#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  long long n, m, x, y, dx, dy, ans;
  cin >> n >> m >> x >> y >> dx >> dy;
  ans = 1e16;
  if (dx >= x) {
    ans = min(ans, dx - x);
  } else {
    ans = min(ans, n - x + n - dx);
  }
  if (dy >= y) {
    ans = min(ans, dy - y);
  } else {
    ans = min(ans, m - y + m - dy);
  }
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long test = 1;
  cin >> test;
  for (long long i = 1; i <= test; i++) {
    solve();
  }
}
