#include <bits/stdc++.h>
using ll = int64_t;
using namespace std;
struct modint {
  ll n;
  static const ll mod = 1000000007;
  modint() : n(0) {}
  modint(ll m) : n((m % mod + mod) % mod) {}
};
modint fastpow(modint, ll);
modint inverse(modint);
modint operator+(modint a, modint b) { return (a.n + b.n) % a.mod; }
modint operator-(modint a, modint b) { return (a.n - b.n + a.mod) % a.mod; }
modint operator*(modint a, modint b) { return (a.n * b.n) % a.mod; }
modint operator/(modint a, modint b) { return (a.n * inverse(b).n) % a.mod; }
modint operator+=(modint &a, modint b) { return a = a + b; }
modint operator-=(modint &a, modint b) { return a = a - b; }
modint operator*=(modint &a, modint b) { return a = a * b; }
modint operator/=(modint &a, modint b) { return a = a / b; }
bool operator==(modint a, modint b) { return a.n == b.n; }
bool operator!=(modint a, modint b) { return a.n != b.n; }
bool operator<(modint a, modint b) { return a.n < b.n; }
bool operator<=(modint a, modint b) { return a.n <= b.n; }
bool operator>(modint a, modint b) { return a.n > b.n; }
bool operator>=(modint a, modint b) { return a.n >= b.n; }
istream &operator>>(istream &i, modint a) { return i >> a.n; }
ostream &operator<<(ostream &o, modint a) { return o << a.n; }
modint stringpow(modint base, string exponent) {
  modint res = 1;
  for (int64_t i = exponent.size() - 1; i >= 0; --i) {
    for (int64_t j = 0; j < exponent[i] - '0'; ++j) {
      res *= base;
    }
    base = base * base * base * base * base * base * base * base * base * base;
  }
  return res;
}
modint fastpow(modint base, ll exponent) {
  modint res = 1;
  while (exponent) {
    if (exponent & 1) res *= base;
    base *= base;
    exponent >>= 1;
  }
  return res;
}
modint inverse(modint x) { return fastpow(x, x.mod - 2); };
void solve() {
  int64_t n, m, rb, cb, rd, cd, p;
  cin >> n >> m >> rb >> cb >> rd >> cd >> p;
  int64_t r = rb, c = cb, dr = 1, dc = 1, t = 0;
  vector<int64_t> ts;
  do {
    if (r == rd || c == cd) ts.push_back(t);
    if (r == 1 && dr == -1 || r == n && dr == 1) dr *= -1;
    if (c == 1 && dc == -1 || c == m && dc == 1) dc *= -1;
    r += dr;
    c += dc;
    t++;
    if (r == rb && c == cb)
      if (r == 1 || r == n || dr == 1)
        if (c == 1 || c == m || dc == 1) break;
  } while (1);
  modint ans = 0, a = 0, b = 0, pp = 100 - p, acc = 1;
  pp /= 100;
  for (int64_t i : ts) {
    a += i * acc;
    b += t * acc;
    acc *= pp;
  }
  cout << modint(p) / 100 * (acc / (1 - acc) / (1 - acc) * b + a / (1 - acc))
       << '\n';
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int64_t tc = 1;
  cin >> tc;
  while (tc--) solve();
}
