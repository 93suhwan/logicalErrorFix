#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long fast(long long a, long long x) {
  if (x == 0) return 1;
  long long b = fast(a, x / 2);
  b *= b;
  b %= mod;
  if (x & 1) return (a * b) % mod;
  return b;
}
int main() {
  long long n, m, t, r, c;
  cin >> n >> m >> t >> r >> c;
  long long ax, ay, bx, by;
  cin >> ax >> ay >> bx >> by;
  long long dx = abs(ax - bx), dy = (ay - dy);
  long long fr;
  if (dx < r && dy < c) {
    long long ti = r * dy + c * dx - dx * dy;
    long long to = n * m - 2 * r * c + (r - dx) * (c - dy);
    fr = ti + to;
  } else {
    fr = n * m - r * c;
  }
  cout << fast(t, fr) << endl;
}
