#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
long long t, n;
long long a[N];
signed main() {
  cin >> t;
  while (t--) {
    cin >> n;
    long long tt = 0, ff = 1;
    for (long long i = 1; i <= n; ++i) cin >> a[i];
    for (long long i = 1; i <= n; ++i) {
      long long f = 0;
      for (long long j = 1; j <= i; ++j) {
        if (a[i] % (j + 1) != 0) {
          f = 1;
          break;
        }
      }
      if (!f) {
        ff = 0;
        break;
      }
    }
    if (ff)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
