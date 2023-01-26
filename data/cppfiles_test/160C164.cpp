#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int r, c, rr, rc, dr, dc, cr = 1, cc = 1;
    cin >> r >> c >> rr >> rc >> dr >> dc;
    int cnt = 0;
    while ((rr != dr) && (rc != dc)) {
      if (rr == r) cr = -1;
      if (rc == c) cc = -1;
      if (rr == 1) cr = 1;
      if (rc == 1) cc = 1;
      rr += cr;
      rc += cc;
      cnt++;
    }
    cout << cnt << endl;
  }
}
