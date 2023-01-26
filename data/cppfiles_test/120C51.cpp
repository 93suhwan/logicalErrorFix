#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    int ans = INT_MAX;
    for (int i = 0; i < 20; ++i) {
      int d = (1 << i);
      int b = (r / (2 * d)) * d;
      b += min(d, 1 + r % (2 * d));
      int a = ((l - 1) / (2 * d)) * d;
      a += min(d, 1 + (l - 1) % (2 * d));
      ans = min(ans, b - a);
    }
    cout << ans << endl;
  }
}
