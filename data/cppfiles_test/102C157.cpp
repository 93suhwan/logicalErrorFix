#include <bits/stdc++.h>
using namespace std;
int fall(int x, int y, int n, int m) {
  if (x < 1 || y < 1 || x > m || y > n) return 1;
  return 0;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int l = s.size();
    int ix = 1, iy = 1, fx = 1, fy = 1, mx, my, minu = 1, maxd = 1, minl = 1,
        maxr = 1;
    for (int i = 0; i < l; i++) {
      if (s[i] == 'U')
        mx = 0, my = -1;
      else if (s[i] == 'D')
        mx = 0, my = 1;
      else if (s[i] == 'L')
        mx = -1, my = 0;
      else
        mx = 1, my = 0;
      if (fall(fx + mx, fy + my, n, m)) {
        if (fall(ix - mx, iy - my, n, m))
          break;
        else {
          if (s[i] == 'U') {
            if (fall(1, maxd + 1, n, m))
              break;
            else
              maxd += 1;
          } else if (s[i] == 'D') {
            if (fall(1, minu - 1, n, m))
              break;
            else
              minu -= 1;
          } else if (s[i] == 'L') {
            if (fall(maxr + 1, 1, n, m))
              break;
            else
              maxr += 1;
          } else {
            if (fall(minl - 1, 1, n, m))
              break;
            else
              minl -= 1;
          }
          ix -= mx, iy -= my;
        }
      } else {
        fx += mx, fy += my;
        minu = min(minu, fy), maxd = max(maxd, fy);
        minl = min(minl, fx), maxr = max(maxr, fx);
      }
    }
    cout << iy << " " << ix << "\n";
  }
}
