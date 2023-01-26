#include <bits/stdc++.h>
using namespace std;
const long long modn = 1e9 + 7;
using i64 = long long;
i64 fastpow(i64 b, i64 p) {
  i64 r = 1LL;
  for (; p > 0; p >>= 1) {
    if (p & 1) r = ((r * b) % modn);
    b = ((b * b) % modn);
  }
  return r;
}
long long gcd(long long a, long long b) {
  while (b != 0) {
    long long tmp = a % b;
    a = b;
    b = tmp;
  }
  return a;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  i64 n, m, k, r, c, x1, y1, x2, y2;
  cin >> n >> m >> k >> r >> c >> x1 >> y1 >> x2 >> y2;
  i64 xx = abs(x1 - x2), yy = abs(y1 - y2);
  i64 X = 2 * xx - r, Y = 2 * yy - c;
  if (x1 == x2 && y1 == y2) {
    cout << fastpow(k, n * m);
  } else if (xx >= r && yy >= c) {
    cout << fastpow(k, n * m - r * c);
  } else if (X <= 0 || Y <= 0) {
    cout << fastpow(k, n * m - (2 * r * c - xx * yy) + r * c - xx * yy);
  } else {
    long long s = n * m - ((2 * r * c) % modn) + ((xx * yy) % modn);
    s = ((((s) % modn) + modn) % modn);
    s = ((s + ((r * c - 2 * xx * yy + X * Y) % modn)) % modn);
    s = ((s + ((xx * yy - X * Y) % modn)) % modn);
    cout << fastpow(k, s);
  }
  return 0;
}
