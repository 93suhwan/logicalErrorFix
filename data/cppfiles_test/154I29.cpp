#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long x, y, z;
  cin >> x >> y >> z;
  long long a[3];
  a[0] = x;
  a[1] = y;
  a[2] = z;
  sort(a, a + 3);
  if (a[2] == a[1] + a[0]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
