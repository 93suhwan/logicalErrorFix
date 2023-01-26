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
    for (int64_t i = 0; i < n; ++i) {
      cin >> a[i];
      mp[a[i]] = -1;
    }
    vector<int64_t> b = a;
    sort(b.rbegin(), b.rend());
    int64_t ans = 1e17 + 7;
    for (int64_t i = 0; i < n; ++i) {
      if (mp[b[i]] == -1) {
        mp[b[i]] = i;
      }
    }
    reverse(a.begin(), a.end());
    for (int64_t i = 0; i < n; ++i) {
      ans = min(ans, i + mp[a[i]]);
    }
    cout << ans << "\n";
  }
  return 0;
}
