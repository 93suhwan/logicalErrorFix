#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
    }
    long long ans = 0;
    for (int i = 1; i < n; i++) {
      ans = max(ans, 1LL * a[i] * a[i - 1]);
    }
    cout << ans << '\n';
  }
  return 0;
}
