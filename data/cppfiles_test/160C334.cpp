#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n, m, a, b, q, w;
    cin >> n >> m >> a >> b >> q >> w;
    bool found = false;
    long long ard = 1, brd = 1, cnt = 0;
    while (found == false) {
      if (a == q || b == w) {
        found = true;
      } else {
        if (a < n && b < m) {
          a += ard;
          b += brd;
          cnt++;
        } else if (a == n && b == m) {
          ard = -1;
          brd = -1;
          a += ard;
          b += brd;
          cnt++;
        } else if (a == n) {
          ard = -1;
          a += ard;
          b += brd;
          cnt++;
        } else if (b == m) {
          brd = -1;
          a += ard;
          b += brd;
          cnt++;
        }
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
