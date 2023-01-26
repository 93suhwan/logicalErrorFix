#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int resx = 1, resy = 1, maxx = 0, maxy = 0, minx = 0, miny = 0, row = 0,
        col = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'U')
        row--;
      else if (s[i] == 'R')
        col++;
      else if (s[i] == 'L')
        col--;
      else
        row++;
      maxx = max(maxx, row);
      minx = min(minx, row);
      maxy = max(maxy, col);
      miny = min(miny, col);
      if (maxx - minx >= n || maxy - miny >= m) break;
      resx = 1 - minx;
      resy = 1 - miny;
    }
    cout << resx << ' ' << resy << endl;
  }
  return 0;
}
