#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int x, y;
  cin >> x >> y;
  if (x == 1) {
    cout << 1 << "\n";
    return;
  }
  if (y < x) {
    cout << x + y << "\n";
  } else if (x == y) {
    cout << x << "\n";
  } else if (x < y) {
    long long int ans = x + (y - x) / 2;
    cout << ans << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t, q;
  q = 1;
  cin >> q;
  for (t = 1; t <= q; t++) {
    solve();
  }
}
