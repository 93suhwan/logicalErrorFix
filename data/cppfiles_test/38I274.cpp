#include <bits/stdc++.h>
using namespace std;
void solve() {
  int64_t n;
  cin >> n;
  int64_t ans =
      min({((n + 5) / 6) * 15, ((n + 7) / 8) * 20, ((n + 9) / 10) * 25});
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int64_t t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
