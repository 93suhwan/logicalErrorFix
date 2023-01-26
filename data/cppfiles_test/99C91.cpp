#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long long MX = 4e6 + 5, MOD = 1e9 + 7, inf = 1e18, LG = 21;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x0, n, ans = 0;
    cin >> x0 >> n;
    if (n == 0) {
      cout << x0 << '\n';
      continue;
    }
    if (x0 % 2 == 0) {
      long long k = (((n - 1) / 4) * 4 + 1);
      ans = x0 - k;
      for (long long i = k + 1; i <= n; i++) {
        if (i % 4 < 2)
          ans -= i;
        else
          ans += i;
      }
    } else {
      long long k = (((n - 1) / 4) * 4 + 1);
      ans = x0 + k;
      for (long long i = k + 1; i <= n; i++) {
        if (i % 4 < 2)
          ans += i;
        else
          ans -= i;
      }
    }
    cout << ans << '\n';
  }
}
