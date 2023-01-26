#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int ra, ca, rb, cb, x = 1, y = 1, ans = 0;
    cin >> ra >> ca >> rb >> cb;
    while (ra != rb && ca != cb) {
      if ((x > 0 && ra == n) || (x < 0 && ra == 1)) {
        x *= -1;
      }
      if ((y < 0 && ca == 1) || (y > 0 && ca == m)) {
        y *= -1;
      }
      ra += x;
      ca += y;
      ans++;
    }
    cout << ans << "\n";
  }
}
