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
    for (long long i = n; i; --i) {
      if (a[i] % (i + 1) != 0) a[i] = 0;
    }
    for (long long i = 1; i <= n; ++i) {
      if (!a[i]) {
        tt++;
        continue;
      }
      if (a[i] % (i - tt + 1) == 0) {
        ff = 0;
        break;
      } else
        tt++;
    }
    if (ff)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
