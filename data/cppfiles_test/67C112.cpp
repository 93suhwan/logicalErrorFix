#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  int dist = max(a, b) - min(a, b);
  int below = min(a, b) - 1;
  int between = dist - 1;
  if (between < below) {
    cout << -1 << '\n';
    return;
  }
  if (c > dist * 2) {
    cout << -1 << '\n';
    return;
  }
  if (c + dist <= dist * 2) {
    cout << c + dist << '\n';
    return;
  }
  cout << c - dist << '\n';
}
int main(void) {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  cout << flush;
  return 0;
}
