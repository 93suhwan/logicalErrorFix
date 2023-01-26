#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, a, b, c, d;
    cin >> n >> m >> a >> b >> c >> d;
    int p, q;
    if (a == c || b == d) {
      cout << 0 << endl;
    } else {
      if (c > a) {
        p = c - a;
      } else {
        p = n - a + n - c;
      }
      if (d > b) {
        q = d - b;
      } else {
        q = m + m - b - d;
      }
      cout << min(p, q) << endl;
    }
  }
  return 0;
}
