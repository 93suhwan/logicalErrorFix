#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long xx, yy, x, y, rr, cc, n, m, k, c, r, xa, ya, xb, yb, p, ans;
long long posw(long long x) {
  long long tt = 1, t = k;
  while (x) {
    if (x & 1) tt = tt * t % MOD;
    x >>= 1;
    t = t * t % MOD;
  }
  return tt;
}
long long sz(long long a, long long b) {
  if (b == 0) return 999999999;
  if (a % b == 0)
    return a / b;
  else
    return a / b + 1;
}
int main() {
  scanf("%I64d%I64d%I64d%I64d%I64d", &n, &m, &k, &r, &c);
  scanf("%I64d%I64d%I64d%I64d", &xa, &ya, &xb, &yb);
  if (xa >= xb && ya >= yb) {
    swap(xa, xb);
    swap(ya, yb);
  }
  if (xa == xb && ya == yb) {
    cout << posw(n * m) << endl;
    return 0;
  }
  if (xb > xa + r - 1 || yb > ya + c - 1) {
    ans = posw(n * m - r * c);
  } else {
    xx = abs(xa - xb);
    yy = abs(ya - yb);
    x = sz(r, xx) - 1;
    y = sz(c, yy) - 1;
    p = min(x, y);
    rr = r - p * xx;
    cc = c - p * yy;
    ans = 2 * (p - 1) * xx * yy - rr * cc +
          (r - (p - 1) * xx) * (c - (p - 1) * yy);
    ans += m * n - (r + xx) * (c + yy) + 2 * xx * yy;
    ans = posw(ans);
  }
  cout << ans << endl;
  return 0;
}
