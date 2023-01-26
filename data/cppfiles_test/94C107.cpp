#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void ckmax(T& x, T y) {
  x = (y > x ? y : x);
}
template <typename T>
inline void ckmin(T& x, T y) {
  x = (y < x ? y : x);
}
int knxor(int x, int y, int k) {
  int z = 0;
  int p = 1;
  while (x > 0 || y > 0) {
    int a = x % k;
    x = x / k;
    int b = y % k;
    y = y / k;
    int c = (a - b + k) % k;
    z = z + p * c;
    p = p * k;
  }
  return z;
}
const double eps = 1e-8;
int sgn(double a) { return a < -eps ? -1 : a < eps ? 0 : 1; }
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int o = 0, e = 0, t = n, val = 1;
    while (t) {
      o = t % 10 * val + o;
      val *= 10;
      t /= 100;
    }
    t = n / 10, val = 1;
    while (t) {
      e = t % 10 * val + e;
      val *= 10;
      t /= 100;
    }
    long long ans = (o + 1) * (e + 1) - 2;
    cout << ans << '\n';
  }
  return 0;
}
