#include <bits/stdc++.h>
using namespace std;
int a[4][200005];
void solve() {
  int w, h, k[4];
  cin >> w >> h;
  for (int i = 0; i < 4; ++i) {
    cin >> k[i];
    for (int j = 1; j <= k[i]; ++j) cin >> a[i][j];
  }
  int ans = 0;
  for (int i = 0; i < 4; ++i) {
    if (i < 2)
      ans = max((a[i][k[i]] - a[i][1]) * h, ans);
    else
      ans = max(ans, (a[i][k[i]] - a[i][1]) * w);
  }
  cout << ans << '\n';
}
signed main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
