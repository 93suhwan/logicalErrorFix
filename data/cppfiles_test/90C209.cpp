#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
void solve() {
  long long x, y;
  cin >> x >> y;
  if (x == y) {
    cout << x << endl;
    return;
  }
  if (y < x) {
    cout << x + y << endl;
    return;
  }
  if (y % x == 0) {
    cout << x << endl;
    return;
  }
  cout << y - (y % x) / 2 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tests = 1;
  cin >> tests;
  while (tests--) {
    solve();
  }
}
