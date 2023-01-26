#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y;
  point(int _x = 0, int _y = 0) {
    x = _x;
    y = _y;
  }
  point operator-(const point z) const { return point(x - z.x, y - z.y); }
} a[202];
struct val {
  int num;
  int remain;
  val(int _a = 0, int _b = 0) {
    num = _a;
    remain = _b;
  }
  val operator+(const val x) const {
    return val(num + x.num, remain + x.remain);
  }
  bool operator<(const val x) const {
    if (x.num == num) return remain < x.remain;
    return num < x.num;
  }
} f[202][202], tmp;
int n, m;
int cross(point a, point b) { return abs(1LL * a.x * b.y - 1LL * a.y * b.x); }
bool chk(int x) {
  int i, j, k, len;
  for (i = 1; i <= n; ++i) {
    for (j = i + 2; j <= n; ++j)
      f[i][j] = val(-(2147483640 >> 1), -(2147483640 >> 1));
  }
  for (len = 2; len < n; ++len) {
    for (i = 1; i + len <= n; ++i) {
      j = i + len;
      for (k = i + 1; k < j; ++k) {
        tmp = f[i][k] + f[k][j];
        tmp.remain += cross(a[k] - a[j], a[i] - a[j]);
        if (tmp.remain >= x) {
          ++tmp.num;
          tmp.remain = 0;
        }
        if (f[i][j] < tmp) f[i][j] = tmp;
      }
    }
  }
  return f[1][n].num >= m;
}
int main() {
  int i, j, l = 0, r = 2147483640, mid, ans = -1;
  scanf("%d%d", &n, &m);
  ++m;
  for (i = 1; i <= n; ++i) scanf("%d%d", &a[i].x, &a[i].y);
  while (l <= r) {
    mid = (l + r) >> 1;
    if (chk(mid)) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  printf("%d\n", ans);
  return 0;
}
