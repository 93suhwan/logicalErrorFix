#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, h;
    cin >> n >> h;
    vector<long long> a(n);
    for (long long i = 0; i < n; ++i) cin >> a[i];
    long long l = -1, r = 2e18 + 1;
    while (l + 1 < r) {
      long long m = (l + r) / 2;
      long long cur = 0;
      for (long long i = 0; i < n; ++i) {
        long long g = m;
        if (i != n - 1) g = min(g, a[i + 1] - a[i]);
        cur += g;
        if (cur >= h) break;
      }
      if (cur >= h)
        r = m;
      else
        l = m;
    }
    cout << r << '\n';
  }
}
