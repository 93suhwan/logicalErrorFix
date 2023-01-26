#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int main() {
  cin >> t;
  while (t--) {
    int n, m, x1, y1, x2, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    int cnt = 0;
    int x = 1, y = 1;
    while (1) {
      if (x1 == x2 || y1 == y2) {
        break;
      }
      cnt++;
      if (x1 == n && y1 == m) {
        x = -x;
        y = -y;
      } else if (x1 == n || y1 == m) {
        if (x1 == n) x = -x;
        if (y1 == m) y = -y;
      }
      x1 += x;
      y1 += y;
    }
    printf("%d\n", cnt);
  }
  return 0;
}
