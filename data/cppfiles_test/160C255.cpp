#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    int p = 0;
    int dr = 1, dc = 1;
    while (1) {
      if (rb == rd || cb == cd) {
        cout << p << endl;
        break;
      }
      if (rb == n || rb == 1 && p != 0) {
        dr = -dr;
      }
      if (cb == m || cb == 1 && p != 0) {
        dc = -dc;
      }
      p++;
      rb += dr;
      cb += dc;
    }
  }
}
