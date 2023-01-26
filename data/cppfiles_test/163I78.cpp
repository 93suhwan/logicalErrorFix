#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long ksm(long long x, long long y) {
  long long res = 1;
  do {
    if (y & 1) res = 1ll * x * res % mod;
    x = 1ll * x * x % mod;
  } while (y >>= 1);
  return res;
}
void sol() {
  long long n, m, x_1, y_1, x_2, y_2, p;
  cin >> n >> m >> x_1 >> y_1 >> x_2 >> y_2 >> p;
  long long kp = 1ll * p * ksm(100, mod - 2) % mod;
  long long np = 1;
  long long dx = 1, dy = 1;
  long long nx = dx + x_1, ny = dy + y_1;
  long long rx = nx - dx, ry = ny - dy;
  if (nx > n || nx < 1) dx = -dx;
  if (ny > m || ny < 1) dy = -dy;
  long long rdx = dx, rdy = dy;
  long long len = 0;
  long long ans = 0;
  do {
    if (x_1 == x_2 || y_1 == y_2) {
      ans += 1ll * np * kp % mod * len % mod;
      np = 1ll * np * (1 - kp + mod) % mod;
    }
    len++;
    x_1 += dx;
    y_1 += dy;
    long long nx = dx + x_1, ny = dy + y_1;
    if (nx > n || nx < 1) dx = -dx;
    if (ny > m || ny < 1) dy = -dy;
  } while (x_1 != rx || y_1 != ry || dx != rdx || dy != rdy);
  ans = (ans + 1ll * len * np % mod) * ksm((1 - np + mod) % mod, mod - 2) % mod;
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long v_v = 1;
  cin >> v_v;
  while (v_v--) sol();
  return 0;
}
