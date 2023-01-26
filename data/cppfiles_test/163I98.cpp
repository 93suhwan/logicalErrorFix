#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long qmi(long long x, long long p = mod - 2) {
  long long res = 1;
  while (p) {
    if (p & 1) res = res * x % mod;
    p >>= 1;
    x = x * x % mod;
  }
  return res;
}
void solve() {
  long long n, m, x1, x2, y1, y2, p;
  cin >> n >> m >> x1 >> y1 >> x2 >> y2 >> p;
  p = (100ll - p) * qmi(100) % mod;
  long long dx = -1, dy = -1;
  long long u = 0, v = 1;
  cout << p << endl;
  for (int i = 4 * (n - 1) * (m - 1); i >= 1; i--) {
    if (x1 + dx < 1 || x1 + dx > n) dx = -dx;
    if (y1 + dy < 1 || y1 + dy > m) dy = -dy;
    x1 += dx;
    y1 += dy;
    u = (u + 1) % mod;
    if (x1 == x2 || y1 == y2) {
      u = u * p % mod;
      v = v * p % mod;
    }
  }
  cout << ((u * qmi(1 - v) % mod) + mod) % mod << endl;
}
int main() {
  int test;
  cin >> test;
  while (test--) solve();
  return 0;
}
