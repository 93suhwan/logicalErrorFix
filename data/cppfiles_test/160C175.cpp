#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, m, rb, cb, rd, cd, s, r, c, c1, r1;
  cin >> t;
  while (t) {
    cin >> n >> m >> rb >> cb >> rd >> cd;
    if (cd >= cb) {
      c = cd - cb;
    } else {
      c = cb - cd;
      c1 = 2 * (m - cb);
      c = c + c1;
    }
    if (rd >= rb) {
      r = rd - rb;
    } else {
      r = rb - rd;
      r1 = 2 * (n - rb);
      r = r + r1;
    }
    if (c < r)
      cout << c;
    else
      cout << r;
    cout << endl;
    t--;
  }
  return 0;
}
