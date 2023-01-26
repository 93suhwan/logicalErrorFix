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
    long long delta = 0, m = 0;
    for (long long i = 1; i < n && !m; i++) {
      delta += pow(10, a[i] - a[i - 1]) - 1;
      if (delta > k) m = i;
    }
    stringstream ss;
    if (m && k + pow(10, a[m] - a[m - 1]) - 1 - delta)
      ss << k + pow(10, a[m] - a[m - 1]) - 1 - delta;
    else
      ss << k - delta;
    m = a[!m ? n - 1 : m - 1];
    for (long long i = 0; i < m; i++) ss << "9";
    cout << ss.str() << "\n";
  }
  return 0;
}
