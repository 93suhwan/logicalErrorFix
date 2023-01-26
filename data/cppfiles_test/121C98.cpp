#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string x, y;
    cin >> x >> y;
    long long x0 = 0, x1 = 0, y0 = 0, y1 = 0;
    long long v00 = 0, v01 = 0, v11 = 0;
    for (long long i = 0; i < n; i++) {
      if (x[i] == '0' and y[i] == '0') {
        x0++;
        y0++;
        v00++;
      } else if (x[i] == '1' and y[i] == '0') {
        x1++;
        y0++;
        v01++;
      } else if (x[i] == '0' and y[i] == '1') {
        x0++;
        y1++;
        v01++;
      } else {
        x1++;
        y1++;
        v11++;
      }
    }
    if (x1 + y1 != n + 1 and x1 != y1)
      cout << -1 << endl;
    else {
      long long ans = 1000000;
      if (x1 + y1 == n + 1) {
        ans = min(ans, 2 * v00 + 1);
      }
      if (x1 == y1) {
        ans = min(ans, v01);
      }
      cout << ans << endl;
    }
  }
}
