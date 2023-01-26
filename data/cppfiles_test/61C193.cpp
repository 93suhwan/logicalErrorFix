#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int64_t T;
  cin >> T;
  while (T--) {
    int64_t n;
    cin >> n;
    vector<int64_t> a(n), b(n);
    map<int64_t, int64_t> ca, cb;
    for (int64_t i = 0; i < n; ++i) cin >> a[i] >> b[i], ++ca[a[i]], ++cb[b[i]];
    int64_t ans = n * (n - 1) * (n - 2) / 6;
    for (int64_t i = 0; i < n; i++) ans -= (ca[a[i]] - 1) * (cb[b[i]] - 1);
    cout << ans << '\n';
  }
  return 0;
}
