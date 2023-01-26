#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("popcnt")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int t, w, h;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    long long ans = 0;
    cin >> w >> h;
    for (int _ = 0; _ <= 1; ++_) {
      int k, l, r;
      cin >> k >> l;
      for (int i = 2; i <= k; ++i) {
        cin >> r;
        ans = max<long long>(ans, 1ll * (r - l) * h);
      }
    }
    for (int _ = 0; _ <= 1; ++_) {
      int k, l, r;
      cin >> k >> l;
      for (int i = 2; i <= k; ++i) {
        cin >> r;
        ans = max<long long>(ans, 1ll * (r - l) * w);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
