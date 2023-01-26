#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
vector<long long> v;
long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long res = power(a, b / 2);
  if (b % 2 == 0)
    return res * res % mod;
  else
    return res * res % mod * a % mod;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    long long n, m, a, b, c, d, p, q, da, db, inia, inib, inida, inidb, x, y,
        xy, cur, cycle, sz, num, cnt = 0, ans = 0;
    cin >> n >> m >> a >> b >> c >> d >> p;
    bool equal = 0;
    if (a == c || b == d) equal = 1;
    if (a < c)
      x = c - a;
    else if (a == n && c == n)
      x = n * 2 - 2;
    else
      x = n * 2 - a - c;
    if (b < d)
      y = d - b;
    else if (b == m && d == m)
      y = m * 2 - 2;
    else
      y = m * 2 - b - d;
    cur = xy = min(x, y);
    if ((a + xy - 1) % (2 * n - 2) >= n) {
      inia = a = 2 * n - 1 - (a + xy - 1) % (2 * n - 2);
      inida = da = -1;
    } else {
      inia = a = (a + xy - 1) % (2 * n - 2) + 1;
      inida = da = 1;
    }
    if ((b + xy - 1) % (2 * m - 2) >= m) {
      inib = b = 2 * m - 1 - (b + xy - 1) % (2 * m - 2);
      inidb = db = -1;
    } else {
      inib = b = (b + xy - 1) % (2 * m - 2) + 1;
      inidb = db = 1;
    }
    v.clear();
    do {
      v.push_back(cur % mod);
      bool flipa = 0, flipb = 0;
      if (da == -1) {
        flipa = 1;
        a = n - a + 1;
        c = n - c + 1;
      }
      if (db == -1) {
        flipb = 1;
        b = m - b + 1;
        d = m - d + 1;
      }
      if (a < c)
        x = c - a;
      else if (a == n && c == n)
        x = n * 2 - 2;
      else
        x = n * 2 - a - c;
      if (b < d)
        y = d - b;
      else if (b == m && d == m)
        y = m * 2 - 2;
      else
        y = m * 2 - b - d;
      xy = min(x, y);
      cur += xy;
      if ((a + xy - 1) % (2 * n - 2) >= n) {
        a = 2 * n - 1 - (a + xy - 1) % (2 * n - 2);
        da = -1;
      } else {
        a = (a + xy - 1) % (2 * n - 2) + 1;
        da = 1;
      }
      if ((b + xy - 1) % (2 * m - 2) >= m) {
        b = 2 * m - 1 - (b + xy - 1) % (2 * m - 2);
        db = -1;
      } else {
        b = (b + xy - 1) % (2 * m - 2) + 1;
        db = 1;
      }
      if (flipa) {
        a = n - a + 1;
        c = n - c + 1;
        da = -da;
      }
      if (flipb) {
        b = m - b + 1;
        d = m - d + 1;
        db = -db;
      }
      if (a == inia && b == inib) cnt++;
    } while (cnt < 4);
    if (equal) {
      cycle = v[v.size() - 1];
      v.insert(v.begin(), 0);
      v.pop_back();
    } else
      cycle = (cur - v[0] + mod) % mod;
    sz = v.size();
    q = 100 - p;
    p = p * power(100, mod - 2) % mod;
    q = q * power(100, mod - 2) % mod;
    num = power((1 - power(q, sz) + mod) % mod, mod - 2);
    for (long long j = 0; j < sz; j++) {
      long long tmp1 = v[j] * power(q, j) % mod * num % mod;
      long long tmp2 = cycle * power(q, sz + j) % mod * num % mod * num % mod;
      ans = (ans + tmp1 + tmp2) % mod;
    }
    cout << ans * p % mod << '\n';
  }
  return 0;
}
