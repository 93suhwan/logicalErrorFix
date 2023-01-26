#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int x, y;
  cin >> x >> y;
  if (y < x) {
    cout << x + y << "\n";
  } else if (x == y) {
    cout << x << "\n";
  } else if (x < y) {
    if (y <= x + x) {
      cout << (x + y) / 2 << "\n";
      return;
    }
    long long int t = (y - (x + x));
    cout << y - t << "\n";
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
