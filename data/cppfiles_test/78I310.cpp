#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long l, r;
  cin >> l >> r;
  if (l == r) {
    cout << 0;
    return;
  }
  if (r % 2 != 0) {
    cout << r / 2;
    return;
  } else {
    long long ans = r / 2 + 1;
    if (ans >= l) {
      cout << r % ans;
    } else {
      cout << r % l;
    }
  }
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
