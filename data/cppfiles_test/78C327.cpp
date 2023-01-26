#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    long long ans;
    if (l == r) {
      cout << 0 << endl;
      continue;
    }
    long long val = r / 2;
    val++;
    ans = r % val;
    if (val < l) ans = r % l;
    cout << ans << endl;
  }
}
