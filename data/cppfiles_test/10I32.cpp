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
i64 f(i64 a, i64 b, i64 c, i64 d) {
  if (a >= c * 2 || b >= d * 2) return (i64(a) * b - i64(c) * d) % MOD;
  if (a == c) {
    if (b == d)
      return i64(a) * b % MOD;
    else {
      i64 dy = b - d;
      i64 cc = (d + dy - 1) / dy - 1;
      return f(a, b - cc * dy, c, d - cc * dy);
    }
  } else {
    if (b == d)
      return f(b, a, d, c);
    else {
      i64 dx = a - c, dy = b - d;
      i64 cc = std::min((c + dx - 1) / dx, (d + dy - 1) / dy) - 1;
      return (f(a - cc * dx, b - cc * dy, c - cc * dx, d - cc * dy) +
              2 * cc * i64(dx) % MOD * dy) %
             MOD;
    }
  }
}
int main() {
  std::scanf("%d%d%d%d%d", &n, &m, &k, &r, &c);
  std::scanf("%d%d%d%d", &ax, &ay, &bx, &by);
  i64 xl = std::min(ax, bx), xr = std::max(ax, bx) + r;
  i64 yl = std::min(ay, by), yr = std::max(ay, by) + c;
  i64 dx = xr - xl, dy = yr - yl;
  i64 result = (i64(n) * m - i64(dx) * dy + f(dx, dy, r, c)) % MOD;
  result = pow64(k, result);
  std::printf("%lld\n", result);
}
