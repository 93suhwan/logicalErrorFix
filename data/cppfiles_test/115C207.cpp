#include <bits/stdc++.h>
using namespace std;
long long t, i, n, a[200020], j, l, p, r, s, k, mid;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (i = 1; i <= n; i++) {
      cin >> a[i];
    }
    l = 0;
    r = 2 * 1e18;
    while (l + 1 < r) {
      mid = (l + r) / 2;
      s = 0;
      a[n + 1] = 2 * 1e18;
      for (i = 1; i <= n; i++) {
        s += min(a[i + 1] - a[i], mid);
      }
      if (s >= k) {
        r = mid;
      } else {
        l = mid;
      }
    }
    cout << l + 1 << '\n';
  }
}
