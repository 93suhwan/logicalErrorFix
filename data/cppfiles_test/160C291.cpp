#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    int dr = 1, dc = 1;
    int time = 0;
    if (rb == rd || cb == cd) {
      cout << 0 << "\n";
      continue;
    }
    while (true) {
      if (rb + dr < 1 || rb + dr > n) {
        dr = -dr;
      }
      if (cb + dc < 1 || cb + dc > m) {
        dc = -dc;
      }
      rb = rb + dr;
      cb = cb + dc;
      time++;
      if (rb == rd || cb == cd) break;
    }
    cout << time << "\n";
  }
  return 0;
}
