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
    k++;
    bool ok = false;
    long long new_delta = 0, m = 0;
    for (m = 1; m < n && !ok; m++) {
      new_delta = pow(10, a[m] - a[m - 1]) - 1;
      if (new_delta < k)
        k -= new_delta;
      else
        ok = true;
    }
    stringstream ss;
    if (k) ss << k;
    if (m >= 2) {
      if (ok)
        m = a[m - 2];
      else
        m = a[n - 1];
      for (long long i = 0; i < m; i++) ss << "9";
    }
    cout << ss.str() << "\n";
  }
  return 0;
}
