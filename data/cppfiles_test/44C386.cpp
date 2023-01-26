#include <bits/stdc++.h>
using namespace std;
void solve() {
  int c, d;
  cin >> c >> d;
  if (c == 0 && d == 0) {
    cout << 0;
    return;
  }
  if (c == d) {
    cout << 1;
    return;
  }
  int dx = abs(c - d);
  if (dx % 2 == 0) {
    cout << 2;
    return;
  }
  cout << -1;
}
int main() {
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
    cout << '\n';
  }
}
