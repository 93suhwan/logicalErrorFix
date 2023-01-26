#include <bits/stdc++.h>
using namespace std;
const int N = 2.1e5;
int lim[N], a[N], b[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, i;
    long long dl = 0, dr = 0;
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
      int x, y, l, r;
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
      assert(l <= r);
      lim[i] = r - l >> 1;
      dl -= l;
      dr += r - l;
    }
    if (dl >= 0 && dl <= dr) {
      cout << (dl & 1) << '\n';
      dl >>= 1;
      for (i = 1; i <= n; i++)
        if (dl >= lim[i])
          dl -= lim[i], cout << a[i] - lim[i] << ' ' << b[i] + lim[i] << '\n';
        else
          cout << a[i] - dl << ' ' << b[i] + dl << '\n', dl = 0;
    } else if (dl < 0) {
      cout << -dl << '\n';
      for (i = 1; i <= n; i++) cout << a[i] << ' ' << b[i] << '\n';
    } else {
      cout << dl - dr << '\n';
      for (i = 1; i <= n; i++)
        cout << a[i] - lim[i] << ' ' << b[i] + lim[i] << '\n';
    }
  }
}
