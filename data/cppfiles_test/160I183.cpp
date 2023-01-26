#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    if (rb == rd || cb == cd) cout << 0 << endl;
    int rt, ct;
    if (rd > rb)
      rt = rd - rb;
    else
      rt = n - rb + n - rd;
    if (cd > cb)
      ct = cd - cb;
    else
      ct = m - cb + m - cd;
    cout << min(rt, ct) << endl;
  }
  return 0;
}
