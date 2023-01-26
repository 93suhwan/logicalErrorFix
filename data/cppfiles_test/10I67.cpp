#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops", \
                     "omit-frame-pointer", "inline")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native", "no-zero-upper")
using namespace std;
const long long mod = (1e9 + 7);
const double eps = (1e-9);
const long long oo = (long long)(1e18 + 5);
long long k;
long long qp(long long b, long long e) {
  long long ans = 1;
  while (e) {
    if (e & 1) ans = (ans * b) % mod;
    e >>= 1;
    b = (b * b) % mod;
  }
  return ans;
}
long long solve(long long dx, long long dy, long long r, long long c) {
  if (dx == 0 && dy == 0) return qp(k, r * c);
  if (dx >= r || dy >= c) return qp(k, r * c);
  long long nr = r - dx;
  long long nc = c - dy;
  long long mul;
  if (nr >= 0 && nc >= 0)
    mul = qp(k, 2 * dx * dy);
  else
    mul = qp(k, r * c - 2 * nr * nc);
  return (mul * solve(dx, dy, nr, nc)) % mod;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m, r, c;
  cin >> n >> m >> k >> r >> c;
  long long ax, ay, bx, by;
  cin >> ax >> ay >> bx >> by;
  if (ax > bx) {
    ax = n - (ax + r - 1);
    bx = n - (bx + r - 1);
  }
  if (ay > by) {
    ay = m - (ay + c - 1);
    by = m - (by + c - 1);
  }
  long long cx = ax + r - bx;
  long long cy = ay + c - by;
  cx = max(cx, 0ll);
  cy = max(cy, 0ll);
  long long ans = qp(k, n * m - 2 * r * c + cx * cy);
  ans = (ans * solve(bx - ax, by - ay, r, c)) % mod;
  cout << (ans) << '\n';
  return 0;
}
