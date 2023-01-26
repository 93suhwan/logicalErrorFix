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
      if (c > a && d > b) {
        ans = min((c - a), (d - b));
      } else if (d < b) {
        ans = (m - b) + (m - d);
      } else if (b < d) {
        long long x = n - a;
        ans = x + (d - (x + b));
      }
      cout << ans << endl;
    }
  }
  return 0;
}
