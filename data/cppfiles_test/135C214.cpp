#include <bits/stdc++.h>
using namespace std;
const long long N = 109;
const long long oo = 1e9 + 9;
long long a[N], pf[N];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, test, k;
  cin >> test;
  while (test--) {
    cin >> n >> k;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (long long i = 1; i <= n; i++) pf[i] = pf[i - 1] + a[i];
    long long remain = n - k * 2;
    map<long long, long long> m;
    long long res = oo;
    for (long long i = remain; i <= n; i++) {
      m.clear();
      for (long long j = 1; j <= n; j++)
        if (j > i || j < i - remain + 1) m[a[j]]++;
      bool kt = true;
      long long cost = pf[i] - pf[i - remain];
      for (auto &xnew : m)
        if (xnew.second > k) {
          kt = false;
          res = min(res, xnew.second - k + cost);
        }
      if (kt) res = min(res, cost);
    }
    cout << res << '\n';
  }
  return 0;
}
