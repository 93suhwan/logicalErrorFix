#include <bits/stdc++.h>
using namespace std;
long long n, a[200000 + 1], res;
set<long long> s;
char c[200000 + 1];
signed main() {
  cin >> n;
  for (long long i = 1; i <= n; ++i) cin >> a[i], s.insert(a[i]);
  for (long long i = 1; i <= n; ++i) cin >> c[i];
  sort(a + 1, a + n + 1);
  for (long long i = 1; i <= n; ++i) {
    if (i == 1) {
      if (c[i] == 'L')
        res -= a[n], cout << a[n] << ' ' << 'L' << endl;
      else
        res += a[n], cout << a[n] << ' ' << 'R' << endl;
      s.erase(s.begin());
    } else {
      if (c[i] == c[i - 1]) {
        auto it = s.lower_bound(abs(res));
        if (it != s.begin()) {
          it--;
          if (c[i] == 'L')
            res += a[i], cout << (*it) << ' ' << 'R' << endl;
          else
            res -= a[i], cout << (*it) << ' ' << 'L' << endl;
          s.erase(it);
        } else {
          it = s.upper_bound(abs(res));
          if (c[i] == 'L')
            res -= a[i], cout << (*it) << ' ' << 'L' << endl;
          else
            res += a[i], cout << (*it) << ' ' << 'R' << endl;
          s.erase(it);
        }
      } else {
        auto it = s.upper_bound(abs(res));
        if (c[i] == 'L')
          res -= a[i], cout << (*it) << ' ' << 'L' << endl;
        else
          res += a[i], cout << (*it) << ' ' << 'R' << endl;
        s.erase(it);
      }
    }
  }
  return 0;
}
