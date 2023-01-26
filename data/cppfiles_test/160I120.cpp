#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, m, a, b, c, d;
    cin >> n >> m >> a >> b >> c >> d;
    long long ans = 0;
    if (a == c || b == d) {
      cout << 0 << endl;
    } else {
      if (d < b && a > c) {
        ans = (m - d) + (m - b);
      } else if (b < d && a > c) {
        ans = d - b;
      } else if (a < c) {
        ans = c - a;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
