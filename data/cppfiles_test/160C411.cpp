#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m, rb, cb, rd, cd;
  cin >> n >> m >> rb >> cb >> rd >> cd;
  long long c1, c2;
  if (rb <= rd) {
    c1 = rd - rb;
  } else {
    c1 = (n - rb) * 2 + (rb - rd);
  }
  if (cb <= cd) {
    c2 = cd - cb;
  } else {
    c2 = (m - cb) * 2 + (cb - cd);
  }
  cout << min(c1, c2) << '\n';
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long tt = 1;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
