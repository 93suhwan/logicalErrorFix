#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long l, r;
  cin >> l >> r;
  cout << min(r - l, r % (r / 2 + 1));
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
