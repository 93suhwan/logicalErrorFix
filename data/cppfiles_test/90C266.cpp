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
    if (b % a == 0) {
      cout << b << endl;
      return;
    } else {
      long long x = b - a - b % a;
      if (x == 0) {
        cout << a + (b - a) / 2;
      } else {
        cout << (b + x) / 2;
      }
      cout << endl;
      return;
    }
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
