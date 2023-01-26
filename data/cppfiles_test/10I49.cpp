#include <bits/stdc++.h>
using namespace std;
struct rect {
  long long ax, ay, bx, by;
};
long long c;
const long long MOD = 1e9 + 7;
long long binpow(long long a, long long n) {
  if (n == 0) return 1;
  if (n % 2 == 0) {
    long long g = binpow(a, n / 2);
    return (g * g % MOD);
  } else {
    return (binpow(a, n - 1) * a % MOD);
  }
}
rect merge(rect a, rect b) {
  long long r = min(a.bx, b.bx), l = max(a.ax, b.ax);
  if (l > r) return {-1, -1, -1, -1};
  long long rr = min(a.by, b.by), ll = max(a.ay, b.ay);
  if (ll > rr) return {-1, -1, -1, -1};
  return {l, ll, r, rr};
}
long long func(rect a, rect b) {
  rect c = merge(a, b);
  long long val = (a.bx - a.ax + 1) * (a.by - a.ay + 1);
  if (c.ax == -1) {
    return val;
  }
  rect d = c;
  long long r = c.ax - a.ax, q = c.ay - a.ay;
  d.ax -= r, d.bx -= r, d.ay -= q, d.by -= q;
  long long mem = func(c, d);
  return val - 2 * (c.bx - c.ax + 1) * (c.by - c.ay + 1) + mem;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, m, k, r, ans = 0;
  long long ax, ay, bx, by;
  cin >> n >> m >> k >> r >> c >> ax >> ay >> bx >> by;
  rect a{ax, ay, ax + r - 1, ay + c - 1}, b{bx, by, bx + r - 1, by + c - 1};
  ans = n * m - (r * c) * 2;
  rect c = merge(a, b);
  if (c.ax != -1) {
    ans += (c.bx - c.ax + 1) * (c.by - c.ay + 1);
  }
  if (ax != bx || ay != by) {
    ans += func(a, b);
  }
  cout << binpow(k, ans) << endl;
  return 0;
}
