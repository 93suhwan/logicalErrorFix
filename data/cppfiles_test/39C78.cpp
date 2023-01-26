#include <bits/stdc++.h>
using namespace std;
long long t = 1, n, m, k, q, l, r, a, b, c, d, u, v, x, y, xx, yy, z,
          mod = 1e9 + 7;
string s;
struct st {
  long long x, y;
};
bool cmp(const st &a, const st &b) { return a.x < b.x; }
inline long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0')
    s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
  return s * w;
}
long long qp(long long x, long long y) {
  long long a = 1, b = x;
  while (y) {
    if (y & 1) a = a * b % mod;
    b = b * b % mod, y >>= 1;
  }
  return a;
}
int main() {
  t = read();
  while (t--) {
    a = read(), b = read(), x = read(), y = read(), xx = read(), yy = read(),
    c = read(), d = read();
    if (xx - x + c > a && yy - y + d > b) {
      puts("-1");
      continue;
    }
    long long ans = 1e18;
    if (xx - x + c <= a)
      ans = min(ans, min(max(0ll, c - x), max(0ll, c - (a - xx))));
    if (yy - y + d <= b)
      ans = min(ans, min(max(0ll, d - y), max(0ll, d - (b - yy))));
    cout << fixed << setprecision(10) << (double)ans << endl;
  }
  return 0;
}
