#include <bits/stdc++.h>
using namespace std;
void solve() {
  int i = 0, j = 0, k = 0;
  int n;
  cin >> n;
  int ans = floor(sqrt(n)) + floor(cbrt(n));
  cout << ans - floor(cbrt(ans)) << endl;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int t;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
  return 0;
}
