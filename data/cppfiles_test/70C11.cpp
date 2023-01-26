#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uint = unsigned int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
using ld = long double;
template <typename T>
void _(const char* s, T h) {
  cerr << s << " = " << h << "\n";
}
template <typename T, typename... Ts>
void _(const char* s, T h, Ts... t) {
  int b = 0;
  while (((b += *s == '(') -= *s == ')') != 0 || *s != ',') cerr << *s++;
  cerr << " = " << h << ",";
  _(s + 1, t...);
}
struct init {
  init() {
    cin.tie(0);
    iostream::sync_with_stdio(0);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(5);
  }
  ~init() {}
} init;
template <typename T, typename U>
void upx(T& x, U y) {
  if (x < y) x = y;
}
template <typename T, typename U>
void upn(T& x, U y) {
  if (x > y) x = y;
}
mt19937 rng(300);
const int32_t M = 1e9 + 7;
int32_t rev(int32_t x, int32_t m) {
  if (x == 1) return 1;
  return (1 - (ll)rev(m % x, x) * m) / x + m;
}
struct modint {
  int32_t x;
  modint() : x(0) {}
  modint(int32_t xx) : x(xx % M) {
    if (x < 0) x += M;
  }
  modint(ll xx) : x(xx % M) {
    if (x < 0) x += M;
  }
  modint& operator+=(modint b) {
    if ((x += b.x) >= M) x -= M;
    return *this;
  }
  modint operator+(modint b) {
    modint res = *this;
    res += b;
    return res;
  }
  modint& operator-=(modint b) {
    if ((x -= b.x) < 0) x += M;
    return *this;
  }
  modint operator-(modint b) {
    modint res = *this;
    res -= b;
    return res;
  }
  modint& operator*=(modint b) {
    x = (ll)x * b.x % M;
    return *this;
  }
  modint operator*(modint b) {
    modint res = *this;
    res *= b;
    return res;
  }
  modint inverse() { return rev(x, M); }
  modint& operator/=(modint b) {
    x = (ll)x * rev(b.x, M) % M;
    return *this;
  }
  modint operator/(modint b) {
    modint res = *this;
    res /= b;
    return res;
  }
  modint operator^(ll w) {
    modint r = 1, a = *this;
    while (w) {
      if (w & 1) r *= a;
      a *= a;
      w /= 2;
    }
    return r;
  }
  modint operator^=(ll w) { return *this = (*this) ^ w; }
  modint operator^(modint w) { return *this ^ w.x; }
  modint operator^=(modint w) { return *this = (*this) ^ w; }
  modint operator-() const { return modint() - *this; }
  explicit operator bool() const { return x; }
  bool operator==(const modint& b) const { return x == b.x; }
};
istream& operator>>(istream& is, modint& p) {
  istream& res = is >> p.x;
  p.x %= M;
  return res;
}
ostream& operator<<(ostream& os, modint p) { return os << p.x; }
template <typename T>
modint operator+(T x, modint y) {
  return modint(x) + y;
}
template <typename T>
modint operator-(T x, modint y) {
  return modint(x) - y;
}
template <typename T>
modint operator*(T x, modint y) {
  return modint(x) * y;
}
template <typename T>
modint operator/(T x, modint y) {
  return modint(x) / y;
}
template <typename T>
modint operator^(T x, modint y) {
  return modint(x) ^ y;
}
modint abs(modint x) { return x; }
using mint = modint;
const ll N = 201010;
mint a[N], p[N], first[N];
int32_t main() {
  ll n, q;
  cin >> n >> q;
  for (ll i = 1; i <= n; ++i) {
    cin >> a[i];
    p[i] = a[i] + p[i - 1];
    first[i] = a[i] * a[i] + first[i - 1];
  }
  while (q--) {
    ll l, r, d;
    cin >> l >> r >> d;
    mint c = r - l + 1;
    mint m = (p[r] - p[l - 1] - d * c * (c - 1) / 2) / c;
    mint need =
        m * m * c + m * d * c * (c - 1) + d * d * c * (c - 1) * (c + c - 1) / 6;
    if (need == first[r] - first[l - 1])
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
