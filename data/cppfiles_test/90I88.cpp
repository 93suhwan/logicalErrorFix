#include <bits/stdc++.h>
using namespace std;
void solve() {
  unsigned long long x, y;
  cin >> x >> y;
  if (y % x == 0 || x % y == 0) {
    cout << min(x, y) << endl;
    return;
  } else {
    unsigned long long r = y % x;
    cout << y - r / 2 << endl;
    return;
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
