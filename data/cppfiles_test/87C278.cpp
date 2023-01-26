#include <bits/stdc++.h>
#pragma GCC optimize "trapv"
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, a[i] - i - 1);
  }
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
}
