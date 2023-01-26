#include <bits/stdc++.h>
using i64 = long long;
const int MOD = 1000000007;
i64 pow64(i64 a, i64 b) {
  i64 result = 1;
  while (b) {
    if (b & 1) result = result * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return result;
}
int n, m, k, r, c;
int ax, ay, bx, by;
int f(int a, int b, int c, int d) {
  if (a >= c * 2 || b >= d * 2) return (i64(a) * b - i64(c) * d) % (MOD - 1);
  if (a == c) {
    if (b == d)
      return i64(a) * b % (MOD - 1);
    else {
      int dy = b - d;
      int cc = (d + dy - 1) / dy - 1;
      return f(a, b - cc * dy, c, d - cc * dy);
    }
  } else {
    if (b == d)
      return f(b, a, d, c);
    else {
      int dx = a - c, dy = b - d;
      int cc = std::min((c + dx - 1) / dx, (d + dy - 1) / dy) - 1;
      return (f(a - cc * dx, b - cc * dy, c - cc * dx, d - cc * dy) +
              2 * cc * i64(dx) * dy) %
             (MOD - 1);
    }
  }
}
int main() {
  std::scanf("%d%d%d%d%d", &n, &m, &k, &r, &c);
  std::scanf("%d%d%d%d", &ax, &ay, &bx, &by);
  int xl = std::min(ax, bx), xr = std::max(ax, bx) + r;
  int yl = std::min(ay, by), yr = std::max(ay, by) + c;
  int dx = xr - xl, dy = yr - yl;
  int result = (i64(n) * m - i64(dx) * dy + f(dx, dy, r, c)) % (MOD - 1);
  result = pow64(k, result);
  std::printf("%d\n", result);
}
