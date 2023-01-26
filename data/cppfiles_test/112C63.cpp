#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int mx = max(a, max(b, c));
  int sum = a + b + c;
  int l = max(0, mx - 1 - (sum - mx));
  int r = (a ? a - 1 : 0) + (b ? b - 1 : 0) + (c ? c - 1 : 0);
  if (l <= d && d <= r) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
