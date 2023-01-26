#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, m, sx, sy, ex, ey, i;
  cin >> t;
  for (i = 0; i < t; i++) {
    scanf("%d %d %d %d %d %d", &n, &m, &sx, &sy, &ex, &ey);
    cout << min((sx <= ex) ? ex - sx : n - sx + n - ex,
                (sy <= ey) ? ey - sy : m - sy + m - ey)
         << endl;
  }
  return 0;
}
