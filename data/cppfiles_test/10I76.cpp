#include <bits/stdc++.h>
using namespace std;
const long long p = 1e9 + 7;
long long ksm(long long x, long long y) {
  long long r = 1;
  while (y) {
    if (y & 1) r = r * x % p;
    x = x * x % p;
    y >>= 1;
  }
  return r;
}
long long n, m, k, ans, r, c, x[2], y[2];
int main() {
  cin >> n >> m >> k >> r >> c >> x[0] >> y[0] >> x[1] >> y[1];
  if (x[0] < x[1] || x[0] == x[1] && y[0] < y[1])
    swap(x[0], x[1]), swap(y[0], y[1]);
  if (y[0] > y[1]) y[0] = m - y[0] + 1, y[1] = m - y[1] + 1;
  if (x[0] == y[0] && x[1] == y[1]) {
    ans = ksm(k, n * m);
    cout << ans;
    return 0;
  }
  if (x[0] + r <= y[0] && x[1] + c <= y[1]) {
    ans = ksm(k, n * m - r * c);
    cout << ans;
    return 0;
  }
  x[1] -= x[0];
  y[1] -= y[0];
  ans = ksm(k, n * m - r * c - r * c + (r - x[1]) * (c - y[1]) + x[1] * c +
                   y[1] * r - x[1] * y[1]);
  cout << ans;
}
