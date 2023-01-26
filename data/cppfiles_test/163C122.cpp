#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long power(long long a, long long b) {
  if (b == 0)
    return 1;
  else {
    long long x = power(a, b / 2);
    long long y = (x * x) % MOD;
    if (b % 2) y = (y * a) % MOD;
    return y;
  }
}
long long inverse(long long a) { return power(a, MOD - 2); }
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long inv = inverse(100);
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    long long n, m, a, b, c, d, p;
    cin >> n >> m >> a >> b >> c >> d >> p;
    p = (p * inv) % MOD;
    long long q = (1 + MOD - p) % MOD;
    long long z = 0;
    long long prob = p;
    long long x1, y1, x2, y2;
    if (a <= c) {
      x1 = c - a;
      x2 = n - a + n - c;
    } else {
      x1 = n - a + n - c;
      x2 = 2 * n - 2 + c - a;
    }
    if (b <= d) {
      y1 = d - b;
      y2 = m - b + m - d;
    } else {
      y1 = m - b + m - d;
      y2 = 2 * m - 2 + d - b;
    }
    x1 %= 2 * (n - 1);
    x2 %= 2 * (n - 1);
    y1 %= 2 * (m - 1);
    y2 %= 2 * (m - 1);
    set<pair<long long, long long> > t;
    t.insert({x1, n - 1});
    t.insert({x2, n - 1});
    t.insert({y1, m - 1});
    t.insert({y2, m - 1});
    long long s = 0;
    long long primary = t.begin()->first;
    while (true) {
      long long timer = t.begin()->first;
      if (t.find({timer, n - 1}) != t.end()) {
        t.erase({timer, n - 1});
        t.insert({timer + 2 * (n - 1), n - 1});
      }
      if (t.find({timer, m - 1}) != t.end()) {
        t.erase({timer, m - 1});
        t.insert({timer + 2 * (m - 1), m - 1});
      }
      z = (z + (timer * prob) % MOD) % MOD;
      prob = (prob * q) % MOD;
      s++;
      if ((t.begin()->first - primary) % (2 * (n - 1)) == 0 &&
          (t.begin()->first - primary) % (2 * (m - 1)) == 0)
        break;
    }
    long long secondary = t.begin()->first;
    long long ans1 = (z * inverse(1 + MOD - power(q, s))) % MOD;
    long long w = secondary - primary;
    long long v = 0;
    for (long long i = 0; i < s; i++) {
      v = (v + (w * prob) % MOD) % MOD;
      prob = (prob * q) % MOD;
    }
    long long ans2 = (v * power(inverse(1 + MOD - power(q, s)), 2)) % MOD;
    long long ans = (ans1 + ans2) % MOD;
    cout << ans << '\n';
  }
  return 0;
}
