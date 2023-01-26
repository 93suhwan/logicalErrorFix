#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  vector<vector<int>> a(n, vector<int>(m, 1));
  long long ans = 0;
  for (int x = 0; x < int(n); x++)
    for (int y = 0; y < int(m); y++) {
      if (x == 0) {
        for (int k = 1;; ++k) {
          int nx = x + k / 2;
          int ny = y + (k + 1) / 2;
          if (nx == n || ny == m) break;
          ans += k;
        }
      }
      if (y == 0) {
        for (int k = 1;; ++k) {
          int nx = x + (k + 1) / 2;
          int ny = y + k / 2;
          if (nx == n || ny == m) break;
          ans += k;
        }
      }
    }
  ans += n * m;
  for (int i = 0; i < int(q); i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x, --y;
    for (int c = 0; c < int(2); c++) {
      int l = 1, r = 1;
      while (true) {
        int nx = x + (l + c) / 2;
        int ny = y + (l + !c) / 2;
        if (nx == n || ny == m || a[nx][ny] == 0) break;
        ++l;
      }
      while (true) {
        int nx = x - (r + !c) / 2;
        int ny = y - (r + c) / 2;
        if (nx < 0 || ny < 0 || a[nx][ny] == 0) break;
        ++r;
      }
      if (a[x][y] == 0) {
        ans += l * r;
      } else {
        ans -= l * r;
      }
    }
    ans += a[x][y];
    a[x][y] ^= 1;
    ans -= a[x][y];
    printf("%lld\n", ans);
  }
}
