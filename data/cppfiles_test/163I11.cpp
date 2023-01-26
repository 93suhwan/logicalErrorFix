#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1e9 + 7, N = 200200;
long long poww(long long a, long long b, long long Mod) {
  long long res = 1;
  if (b < 0) b = (b % (Mod - 1) + Mod - 1) % (Mod - 1);
  for (; b; b >>= 1, a = 1ll * a * a % Mod)
    if (b & 1) res = 1ll * res * a % Mod;
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, m, x1, x2, y1, y2, p;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2 >> p;
    long long r = 0, nn = 0, xt = 0, t = 0, x = x1, y = y1, dx = 1, dy = 1;
    long long q = 100 - p;
    q = q * poww(100, -1, Mod);
    q %= Mod;
    p = p * poww(100, -1, Mod);
    p %= Mod;
    if (x == 1) dx = 1;
    if (x == n) dx = -1;
    if (y == 1) dy = 1;
    if (y == n) dy = -1;
    int fx = dx, fy = dy;
    if (x == x2 || y == y2) nn++;
    x += dx, y += dy;
    long long qqq = 1;
    while (xt == 0) {
      if (t == 0) {
        t++;
        continue;
      }
      if (x == 1) dx = 1;
      if (x == n) dx = -1;
      if (y == 1) dy = 1;
      if (y == m) dy = -1;
      if (x == x1 && y == y1 && dx == fx && dy == fy) {
        xt = t;
        break;
      }
      if (x == x2 || y == y2) {
        r += (((t * p) % Mod * qqq) % Mod);
        qqq *= q;
        qqq %= Mod;
        r %= Mod;
        nn++;
      }
      x += dx;
      y += dy;
      t++;
    }
    long long ans = xt * poww(q, nn, Mod);
    ans %= Mod;
    long long qq = poww(q, nn, Mod);
    qq = (1 - qq + Mod) % Mod;
    ans = (ans + r) % Mod;
    ans = (ans * poww(qq, -1, Mod)) % Mod;
    cout << ans % Mod << endl;
  }
  return 0;
}
