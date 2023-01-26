#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  for (long long bla = 0; bla < t; bla++) {
    long long n, k;
    cin >> n >> k;
    vector<long long> x;
    vector<long long> y;
    for (long long i = 0; i < n; i++) {
      long long a;
      cin >> a;
      if (a > 0) x.push_back(a);
      if (a < 0) y.push_back(-a);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    long long xs = x.size();
    long long ys = y.size();
    long long d = 0;
    if (xs != 0 || ys != 0) {
      if (xs != 0 && ys != 0) {
        long long r;
        if (y[ys - 1] > x[xs - 1])
          r = y[ys - 1];
        else
          r = x[xs - 1];
        d -= r;
      } else {
        if (xs == 0)
          d -= y[ys - 1];
        else if (ys == 0)
          d -= x[xs - 1];
      }
      if (xs > 0) {
        for (long long i = (xs - 1); i >= 0; i -= k) {
          d += x[i] * 2;
        }
      }
      if (ys > 0) {
        for (long long i = (ys - 1); i >= 0; i -= k) {
          d += y[i] * 2;
        }
      }
    }
    cout << d << endl;
  }
  return 0;
}
