#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    int ans = 0;
    int x = 1, y = 1;
    while (rb != rd && cb != cd) {
      if (rb + x == 0 || rb + x > n) x *= -1;
      if (cb + y == 0 || cb + y > m) y *= -1;
      rb += x;
      cb += y;
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
