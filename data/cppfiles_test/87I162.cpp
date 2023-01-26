#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    long long mx = 0, mxi = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      if (mx < a[i]) {
        mx = a[i];
        mxi = i;
      }
    }
    long long ans = mx - mxi - 1;
    cout << ans << "\n";
  }
  return 0;
}
