#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    long long a, b, c, m;
    cin >> a >> b >> c >> m;
    long long temp = a + b + c;
    long long mmax = temp - 3;
    if (a == 0) mmax++;
    if (b == 0) mmax++;
    if (c == 0) mmax++;
    long long ma = max(a, max(c, b));
    long long mmin = 0;
    if (ma == a) {
      long long te = max(b, c);
      mmin = ma - te - 1;
    } else if (ma == b) {
      long long te = max(a, c);
      mmin = ma - te - 1;
    } else if (ma == c) {
      long long te = max(a, b);
      mmin = ma - te - 1;
    }
    if (m >= mmin && m <= mmax)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
