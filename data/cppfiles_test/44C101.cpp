#include <bits/stdc++.h>
using namespace std;
void solve() {
  int c, d;
  cin >> c >> d;
  if (c == 0 && d == 0) {
    cout << 0 << endl;
    return;
  }
  if (c == d) {
    cout << 1 << endl;
    return;
  }
  if (abs(c - d) % 2 == 0) {
    cout << 2 << endl;
    return;
  } else {
    cout << -1 << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
