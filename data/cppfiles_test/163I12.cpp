#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MAX = 300010;
const long long MOD = (int)1e9 + 7;
const int INF = 1e9;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-8;
long long fexp(long long b, long long e) {
  if (e == 0) return 1ll;
  long long res = fexp(b, e / 2);
  res = (res * res) % MOD;
  if (e % 2) res = (res * b) % MOD;
  return res;
}
long long inv(long long a) { return fexp(a, MOD - 2); }
long long solve(long long p, long long d, long long ciclo, long long k) {
  long long op = (1 - p + MOD) % MOD;
  long long val1 = (p * d) % MOD;
  long long dval1 = (1 - fexp(op, k) + MOD) % MOD;
  dval1 = inv(dval1);
  val1 = (val1 * dval1) % MOD;
  long long val2 = (p * ciclo) % MOD;
  val2 = (val2 * fexp(op, k)) % MOD;
  long long dval2 = (fexp(op, k) - 1 + MOD) % MOD;
  dval2 = (dval2 * dval2) % MOD;
  dval2 = inv(dval2);
  val2 = (val2 * dval2) % MOD;
  long long val3 = 0;
  long long res = (val1 + val2 - val3) % MOD;
  return res;
}
int32_t main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, m, x, y, x2, y2, p;
    cin >> n >> m >> x >> y >> x2 >> y2 >> p;
    long long sx = x, sy = y;
    p = (p * inv(100)) % MOD;
    vector<int> ds;
    long long d = 0;
    long long ciclo = 0;
    long long dx = 1, dy = 1;
    if (x == n and dx == 1) dx *= -1;
    if (x == 1 and dx == -1) dx *= -1;
    if (y == m and dy == 1) dy *= -1;
    if (y == 1 and dy == -1) dy *= -1;
    long long dxi = dx, dyi = dy;
    while (d < 100005) {
      if (d != 0 and x == sx and y == sy and dx == dxi and dy == dyi) break;
      if (x == x2 or y == y2) ds.push_back(d);
      x += dx;
      y += dy;
      if (x == n and dx == 1) dx *= -1;
      if (x == 1 and dx == -1) dx *= -1;
      if (y == m and dy == 1) dy *= -1;
      if (y == 1 and dy == -1) dy *= -1;
      d++;
      ciclo++;
    }
    sort(ds.begin(), ds.end());
    ds.erase(unique(ds.begin(), ds.end()), ds.end());
    long long k = ds.size(), res = 0;
    if (k == 0) {
      cout << 0 << '\n';
      continue;
    }
    for (int i = 0; i < (int)ds.size(); i++) {
      long long val = solve(p, ds[i], ciclo, k);
      long long op = (1 - p + MOD) % MOD;
      val = (val * fexp(op, i)) % MOD;
      res = (res + val);
    }
    res %= MOD;
    res = (res + MOD) % MOD;
    cout << res << '\n';
  }
  return 0;
}
