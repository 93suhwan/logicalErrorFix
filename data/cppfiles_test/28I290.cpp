#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a, b, c;
  cin >> a >> b >> c;
  a %= 2;
  b %= 2;
  c %= 2;
  if (a == b && b == c)
    cout << 0 << '\n';
  else
    cout << 1 << '\n';
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
