#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, m, sx, sy, ex, ey, i;
  cin >> t;
  for (i = 0; i < t; i++) {
    scanf("%d %d %d %d %d %d", &n, &m, &sx, &sy, &ex, &ey);
    if (sx == ex || sy == ey) {
      cout << 0 << endl;
    } else {
      cout << min((sx < ex) ? ex - sx : (n - sx << 1) + sx - ex,
                  (sy < ey) ? ey - sy : (m - sy << 1) + sy - ey)
           << endl;
    }
  }
  return 0;
}
