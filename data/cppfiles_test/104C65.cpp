#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 10;
long long lim[maxn], a[maxn], b[maxn];
void solve() {
  long long n, m;
  long long dl = 0, dr = 0;
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    long long x, y, l, r;
    cin >> x >> y;
    a[i] = min(x, m);
    b[i] = m - a[i];
    if (x <= m)
      l = m - x - y;
    else
      l = x - m - y;
    if (y <= m)
      r = x - m + y;
    else
      r = x + m - y;
    lim[i] = r - l >> 1;
    dl -= l;
    dr += r - l;
  }
  if (dl >= 0 && dl <= dr) {
    cout << (dl & 1) << '\n';
    dl >>= 1;
    for (long long i = 1; i <= n; i++)
      if (dl >= lim[i])
        dl -= lim[i], cout << a[i] - lim[i] << ' ' << b[i] + lim[i] << '\n';
      else
        cout << a[i] - dl << ' ' << b[i] + dl << '\n', dl = 0;
  } else if (dl < 0) {
    cout << -dl << '\n';
    for (long long i = 1; i <= n; i++) cout << a[i] << ' ' << b[i] << '\n';
  } else {
    cout << dl - dr << '\n';
    for (long long i = 1; i <= n; i++)
      cout << a[i] - lim[i] << ' ' << b[i] + lim[i] << '\n';
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
}
