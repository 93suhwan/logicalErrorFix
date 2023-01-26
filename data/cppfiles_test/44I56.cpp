#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b;
  cin >> a >> b;
  if (abs(a - b) == 1) {
    cout << -1 << endl;
    return;
  } else if (a == b and a != 0 and b != 0) {
    cout << 1 << endl;
    return;
  } else if (abs(a - b) > 1 and a != 0 and b != 0) {
    cout << abs(a - b) << endl;
    return;
  } else if (a == 0 and b == 0) {
    cout << 0 << endl;
    return;
  } else if (a == 0 or b == 0) {
    cout << 2 << endl;
    return;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
