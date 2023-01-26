#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int64_t t;
  cin >> t;
  while (t--) {
    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    map<int64_t, int64_t> mp;
    int64_t mx = 0;
    set<int64_t> s;
    for (int64_t i = 0; i < n; ++i) {
      cin >> a[i];
      mx = max(mx, a[i]);
    }
    int64_t ans = 0, ans2 = a[n - 1];
    reverse(a.begin(), a.end());
    for (int64_t i = 0; i < n; ++i) {
      if (a[i] > ans2) {
        ans++;
        ans2 = a[i];
      }
      if (a[i] == mx) {
        break;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
