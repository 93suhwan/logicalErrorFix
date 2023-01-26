#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b;
  cin >> a >> b;
  if (a == b) {
    cout << 0 << endl;
    return;
  }
  if (abs(a - b) == 1) {
    cout << 1 << endl;
    return;
  }
  if (a <= ((b / 2))) {
    cout << b % ((b / 2) + 1) << endl;
    return;
  }
  cout << b % a << endl;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
