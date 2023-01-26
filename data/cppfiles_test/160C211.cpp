#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, m, rb, cb, rd, cd, s, r, c;
  cin >> t;
  while (t) {
    cin >> n >> m >> rb >> cb >> rd >> cd;
    s = 0, c = 0, r = 0;
    while ((rb != rd) && (cb != cd)) {
      if (rb == n) r = -1;
      if (cb == m) c = -1;
      if (rb == 1) r = 0;
      if (cb == 1) c = 0;
      if (r >= 0) {
        rb = rb + 1;
      } else {
        rb = rb - 1;
      }
      if (c >= 0) {
        cb = cb + 1;
      } else {
        cb = cb - 1;
      }
      s++;
    }
    cout << s;
    cout << endl;
    t--;
  }
  return 0;
}
