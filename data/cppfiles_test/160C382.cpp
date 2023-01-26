#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  while (x-- > 0) {
    long t = 0;
    long n, m, rr, rc, dr, dc;
    long tr, tc;
    cin >> n >> m >> rr >> rc >> dr >> dc;
    tr = rr;
    tc = rc;
    while (rr != dr && rc != dc) {
      t++;
      if (tr < n && tc < m) {
        rr++;
        rc++;
        tr = rr;
        tc = rc;
      } else {
        if (tr >= n && tc < m) {
          rr--;
          rc++;
          tc = rc;
        } else if (tc >= m && tr < n) {
          rr++;
          rc--;
          tr = rr;
        } else {
          rc--;
          rr--;
        }
      }
    }
    cout << t << endl;
  }
}
