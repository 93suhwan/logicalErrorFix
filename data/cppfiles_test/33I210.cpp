#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    long long mx = INT_MIN;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      mx = max(mx, a[i]);
    }
    long long ans;
    for (long long i = 0; i < n; i++) {
      if (a[i] == mx) {
        if (i != n - 1 && i > 0) {
          if (a[i - 1] > a[i + 1]) {
            ans = a[i - 1] * a[i];
            break;
          } else {
            ans = a[i + 1] * a[i];
            break;
          }
        } else if (i == n - 1) {
          ans = a[i - 1] * a[i];
          break;
        } else if (i == 0) {
          ans = a[i + 1] * a[i];
          break;
        }
      }
    }
    cout << ans << "\n";
  }
}
