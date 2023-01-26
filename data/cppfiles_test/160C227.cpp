#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m, x, y, a, b;
  cin >> n >> m >> x >> y >> a >> b;
  if (n > m) {
    swap(n, m);
    swap(x, y);
    swap(a, b);
  }
  long long c = 1;
  long long d = 1;
  long long ans = 0;
  while (1) {
    if (x == a || y == b) {
      cout << ans << '\n';
      return;
    }
    ans++;
    if (x + c > n || x + c < 1) {
      c *= -1;
    }
    if (y + d > m || y + d < 1) {
      d *= -1;
    }
    x += c;
    y += d;
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n = 1;
  cin >> n;
  while (n--) {
    solve();
  }
}
