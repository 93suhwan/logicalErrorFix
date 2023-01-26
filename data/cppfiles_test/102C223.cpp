#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, n, m;
  string str;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    cin >> str;
    int x = 0, y = 0;
    int maxx = 0, maxy = 0, minx = 0, miny = 0;
    int i = 0;
    while (i < str.length()) {
      switch (str[i]) {
        case 'U':
          minx = min(minx, --x);
          break;
        case 'D':
          maxx = max(maxx, ++x);
          break;
        case 'R':
          maxy = max(maxy, ++y);
          break;
        case 'L':
          miny = min(miny, --y);
      }
      if (maxx - minx >= n) {
        if (x == minx) minx++;
        break;
      }
      if (maxy - miny >= m) {
        if (y == miny) miny++;
        break;
      }
      i++;
    }
    cout << 1 - minx << ' ' << 1 - miny << '\n';
  }
  return 0;
}
