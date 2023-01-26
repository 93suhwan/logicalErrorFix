#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  int64_t t;
  cin >> t;
  while (t--) {
    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for (int64_t i = 0; i < n; i++) {
      cin >> a[i];
    }
    int64_t ans = 0;
    int64_t ma = a[n - 1];
    for (int64_t i = n - 2; i >= 0; i--) {
      if (a[i] > ma) {
        ma = a[i];
        ans++;
      }
    }
    cout << ans << '\n';
  }
}
