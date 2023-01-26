#include <bits/stdc++.h>
using namespace std;
const int sz = 1e5 + 5, mod = 1e9 + 7;
long long bigmod(long long b, long long n) {
  b %= mod;
  if (n == -1) n = mod - 2;
  long long ans = 1;
  while (n) {
    if (n & 1) ans = ans * b % mod;
    n >>= 1;
    b = b * b % mod;
  }
  return ans;
}
int main() {
  long long n, m, k, r, c;
  cin >> n >> m >> k >> r >> c;
  long long ax, ay, bx, by;
  cin >> ax >> ay >> bx >> by;
  if (ax > bx) swap(ax, bx), swap(ay, by);
  long long cx = min(ax, bx) + r - max(ax, bx);
  long long cy = min(ay, by) + c - max(ay, by);
  cx = max(cx, 0LL);
  cy = max(cy, 0LL);
  long long cov = 2 * r * c - cx * cy;
  long long ans = bigmod(k, n * m - cov);
  long long dx = abs(ax - bx), dy = abs(ay - by);
  dx = min(dx, r), dy = min(dy, c);
  long long cut = dx * c + dy * r - dx * dy;
  ans = ans * bigmod(k, cut) % mod;
  if (ans < 0) ans += mod;
  cout << ans;
}
