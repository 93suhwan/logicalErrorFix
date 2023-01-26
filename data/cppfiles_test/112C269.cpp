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
      mmin = ma - b - c - 1;
    } else if (ma == b) {
      mmin = ma - a - c - 1;
    } else if (ma == c) {
      mmin = ma - a - b - 1;
    }
    mmin = max((long long)0, mmin);
    if (m >= mmin && m <= mmax)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
