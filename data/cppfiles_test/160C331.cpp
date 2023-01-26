#include <bits/stdc++.h>
using namespace std;
int n, m, rb, cb, rd, cd, t;
bool row[105], colum[105];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m >> rb >> cb >> rd >> cd;
    int time = 0;
    int r, c;
    if (rb == rd || cb == cd) {
      cout << 0 << endl;
      continue;
    } else {
      if (rb > rd) {
        r = (n - rb) + (n - rd);
      } else
        r = rd - rb;
      if (cb > cd) {
        c = (m - cb) + (m - cd);
      } else
        c = cd - cb;
      time = min(r, c);
      cout << time << endl;
    }
  }
}
