#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, k;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    int count = 0;
    int a = 1, b = 1;
    if (rb != rd && cb != cd) {
      while (true) {
        if (rb == n) {
          a = -1;
        }
        if (rb == 1) {
          a = 1;
        }
        if (cb == m) {
          b = -1;
        }
        if (cb == 1) {
          b = 1;
        }
        rb = rb + a;
        cb = cb + b;
        count++;
        if (rb == rd || cb == cd) {
          break;
        }
      }
    }
    cout << count << endl;
  }
}
