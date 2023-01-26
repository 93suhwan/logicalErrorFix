#include <bits/stdc++.h>
using namespace std;
const long long INF_ = LONG_LONG_MIN;
signed main() {
  long long t;
  cin >> t;
  for (long long u = 0; u < t; ++u) {
    long long n, max_ = -1, ans = 0;
    cin >> n;
    vector<long long> b(n);
    for (long long i = 0; i < n; ++i) {
      cin >> b[i];
      max_ = max(max_, b[i]);
    }
    long long a = b[n - 1];
    for (long long i = n - 2; i >= 0; --i) {
      if (b[i] > a) {
        a = b[i];
        ans++;
      }
      if (a == max_) {
        a = 0;
        cout << ans << '\n';
        break;
      }
    }
    if (a == max_) {
      cout << ans << '\n';
      break;
    }
  }
}
