#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    long long l, r;
    cin >> l >> r;
    long long ma = 1;
    while (ma * 2 <= r) ma <<= 1;
    cout << min(ma - l, (r - l + 1) / 2) << '\n';
  }
  return 0;
}
