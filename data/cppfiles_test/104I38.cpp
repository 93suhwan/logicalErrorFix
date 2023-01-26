#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
long long t;
long long main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<long long> a(n + 1), b(n + 1);
    long long cursum = 0;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i] >> b[i];
      cursum += a[i] - b[i];
    }
    long long L = 0;
    long long R = 0;
    function<long long(long long, long long)> greedy = [&](long long x,
                                                           long long y) {
      long long rem = m;
      long long dx = min(x, rem);
      x -= dx;
      rem -= dx;
      if (rem > 0) {
        y -= rem;
      }
      return x - y;
    };
    function<void(long long &, long long &)> greedy_modify = [&](long long &x,
                                                                 long long &y) {
      long long rem = m;
      long long dx = min(x, rem);
      x -= dx;
      rem -= dx;
      if (rem > 0) {
        y -= rem;
      }
      return x - y;
    };
    for (long long i = 1; i <= n; i++) {
      L += greedy(a[i], b[i]);
      R -= greedy(b[i], a[i]);
    }
    long long ans;
    if (L <= 0 and R >= 0) {
      if (L % 2 == 0)
        ans = 0;
      else if (R > 0)
        ans = 1;
      else
        ans = -1;
    } else {
      ans = min(abs(L), abs(R));
      if (R < 0) ans = R;
      if (L > 0) ans = L;
    }
    cout << abs(ans) << "\n";
    vector<long long> c = a;
    vector<long long> d = b;
    for (long long i = 1; i <= n; i++) {
      greedy_modify(c[i], d[i]);
    }
    for (long long i = 1; i <= n; i++) {
      long long rem_swaps = (ans - L) / 2;
      long long to_change = min({rem_swaps, a[i] - c[i], d[i]});
      c[i] += to_change;
      d[i] -= to_change;
      L += 2 * rem_swaps;
    }
    for (long long i = 1; i <= n; i++) {
      cout << (a[i] - c[i]) << " " << (b[i] - d[i]) << "\n";
    }
  }
}
