#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    if (a == 0 && b == 0) {
      cout << 0 << endl;
    } else if (a == b) {
      cout << 1 << endl;
    } else {
      if (abs(a - b) % 2 == 0) {
        cout << 2 << endl;
      } else {
        cout << -1 << endl;
      }
    }
  }
}
