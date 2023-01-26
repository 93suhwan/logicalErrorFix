#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    int count = 0;
    int dr = 1, dc = 1;
    while (true) {
      if (rb == rd || cb == cd) {
        break;
      }
      if (rb + dr > n || rb + dr < 1) {
        dr *= -1;
      }
      if (cb + dc > m || cb + dc < 1) {
        dc *= -1;
      }
      rb += dr;
      cb += dc;
      count++;
    }
    cout << count << endl;
  }
  return 0;
}
