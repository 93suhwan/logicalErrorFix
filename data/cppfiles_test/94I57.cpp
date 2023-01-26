#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) cin >> a[i];
    if (n == 1) {
      cout << k + 1 << "\n";
      continue;
    }
    long long delta = 0, m = 0;
    bool ok = false;
    for (long long i = 1; i < n && !ok; i++) {
      delta += pow(10, a[i] - a[i - 1]) - 1;
      m++;
      if (delta > k) {
        ok = true;
      }
    }
    stringstream ss;
    if (!ok)
      ss << k - delta + 1;
    else if (k + 10 <= delta)
      ss << k + 1;
    else
      ss << k + 10 - delta;
    m = a[m - 1 + !ok];
    for (long long i = 0; i < m; i++) ss << "9";
    cout << ss.str() << "\n";
  }
  return 0;
}
