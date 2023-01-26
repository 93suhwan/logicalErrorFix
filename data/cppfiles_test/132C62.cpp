#include <bits/stdc++.h>
using namespace std;
string multiple[4] = {"00", "25", "50", "75"};
void solve() {
  int a[7];
  for (int i = (0); i < (7); i++) cin >> a[i];
  cout << a[0] << " " << a[1] << " " << a[6] - a[1] - a[0] << '\n';
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
