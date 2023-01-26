#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using LL = long long;
using comp = complex<double>;
const double PI = 3.14159265358979323846264338327950L;
int mod = 1e9 + 7;
const ll INFLL = 1LL << 62;
const int INF = 1 << 30;
comp inC() {
  double x, y;
  cin >> x >> y;
  return {x, y};
}
struct Data {
  ll cost, val;
  Data(ll cost = 0, ll val = 0) : cost(cost), val(val) {}
  bool operator<(const Data& a) const { return cost > a.cost; }
};
void tle() {
  for (int i = 0; (i) < (2002002002002); (i)++) continue;
}
struct mint {
  ll x;
  mint(ll x = 0) : x((x % mod + mod) % mod) {}
  mint operator-() const { return mint(-x); }
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const { return mint(*this) += a; }
  mint operator-(const mint a) const { return mint(*this) -= a; }
  mint operator*(const mint a) const { return mint(*this) *= a; }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }
  mint inv() const { return pow(mod - 2); }
  mint& operator/=(const mint a) { return *this *= a.inv(); }
  mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream& operator>>(istream& is, mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }
struct combination {
  vector<mint> fact, ifact;
  combination(int n) : fact(n + 1), ifact(n + 1) {
    assert(n < mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * ifact[k] * ifact[n - k];
  }
} comb(202);
void solve() {
  int n, k;
  cin >> n >> k;
  mint ans = 0;
  mint p = 1;
  while (k) {
    int f = k % 2;
    ans += p * (f);
    p *= n;
    k /= 2;
  }
  cout << ans << endl;
}
int main() {
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
