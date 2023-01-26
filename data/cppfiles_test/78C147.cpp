#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long l, r;
  cin >> l >> r;
  long long mn = r / 2 + 1;
  cout << r % (mn >= l ? mn : l) << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long _;
  cin >> _;
  while (_--) solve();
  return 0;
}
