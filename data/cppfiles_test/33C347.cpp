#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(0)->sync_with_stdio(false);
  cout << setprecision(10) << fixed;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    long long mx = 0;
    for (int i = 0; i + 1 < n; ++i) {
      mx = max(mx, a[i] * a[i + 1]);
    }
    cout << mx << '\n';
  }
  return 0;
}
