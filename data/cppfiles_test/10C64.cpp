#include <bits/stdc++.h>
using namespace std;
long double PI = acos(-1);
long double DEL = 1e-12;
long long M = 1e9 + 7;
const long long N = 3e5 + 10;
long long cnt, sum, mx, mn, ans, a[N], b[N];
long long n, m, d, i, j, k, l, p, q, r, c, t, w, x, y, z, tc;
string s;
long long fpow(long long x, long long n) {
  long long res = 1;
  x %= M;
  while (n) {
    if (n & 1) res = res * x % M;
    x = x * x % M;
    n >>= 1;
  }
  return res;
}
long long noofways(long long n, long long m, long long r, long long c) {
  if (n >= 2 * r or m >= 2 * c) {
    return fpow(k, n * m - r * c);
  }
  long long ext = (n * m) - 2 * r * c + (2 * r - n) * (2 * c - m);
  return noofways(r, c, 2 * r - n, 2 * c - m) * fpow(k, ext) % M;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k >> r >> c;
  long long ax, ay, bx, by;
  cin >> ax >> ay >> bx >> by;
  if (ax == bx and ay == by) {
    cout << fpow(k, n * m);
    return 0;
  }
  if (ax > bx) {
    swap(ax, bx);
  }
  if (ay > by) {
    swap(ay, by);
  }
  long long ext = n * m - (by + c - ay) * (bx + r - ax);
  cout << fpow(k, ext) * noofways(bx + r - ax, by + c - ay, r, c) % M;
}
