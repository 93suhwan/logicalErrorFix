#include <bits/stdc++.h>
using namespace std;
long long qpow(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x % 998244353;
    y /= 2;
    x = x * x % 998244353;
  }
  return res;
}
long long rev(long long x) { return qpow(x, 998244353 - 2); }
void solve() {
  long long n, m, p;
  cin >> n >> m;
  long long x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2 >> p;
  long long dx = -1, dy = -1, k = 0, ans = 0;
  long long a = 1, b = 0;
  p = p * rev(100) % 998244353;
  p = (1 - p + 998244353) % 998244353;
  for (long long i = 0; i < 4 * (n - 1) * (m - 1); i++) {
    if (x1 == n and dx == 1)
      dx = -1;
    else if (x1 == 1 and dx == -1)
      dx = 1;
    if (y1 == m and dy == 1)
      dy = -1;
    else if (y1 == 1 and dy == -1)
      dy = 1;
    x1 += dx;
    y1 += dy;
    b++;
    if (x1 == x2 or y1 == y2) {
      a = a * p % 998244353;
      b = b * p % 998244353;
    }
  }
  a = (1 - a + 998244353) % 998244353;
  ans = b * rev(a) % 998244353;
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
