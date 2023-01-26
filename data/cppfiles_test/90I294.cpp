#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a, b;
  cin >> a >> b;
  if (a == b) {
    cout << a << endl;
    return;
  } else if (a > b) {
    cout << a + b << endl;
    return;
  } else {
    cout << (a + b) / 2 << endl;
    return;
  }
  cout << -1 << endl;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
