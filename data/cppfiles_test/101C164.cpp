#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 10;
const long long INF = 0x3f3f3f3f;
const long long mod = 998244353;
const double esp = 1e-7;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    set<long long> x, y;
    long long n, m, k;
    cin >> n >> m >> k;
    for (long long i = 1; i <= n; i++) {
      long long u;
      cin >> u;
      x.insert(u);
    }
    for (long long i = 1; i <= m; i++) {
      long long u;
      cin >> u;
      y.insert(u);
    }
    map<pair<long long, long long>, long long> mpx, mpy;
    map<long long, long long> cntx, cnty;
    for (long long i = 1; i <= k; i++) {
      long long a, b;
      cin >> a >> b;
      if (x.count(a) == 0) {
        auto p = x.lower_bound(a);
        p--;
        long long lim = *p;
        cntx[lim]++;
        mpx[{lim, b}]++;
      }
      if (y.count(b) == 0) {
        auto p = y.lower_bound(b);
        p--;
        long long lim = *p;
        cnty[lim]++;
        mpy[{lim, a}]++;
      }
    }
    long long ans = 0;
    for (auto i : cntx) ans += i.second * (i.second - 1) / 2;
    for (auto i : cnty) ans += i.second * (i.second - 1) / 2;
    for (auto i : mpx) ans -= i.second * (i.second - 1) / 2;
    for (auto i : mpy) ans -= i.second * (i.second - 1) / 2;
    cout << ans << '\n';
  }
}
