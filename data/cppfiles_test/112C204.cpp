#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  int t;
  cin >> t;
  while (t--) {
    int a[3], m;
    cin >> a[0] >> a[1] >> a[2] >> m;
    sort(a, a + 3);
    int mn = a[2] - (a[0] + a[1] + 1);
    if (mn < 0) mn = 0;
    int mx = a[0] + a[1] + a[2] - 3;
    if (m >= mn && m <= mx) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
