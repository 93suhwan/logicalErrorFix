#include <bits/stdc++.h>
using namespace std;
long long a[4][200005];
void solve() {
  long long w, h, k[4];
  cin >> w >> h;
  for (long long i = 0; i < 4; ++i) {
    cin >> k[i];
    for (long long j = 1; j <= k[i]; ++j) cin >> a[i][j];
  }
  long long ans = 0;
  for (long long i = 0; i < 4; ++i) {
    if (i < 2)
      ans = max((a[i][k[i]] - a[i][1]) * h, ans);
    else
      ans = max(ans, (a[i][k[i]] - a[i][1]) * w);
  }
  cout << ans << '\n';
}
signed main() {
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
