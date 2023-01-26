#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (long long i = 0; i < n; i++) cin >> a[i];
    for (long long i = 0; i < n; i++) cin >> b[i];
    long long mx1 = *max_element(a.begin(), a.end());
    long long mx2 = *max_element(b.begin(), b.end());
    set<pair<long long, long long>> s1, s2;
    long long x = 0, y = 0;
    vector<long long> ans(n);
    for (long long i = 0; i < n; i++) {
      if (a[i] == mx1) {
        ans[i] = 1;
        y = b[i];
      }
      if (b[i] == mx2) {
        ans[i] = 1;
        x = a[i];
      }
      if (a[i] != mx1 && b[i] != mx2) {
        s1.insert({a[i], i});
        s2.insert({b[i], i});
      }
    }
    while (1) {
      auto it = s1.lower_bound({x, 0});
      if (it != s1.end()) {
        long long idx = it->second;
        ans[idx] = 1;
        x = min(x, a[idx]);
        y = min(y, b[idx]);
        s1.erase(it);
      } else {
        it = s2.lower_bound({y, 0});
        if (it != s2.end()) {
          long long idx = it->second;
          ans[idx] = 1;
          x = min(x, a[idx]);
          y = min(y, b[idx]);
          s2.erase(it);
        } else {
          break;
        }
      }
    }
    for (long long i = 0; i < n; i++) cout << ans[i];
    cout << '\n';
  }
  return 0;
}
