#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    int n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    int dr = 1;
    int dc = 1;
    int steps = 0;
    while (rb != rd) {
      if (cb == cd) {
        break;
      } else {
        steps++;
        if (rb == n) {
          dr = -1 * dr;
        }
        if (cb == m) {
          dc = dc * -1;
        }
        rb = rb + dr;
        cb = cb + dc;
      }
    }
    cout << steps << endl;
  }
  return 0;
}
