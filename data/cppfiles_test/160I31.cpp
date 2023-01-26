#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    long long int dr = 1;
    long long int dc = 1;
    long long int a = 0;
    while (a >= 0) {
      long long int rbdr = rb + dr;
      long long int cbdc = cb + dc;
      if (rb == rd) {
        break;
      } else if (cb == cd) {
        break;
      } else if (rbdr > n) {
        dr = dr * (-1);
      } else if (rbdr < 1) {
        dr = dr * (-1);
      } else if (cbdc > m) {
        dc = dc * (-1);
      } else if (cbdc < 1) {
        dc = dc * (-1);
      }
      a++;
      rb = rb + dr;
      cb = cb + dc;
    }
    cout << a << endl;
  }
  return 0;
}
