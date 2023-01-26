#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long x, y;
  cin >> x >> y;
  if (y % x == 0) {
    cout << x << endl;
  } else {
    long long ans = x + y;
    cout << ans << endl;
  }
}
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
}
